## Debug mode in Command Prompt/Terminal
- enter with `node inspect app.js`
- `next` for next line of code
- use `list(10)` to go next 10 lines of code
- `c` or `continue` runs through lines of code till the program completes

## REPL 
- Read evaluate print loop
- kind of like console in chrome dev tools
- `repl`

## Debugger statement
- within the script, write `debugger`
- run `c` in debug mode to get to line break at debugger statement

### Can run with nodemon as well
- `nodemon inspect app.js`
- make changes on the fly, and nodemon restarts debugger

## Debugging via Chrome dev tools
- `node --inspect-brk app.js`
- open chrome://inspect/
- lists all of remote targets
- open 'Open dedicated DevTools'
- open sources, toggle console with esc
- use buttons to run through lines of code
- 