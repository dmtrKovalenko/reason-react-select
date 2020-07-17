open Emotion;
open Popper;

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
      />
    </div>
  </Dropdown>;
};

let default = make;
