type optionProps('a) = {data: 'a};

[@bs.deriving abstract]
type components('a) = {
  [@bs.as "Input"]
  inputComponent: React.component({.}),
  [@bs.as "ValueContainer"]
  valueContainerComponent: React.component({.}),
  [@bs.as "Option"]
  optionComponent: React.component(optionProps('a)),
};

[@bs.module "react-select"]
external components: components('a) = "components";

[@bs.deriving abstract]
type componentOverrides = {
  [@bs.optional] [@bs.as "Input"]
  input: ({. }) => React.element,
  [@bs.optional] [@bs.as "IndicatorsContainer"]
  indicatorsContainer: ({. }) => React.element,
  [@bs.optional] [@bs.as "ValueContainer"]
  valueContainer: ({. }) => React.element,
};

type styleInjector = ReactDOMRe.Style.t => ReactDOMRe.Style.t;

[@bs.deriving abstract]
type styleOverrides = {
  [@bs.optional]
  menu: styleInjector,
  [@bs.optional]
  control: styleInjector,
  [@bs.optional]
  option: styleInjector,
};

module Async = {
  [@bs.module "react-select/async"] [@react.component]
  external make:
    (
      ~autoFocus: bool=?, /* autofocus the component on mount */
      ~cacheOptions: bool=?, /* cache loaded async options */
      ~className: string=?, /* className for the container  */
      ~defaultOptions: bool=?, /* if `true` load will be initiated on initial open */
      ~deleteRemoves: bool=?, /* whether pressing delete key removes the last item when there is no input value */
      ~delimiter: string=?, /* delimiter to use to join multiple values */
      ~disabled: bool=?, /* whether the Select is disabled or not */
      ~loadOptions: (string, Js.Array.t('a) => unit) => unit=?,
      ~menuIsOpen: bool=?, /* if `true` menu is always open */
      ~onChange: Js.nullable('a) => unit=?, /* onChange handler: function(newOption) {} */
      ~options: array('a)=?, /* array of options */
      ~styles: styleOverrides=?, /* style override injectors  */
      ~components: componentOverrides=?, /* component renderers */
      ~value: option('a)
    ) =>
    React.element =
    "default";
};
