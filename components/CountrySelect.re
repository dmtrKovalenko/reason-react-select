open Emotion;
open Popper;

// let throttledSearchCountries = Throttle.make(loadCountries, ~delay=250);

[@react.component]
let make = () => {
  let (isOpen, setIsOpen) = React.useState(() => false);

  let loadCountriesRef =
    Throttle.make(
      ~delay=250,
      ((inputValue, cb)) => {
        open! PromiseMonad;

        Fetch.fetch("/api/countries?q=" ++ inputValue)
        >>- Fetch.Response.json
        >>= Models.Decode.countries
        >>= (response => cb(response.countries))
        >>/= (
          e => {
            Js.log2("Cannot parse response:", e);
          }
        );
      },
    )
    |> React.useRef;

  <Dropdown
    isOpen
    onClose={_ => setIsOpen(_ => false)}
    target={
      <button onClick={_ => setIsOpen(_ => true)}>
        {React.string("Select country")}
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
        autoFocus=true
        cacheOptions=true
        defaultOptions=true
        loadOptions={(inputValue, cb) =>
          (inputValue, cb) |> React.Ref.current(loadCountriesRef) |> ignore
        }
      />
    </div>
  </Dropdown>;
};

let default = make;
