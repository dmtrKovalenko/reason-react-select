open Emotion;

[@react.component]
let make = (~children, ~isOpen, ~target, ~onClose) => {
  let handleKeyDown = e => {
    e
    |> ReactEvent.Keyboard.key
    |> (
      fun
      | "Escape" => onClose()
      | _ => ()
    );
  };

  <div className={css([position(`relative)])}>
    target
    {isOpen
       ? <div onKeyDown=handleKeyDown onBlur={_ => onClose()}> children </div>
       : ReasonReact.null}
  </div>;
};
