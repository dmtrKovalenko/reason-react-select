open Models;
open Json.Decode;

let country = countryJson => {
  label: countryJson |> field("label", string),
  value: countryJson |> field("value", string),
};

let countries = countriesJson => {
  countries: countriesJson |> field("countries", array(country)),
};
