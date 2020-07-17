# A demo application using react-select and ReasonML

**Checkout this app running** at https://ahrefs-task.dmtr-kovalenko.vercel.app/

This example features:

- Have inbound `/api/countries` route written in Reason
- Have a select component that queries route and shows the options
- Have couple of cypress tests confimring this behavior

*Make sure*

Real entry point of application is `components/root.re` because bunch of reason declarations just doesn't support SSR because of missing `cjs` output.

## Deploy your own

Deploy the example using [Vercel](https://vercel.com) right now:

[![Deploy with Vercel](https://vercel.com/button)](https://vercel.com/import/project?template=https://github.com/dmtrKovalenko/reason-react-select)

## How to use

Run locally

```
yarn
yarn dev
```

Run Cypress tests

```
yarn test
```

Deploy to vercel via CLI

```
yarn now
```


