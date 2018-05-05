# Node JS

## What is Node.js?
- Javascript runtime using the V-8 engine of chrome.
- V-8 engine is an open source js engine written in c++ which compiles js code to machine code.
- Use javascript syntax to write programs the way we write python/c++ etc.
- Built on Chrome's V8 JS engine. Super fast
- Uses event-driven, non-blocking I/O model.
- Doesn't convert to machine code first
- V-8 engine quickly converts to machine code using c++.

## Command promt node
`node`
>`console.log("hello world");`
`hello world
undefined`

## Global state
- similar to javascript `window`
- `global`
- gives world state of node process
- `process` similar to `document`

## Why Node.js?
- It is event driven and non-blocking I/O language. This means multiple users can carry out multiple requests at the same time.

## Non blocking I/O
```
//blocking.js

var u1 = getUser('123'); //requests data from db. blocks next statement till completed I/O
console.log('user1',u1); // can only happen once first is over
var u2 = getUser('321'); //requests data from db. blocks next statement till completed I/O
console.log('user1',u2);

var sum = 1+2;
console.log(sum);
```

get u1 -> print u1 -> get u2 -> print u2 -> calc sum -> print sum


```
//non-blocking.js
getUser('123', function(u1){	//these don't block the non I/O process
	console.log('u1',u1);
	});

getUser('321', function(u2){
	console.log('u2',u2);
	});

var sum = 1+3;
console.log(sum);		//not blocked by i/O
```

start getting u1, u2 -> calc and print sum -> both u1,u2 printed. faster

- In the web server example, we only use 1 single thread rather than one for each request. When request comes in, I/O is non-blocking so we don't take up any more resources than required.

## NPM package ecosystem 
- Largest ecosystem of open source libraries