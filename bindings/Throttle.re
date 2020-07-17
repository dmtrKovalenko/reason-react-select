type fn('a, 'b) = 'a => 'b;

[@bs.module "throttle-debounce"]
external make_: (int, bool, 'a => 'b) => fn('a, 'b) = "throttle";

let make = (~delay, ~noTrailling=false, fn) => make_(delay, noTrailling, fn);
