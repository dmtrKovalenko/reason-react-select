open Emotion;

// ISO 3166-1 alpha-2
// ⚠️ Doesn't supported in IE 11
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
      >>= Decoders.countries
      >>= (
        response =>
          response.countries
          |> Js.Array.map(country =>
               {
                 ...country,
                 label:
                   countryToFlag(country.value) ++ "   " ++ country.label,
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
let make = (~value, ~onChange, ~className) => {
  let (isOpen, setIsOpen) = React.useState(() => false);

  <Popper
    isOpen
    onClose={_ => setIsOpen(_ => false)}
    target={
      <button
        ariaLabel={
          switch (value) {
          | Some(country) => "Selected country is " ++ country.label
          | None => "Select country"
          }
        }
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
        className
        autoFocus=true
        menuIsOpen=true
        onChange={newValue =>
          newValue
          |> Js.Nullable.toOption
          |> onChange
          |> (_ => setIsOpen(_ => false))
        }
        cacheOptions=true
        defaultOptions=true
        loadOptions={(inputValue, cb) =>
          (inputValue, cb) |> loadCountries |> ignore
        }
        styles=ReactSelectOverrides.styleOverrides
        components=ReactSelectOverrides.Components.overrides
      />
    </div>
  </Popper>;
};

let default = make;
