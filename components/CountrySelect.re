open Emotion;

let styles = {
  "control": style =>
    ReactDOMRe.Style.combine(
      style,
      ReactDOMRe.Style.make(
        ~borderBottomLeftRadius="0",
        ~borderBottomRightRadius="0",
        (),
      ),
    ),
  "menu": style =>
    ReactDOMRe.Style.combine(
      style,
      ReactDOMRe.Style.make(
        ~marginTop="0",
        ~borderTopLeftRadius="0",
        ~borderTopRightRadius="0",
        (),
      ),
    ),
};

let loadCountries =
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
  );

[@react.component]
let make = () => {
  let (isOpen, setIsOpen) = React.useState(() => true);

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
        {React.string("Select country")}
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
        styles
        menuIsOpen=true
        autoFocus=true
        cacheOptions=true
        defaultOptions=true
        loadOptions={(inputValue, cb) =>
          (inputValue, cb) |> loadCountries |> ignore
        }
      />
    </div>
  </Popper>;
};

let default = make;
