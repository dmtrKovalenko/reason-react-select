[@react.component]
let make = () => {
  let (value, setValue) = React.useState(() => None);

  <CountrySelect
    value
    className="country-selector"
    onChange={newValue => setValue(_ => newValue)}
  />;
};

let default = make;
