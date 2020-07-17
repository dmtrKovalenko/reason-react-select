// we need this awful thing because of @ahrefs/bs-emotion doesn't support SSR
module DynamicSelect = {
  [@bs.obj] external makeProps: unit => {.};

  let importCountrySelect:
    unit => Js.Promise.t({. "default": React.component({.})}) = [%bs.raw
    {|
      () => import("../components/CountrySelect.bs.js")
    |}
  ];

  let make = Next.dynamic(importCountrySelect, { ssr: false });
};

[@react.component]
let make = () => {
  <DynamicSelect />;
};

let default = make;
