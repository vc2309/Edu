const util = require('./utils')
it('should add two numbers', () => {
	var res = util.add(5,5);
	if(res!==9)
		throw new Error(`Expected ${4+5}, got ${res}`);

});

it('should square a given number', ()=>{
	var res = util.square(4);
	if(res!==16)
		throw new Error(`Expected ${4*4}, got ${res}`);

});