open Emotion;

let button = css([display(`flex)]);

Js.log(button);

[@react.component]
let make = () => {
  <div className=button> {React.string("wenfiwnefiojn")} </div>;
};

let default = make;
