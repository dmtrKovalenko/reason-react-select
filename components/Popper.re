open Emotion;

module Blanket = {
  [@react.component]
  let make = (~onClick) => {
    <div
      onClick
      className={css([
        bottom(`px(0)),
        left(`px(0)),
        right(`px(0)),
        top(`px(0)),
        position(`fixed),
        zIndex(1),
      ])}
    />;
  };
};

[@react.component]
let make = (~children, ~isOpen, ~target, ~onClose) => {
  <div className={css([position(`relative)])}>
    target
    {isOpen ? <> children <Blanket onClick=onClose /> </> : ReasonReact.null}
  </div>;
};
