let defer = (f): Js.Promise.t('a) =>
  Js.Promise.make((~resolve, ~reject as _) => ignore(f(resolve)));

let resolve = (a: 'a): Js.Promise.t('a) => Js.Promise.resolve(a);

let raiseASync = (a: exn): Js.Promise.t('a) => Js.Promise.reject(a);

/** Resolve promise, requires to manually handle promise */
let (>>-) = (m: Js.Promise.t('a), f: 'a => Js.Promise.t('b)) =>
  Js.Promise.then_(f, m);

/** Resolve promise with auto return */
let (>>=) = (m: Js.Promise.t('a), f: 'a => 'b) =>
  Js.Promise.then_(a => resolve(f(a)), m);

let (>>|) = (m: Js.Promise.t('a), f: 'a => 'b) =>
  Js.Promise.then_(
    a => {
      f(a);
      resolve(ignore);
    },
    m,
  );

/** Catch promise */
let (>>/) = (m: Js.Promise.t('a), f: Js.Promise.error => Js.Promise.t('a)) =>
  Js.Promise.catch(f, m);

/** Catch promise with auto return */
let (>>/=) = (m: Js.Promise.t('a), f: Js.Promise.error => 'a) =>
  Js.Promise.catch(e => Js.Promise.resolve(f(e)), m);
