const culture = require('bindings')('culture')

console.log(`Culture date format: ${culture.getDateFormat()}`)