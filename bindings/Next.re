module Link = {
  [@bs.module "next/link"] [@react.component]
  external make:
    (
      ~href: string=?,
      ~_as: string=?,
      ~prefetch: option(bool)=?,
      ~replace: option(bool)=?,
      ~shallow: option(bool)=?,
      ~passHref: option(bool)=?,
      ~children: React.element
    ) =>
    React.element =
    "default";
};

module Head = {
  [@bs.module "next/head"] [@react.component]
  external make: (~children: React.element) => React.element = "default";
};

module Error = {
  [@bs.module "next/head"] [@react.component]
  external make: (~statusCode: int, ~children: React.element) => React.element =
    "default";
};

module NextServer = {
  type request('a) = {
    query: 'a
  }
  
  type response('a) = {json: 'a => unit};
};

type moduleWithDefaultExportLike('a) = {. "default": React.component('a)};

type dynamicOptions = {ssr: bool};

[@bs.module "next/dynamic"]
external dynamic:
  (unit => Js.Promise.t(moduleWithDefaultExportLike('a)), dynamicOptions) =>
  React.component('a) =
  "default";
