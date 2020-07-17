open Emotion;

// ISO 3166-1 alpha-2
// ⚠️ No support for IE 11
let countryToFlag = isoCode => {
  isoCode
  |> Js.String.toUpperCase
  |> Js.String.unsafeReplaceBy0([%re "/./g"], (char, _, _) =>
       char
       |> Js.String.charCodeAt(0)
       |> int_of_float
       |> (charIso => charIso + 127397)
       |> Js.String.fromCodePoint
     );
};

let loadCountries =
  Throttle.make(
    ~delay=250,
    ((inputValue, cb)) => {
      open! PromiseMonad;
      open! Models;

      Fetch.fetch("/api/countries?q=" ++ inputValue)
      >>- Fetch.Response.json
      >>= Models.Decode.countries
      >>= (
        response =>
          response.countries
          |> Js.Array.map(country =>
               {
                 ...country,
                 label: countryToFlag(country.value) ++ "   " ++ country.label,
               }
             )
          |> cb
      )
      >>/= (
        e => {
          Js.log2("Cannot parse response:", e);
        }
      );
    },
  );

[@react.component]
let make = () => {
  let (value, setValue) = React.useState(() => None);
  let (isOpen, setIsOpen) = React.useState(() => false);

  <Popper
    isOpen
    onClose={_ => setIsOpen(_ => false)}
    target={
      <button
        onClick={_ => setIsOpen(_ => true)}
        className={css([
          padding2(8->`px, 12->`px),
          color("333333"->`hex),
          backgroundColor("ffffff"->`hex),
          lineHeight(18->`px),
          borderRadius(4->`px),
          borderWidth(1->`px),
          borderStyle(`solid),
          borderColor(`rgba((0, 0, 0, 0.2))),
        ])}>
        {React.string(
           switch (value) {
           | Some(country) => country.label
           | None => "Select country"
           },
         )}
        <ArrowIcon className={css([marginLeft(4->`px)])} />
      </button>
    }>
    <div
      className={css([
        backgroundColor(Emotion.Css.Color.white),
        borderRadius(`px(4)),
        marginTop(`px(8)),
        position(`absolute),
        zIndex(2),
        width(`px(340)),
      ])}>
      <ReactSelect.Async
        value
        styles=ReactSelectOverrides.styles
        components={
          "IndicatorsContainer": () => React.null,
          "ValueContainer": props =>
            <div
              className={css([
                display(`flex),
                alignItems(`center),
                flexBasis(100.->`pct),
                marginLeft(8->`px),
              ])}>
              <SearchIcon />
              {React.createElement(
                 ReactSelect.components |> ReactSelect.valueContainerGet,
                 props,
               )}
            </div>,
        }
        autoFocus=true
        cacheOptions=true
        defaultOptions=true
        onChange={newValue => setValue(_ => Js.Nullable.toOption(newValue))}
        loadOptions={(inputValue, cb) =>
          (inputValue, cb) |> loadCountries |> ignore
        }
      />
    </div>
  </Popper>;
};

let default = make;
