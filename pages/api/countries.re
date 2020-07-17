open Next.NextServer;

let countries = (req, res: response(Models.countriesResponse)) => {
  Js.log(req);
  res.json({countries: CountriesList.countriesList});
};

let default = countries;
