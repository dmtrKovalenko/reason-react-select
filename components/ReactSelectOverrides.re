open ReactDOMRe.Style;

let styles = {
  "control": style =>
    combine(
      style,
      make(~borderBottomLeftRadius="0", ~borderBottomRightRadius="0", ()),
    ),
  "option": style => combine(style, make(~whiteSpace="pre", ())),
  "menu": style =>
    combine(
      style,
      make(
        ~marginTop="0",
        ~borderTopLeftRadius="0",
        ~borderTopRightRadius="0",
        (),
      ),
    ),
};

module InicatorsContainer = {
  [@react.component]
  let make = () => React.null;
};
