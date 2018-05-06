# Promises in ES6
- help in synchronizing asynchronous actions
- `Promise()` is an functor type
- we make a function wrapped in a Promise object as such : `var somePromise = new Promise(<some function>) `

- the promise function will have a resolve and a reject param. The resolve function is called on success, and reject function called on failure.

- using the `then` keyword, we chain a success and a failure callback function based on the outcome of some operation.

```
somePromise.then((message) => {
	console.log("Success: ",message);
},
(err) => {
	console.log("Fail: ",err);
}
);
```

- here, somePromise will be executed. Keep in mind somePromise is a function itself. 
- some function will then either call reject or resolve within the function body. Based on which is called, one of the two callback functions placed within the param list of the `.then()` function is called.