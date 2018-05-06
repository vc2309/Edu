## Encoding User Input to fit URL
- user input needs to be formatted to be sent into the url
- to get the correct input from the command line from the user we can use yargs
- chain the properties as such
```
var argv = yargs
	.options({
		address: {
			demand: true,
			alias: 'a',
			describe: 'Address to fetch weather for',
			string: true 	//Always parse the address input as a string
		},
})
	.help()
	.alias('help','h')
	.argv;
```
- we can use encodeURIComponent() to format the input string
- `encodeURIComponent(string)`
