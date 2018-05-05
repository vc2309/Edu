## Asynchronous programming
- non blocking I/O

##using setTimeout()
- `setTimeout( <callback function>, <time> ms)`

- following statements can start executing without this blocking it.
- callback function is what executes once the operation has completed.

# Callstack

callStack -----> NodeAPIs -----> Callback queue ---
											   |
    A                 					       |
    |    									   |
	-------------------------------------------
--- 
- By default, the first thing on the call stack is main() which is implicit
- each regular statement and variable executes on the callstack
- when a function is called, its placed on top of the callstack
- on returning, the fxn is popped off the stack

Asynch example
```
console.log("Startup");

setTimeout( ()=> {console.log("asynchhhhh")}, 2000);

setTimeout( ()=> {console.log("asynchhhhh")}, 0);


console.log("Finishing");
```
- console log executed on the callstack 
- setTimeout of 2s called on stack, popped off stack and placed in NodeAPIs stack and countdown started
- callstack continues
- setTimeout of 0s called and placed on NodeAPIs stack
- the callbacks of the items in the NodeAPI stack are placed in the callback queue and pushed onto stack
- before the 0s setTimeout logs, the callstack needs to be empty
- the last console log runs, so callstack is empty -> setTimeout 0s pushed from callback queue into callstack and executed
- callstack and callback queue empty but NodeAPI has a listener for setTimeout 2s. so cannot finish the program.
- 2s finish, setTimeout 2s callback pushed to callback queue, then callstack, executed and program exits.


