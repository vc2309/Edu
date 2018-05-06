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

geocode.getGeocode(uri, (err, res) => {
	
	if(err==="BAD_CON")
	{
		console.log("Unable to connect");
	}
	else if(err==="BAD_ADD")
	{
		console.log(res);
	}
	else
	{	
		weather.getWeather(res, (err, result) => {
			if(err==="BAD_ADD")
			{
				console.log(result);
			}
			else
			{
				console.log(`At ${res.formatted_address}, it is currently ${result.des} at ${result.temp} degrees F.`)
			}
		});
	}	
});
console.log("Waiting for response...");