open Json.Decode;

type country = {
  label: string,
  value: string,
};

type countriesResponse = {countries: array(country)};

module Decode = {
  let country = countryJson => {
    label: countryJson |> field("label", string),
    value: countryJson |> field("value", string),
  };
  
  let countries = countriesJson => {
    countries: countriesJson |> field("countries", array(country)),
  };
};
