open Emotion;
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

let components = {
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
};
