## Arrow functions
- this is an ES6 feature
- not completely swappable with a regular ES5 function

## Special features
- typical syntax
```
var square = (x) => {
	return x*x;
};
```

- minimalist function
```
var cube = (x) => x*x*x; //Minimal fxn returning x^3

```

## Differences
- doesn't bind a `this` keyword. cannot reference

- doesn't bind a `arguments` array
- this `arguments` array is an implicit array which is passed if a function without a parameter list is called with parameters.