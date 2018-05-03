# Modules

- We use the keyword `require` to import packages which may be inbuilt or 3rd party packages.
- We can even use require to require our own files
- Similar to `#include` in c++ or `import` in python

## Exploring api modules
- look at https://nodejs.org/api/ for built in modules

1. os : `const os = require('os');`
	- Used for operating system manipulations and info
2. fs : `const fs = require('fs');`
	- Used for operating system manipulations and info

## Require your own files
- use relative path
- in app.js, use `const notes = require('./notes.js');`
- `module` keyword is available for all js files.
- `module.exports` is what allows external files importing current file to access properties/functions of file
- in exporting file we add exported functions as such
```
module.exports.addNote = () => {	//ES5 Alternative to module.exports.addNote = function() {}
```
- This is an arrow function. Big difference is that arrow functions don't bind `this` keyword or args array.

## Using npm modules
- check npm version `npm -v`
- initialize npm for project `npm init`
- this generates package.json which contains the json for your project's details
- first package : lodash -> run `npm install lodash --save` this will update the package.json to include this module, reloads if you delete node_modules/
- then require it within the app.js
- when you use require, node first looks for a core module
- NOTE : always ignore node_modules from git/zips etc