## What is a callback function?
- it is a function which is passed as an argument to another function, which gets executed after the initial function completes.

### Pretty printing objects
- when we console log an object, it gets clipped
- to pretty print an object and get a structured display of the object use JSON.stringify
- `JSON.stringify(body, undefined, 2)`
-arguments are ( <obj>, <props to clip>, <spaces> )


#HTTP
- the request sent receives 3 arguments passed back into the callback : error, response and body
- response is an HTTP response with the following
	- http status code : 200/404/301...
	- http flags 
	- body
- error contains the object filled with any mistakes made in making the request in the first place
- error has a code 