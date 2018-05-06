# Abstracting functionality
- for most Node projects, we want app.js to be the main interface between the user and the program.
- it should only have 1 responsibility
- we move other functionality into other modules.
- for the weather app we make a new module called geocade.js which takes the encoded address and returns the latitude and longitude

## Project structure
	WeatherApp/
		app.js
		geocode.js
		package.json
		package-lock.json

- `require('./geocode.js')` in app.js

# Making it Asynchronous
- now we call geocode.getGeocode from app.js
- to allow non blocking we add a callback function to the parameter list of getGeocode
```
var add = geocode.getGeocode(uri, (err, res) => {
	if(err==="BAD_CON")
	{
		console.log("Unable to connect");
	}
	else if(err==="BAD_ADD")
	{
		console.log("Unable to find that address");
	}
	else
	{
		console.log("Address:", res.formatted_address);
		console.log(`Longitude: ${res.lng} Latitude: ${res.lat}`)
	}
});
```
- in geocode.js, we send the request, and according to the response, we will call the callback with appropriate parameters.

```
getGeocode = (uri, callback) => {

	request({
				url:`https://maps.googleapis.com/maps/api/geocode/json?address=${uri}&key=AIzaSyALzL8WBKsZg8eEkXRzZ6CvUVsd-fmd46A`,
				json: true
			}, 
	(err, response, body) => 
		{	
			if(err)
			{
				callback('BAD_CON',null);
			}
			else if(body.status==="ZERO_RESULTS")
			{
				callback('BAD_ADD',null)
			}
			else if(body.status==='OK')
			{
					var Add = {
						formatted_address:body.results[0].formatted_address,
						lng:body.results[0].geometry.location.lng,
						lat:body.results[0].geometry.location.lat
					}
					callback(null,Add);
			}
		});
}
```
