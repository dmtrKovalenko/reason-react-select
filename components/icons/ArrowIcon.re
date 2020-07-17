[@react.component]
let make = (~className) => {
  <svg className width="8" height="8" viewBox="0 0 8 5">
    <title> {React.string("arrow")} </title>
    <g fill="none" fillRule="evenodd">
      <path
        d="M14.999-10.5A2.503 2.503 0 0117.5-7.992h0v19.984c0 .694-.279 1.321-.732 1.776a2.489 2.489 0 01-1.77.732h0-112.997a2.503 2.503 0 01-2.501-2.508h0V-7.992c0-.694.279-1.321.732-1.776a2.489 2.489 0 011.77-.732h0z"
        strokeOpacity="0.2"
        stroke="#000"
        fill="#FFF"
      />
      <path d="M0-2h8v8H0z" />
      <path fill="#333" d="M0 0h8L4 5z" />
    </g>
  </svg>;
};
