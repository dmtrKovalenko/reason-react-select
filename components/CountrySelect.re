open Emotion;
open Popper;

let loadCountries = inputValue => {
  open! PromiseMonad;

  Fetch.fetch("/api/countries")
  >>- Fetch.Response.json
  >>= Models.Decode.countries
  >>= (response => response.countries)
  >>/= (
    e => {
      Js.log2("Cannot parse response:", e);
      [||];
    }
  );
};

[@react.component]
let make = () => {
  let (isOpen, setIsOpen) = React.useState(() => false);

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
        loadOptions=loadCountries
      />
    </div>
  </Dropdown>;
};

let default = make;
