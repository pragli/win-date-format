const Culture = require('bindings')('culture');

module.exports = {
  getDateFormat: () => Culture.getDateFormat()
}
