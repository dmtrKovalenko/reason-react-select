open Emotion;
open ReactDOMRe.Style;

let styleOverrides =
  ReactSelect.styleOverrides(
    ~menu=
      style =>
        combine(
          style,
          make(
            ~marginTop="0",
            ~borderTopLeftRadius="0",
            ~borderTopRightRadius="0",
            (),
          ),
        ),
    ~control=
      style =>
        combine(
          style,
          make(~borderBottomLeftRadius="0", ~borderBottomRightRadius="0", ()),
        ),
    ~option=style => combine(style, make(~whiteSpace="pre", ())),
    ()
  );

module Components = {
  let indicatorsContainer = _ => {
    React.null;
  };

  let valueContainer = props =>
    <div
      className={css([
        display(`flex),
        alignItems(`center),
        flexBasis(100.->`pct),
        marginLeft(8->`px),
      ])}>
      <SearchIcon />
      {React.createElement(
         ReactSelect.components |> ReactSelect.valueContainerComponentGet,
         props,
       )}
    </div>;

  let overrides =
    ReactSelect.componentOverrides(~indicatorsContainer, ~valueContainer, ());
};
