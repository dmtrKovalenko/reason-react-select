open Models;
open Next.NextServer;

[@bs.deriving abstract]
type countriesQuery = {
  [@bs.optional]
  q: string,
};

let max_search_results = 10;

let searchCountries = substring => {
  let toLower = Js.String.toLowerCase;
  let caseInsensetiveQuery = substring |> toLower;

  CountriesList.countriesList
  |> Js.Array.filter(country =>
       country.label |> toLower |> Js.String.startsWith(caseInsensetiveQuery)
     )
  |> Js.Array.slice(~start=0, ~end_=max_search_results);
};

let countries = (req, res: response(countriesResponse)) => {
  let input =
    req.query
    |> qGet
    |> (
      fun
      | Some(value) => value
      | None => ""
    );

  let filterredCountries = input |> searchCountries;
  res.json({countries: filterredCountries});
};

let default = countries;
