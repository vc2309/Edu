## Nodemon
- this is a command line utility which we can use to restart our apps
- `npm install nodemon -g`
- not part of project's modules
- `nodemod app.js`
- keeps running till changes are made

## Getting user input
- access command line arguments using `process` object
- `process.argv` is the array of space separated arguments to the process
- [0] = node path, [1] = process file path, [2].... arguments

### Yargs 
- command line args parser


### JSON
- javascript object notation
- string which represents an object
- parse to JSON using following
```
var obj = {name="Vishnu"};
var stringObj = JSON.stringify(obj); // Parse to string

var stringPerson = '{"name":"Vishnu", "age":21}'; //String which needs to be parsed into an object
var personObj = JSON.parse(stringPerson);

// - To store to a file

const fs = require('fs');

var OriginalNote = {title="sdkjsdbksd", body="sdkj"};
fs.writeFileSync('notes.json',JSON.stringify(OriginalNote));

```