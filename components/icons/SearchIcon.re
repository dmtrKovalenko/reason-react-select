[@react.component]
let make = () => {
  <svg width="13" height="13" viewBox="0 0 13 13">
    <title> {ReasonReact.string("icon")} </title>
    <defs>
      <filter
        x="-2.6%"
        y="-2.5%"
        width="105.2%"
        height="106%"
        filterUnits="objectBoundingBox"
        id="prefix__a">
        <feMorphology
          radius="1"
          operator="dilate"
          in_="SourceAlpha"
          result="shadowSpreadOuter1"
        />
        <feOffset
          dy="1"
          in_="shadowSpreadOuter1"
          result="shadowOffsetOuter1"
        />
        <feGaussianBlur
          stdDeviation="1.5"
          in_="shadowOffsetOuter1"
          result="shadowBlurOuter1"
        />
        <feComposite
          in_="shadowBlurOuter1"
          in2="SourceAlpha"
          operator="out"
          result="shadowBlurOuter1"
        />
        <feColorMatrix
          values="0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0.1 0"
          in_="shadowBlurOuter1"
        />
      </filter>
      <filter
        x="-.2%"
        y="-1.4%"
        width="100.4%"
        height="102.9%"
        filterUnits="objectBoundingBox"
        id="prefix__d">
        <feOffset dy="-1" in_="SourceAlpha" result="shadowOffsetInner1" />
        <feComposite
          in_="shadowOffsetInner1"
          in2="SourceAlpha"
          operator="arithmetic"
          k2="-1"
          k3="1"
          result="shadowInnerInner1"
        />
        <feColorMatrix
          values="0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0.08 0"
          in_="shadowInnerInner1"
        />
      </filter>
      <path
        d="M0 2.002C0 .896.903 0 2.006 0h225.988C229.102 0 230 .887 230 2.002v194.996a2.007 2.007 0 01-2.006 2.002H2.006A1.998 1.998 0 010 196.998V2.002z"
        id="prefix__b"
      />
      <path id="prefix__c" d="M0 0h230v35H0z" />
    </defs>
    <g fill="none" fillRule="evenodd">
      <g transform="translate(-11 -11)">
        <use fill="#000" filter="url(#prefix__a)" xlinkHref="#prefix__b" />
        <path
          strokeOpacity="0.08"
          stroke="#000"
          d="M227.994-.5a2.502 2.502 0 012.506 2.502h0v194.996c0 .69-.281 1.316-.735 1.768a2.501 2.501 0 01-1.77.734h0H2.004A2.502 2.502 0 01-.5 196.998h0V2.002c0-.69.281-1.316.735-1.768A2.501 2.501 0 012.005-.5h225.99z"
          fill="#FFF"
        />
      </g>
      <g transform="translate(-11 -11)">
        <use fillOpacity="0.08" fill="#FFF" xlinkHref="#prefix__c" />
        <use fill="#000" filter="url(#prefix__d)" xlinkHref="#prefix__c" />
      </g>
      <path d="M-1-1h14v14H-1z" />
      <path
        d="M5 0a5 5 0 014.17 7.758l3.3 3.302-1.41 1.41-3.302-3.3A5 5 0 115 0zm0 1.8a3.2 3.2 0 100 6.4 3.2 3.2 0 000-6.4z"
        fill="#333"
      />
    </g>
  </svg>;
};
