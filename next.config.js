const withTM = require('next-transpile-modules')(['bs-platform', '@ahrefs/bs-emotion'])

module.exports = withTM({
  pageExtensions: ['jsx', 'js', 'bs.js'],
})

