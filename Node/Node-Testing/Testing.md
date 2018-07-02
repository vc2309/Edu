# Testing Applications

## Using mocha
	npm i mocha --save-dev
- This means the module is only required in development, not in deployment

### Creating a test file
- For any js file, eg. utils.js, add the extension `.test.js` : `utils.js -> utils.test.js`, this lets mocha know where to look for test cases.

- Mocha follows behaviour driven development : BDD, so for each module, we set an expectation within the it() function:
	
		it('should add two numbers', ()=> {
			// Testing logic
			});
- Throw an error for an incorrect result
		
		if(//result is wrong)
			throw new Error(`Expected ${}..`)

### Auto rerunning tests
- Using nodemon again
		
		nodemon --exec 'npm test'
- In package.json, put
		
		"test-watch": "nodemon --exec \"npm test\""