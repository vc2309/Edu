var yargs = require('yargs');
var geocode = require('./geocode');
var weather = require('./weather')
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


var uri = encodeURIComponent(argv.address);	//T

getGeocode(uri)
	.then(
			(response) => {return weather.getWeather(response)}
		)
	.then(
			(res) => {console.log(`At ${res.formatted_address}, it is currently ${res.des} at ${res.temp} degrees F.`);}
		)
	.catch(
		(error) => {console.log(error);});
console.log("Waiting for response...");