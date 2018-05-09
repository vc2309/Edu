var axios = require('axios');
var weather = require('./refactoraxios-2.js');
getGeocode =(uri) =>{ return new Promise((resolve,reject) => {

	axios.get(`https://maps.googleapis.com/maps/api/geocode/json?address=${uri}&key=AIzaSyALzL8WBKsZg8eEkXRzZ6CvUVsd-fmd46A`)
	.then( (response) => {
		if (response.data.status === "OK") {
			var Add = {
					formatted_address:response.data.results[0].formatted_address,
					lng:response.data.results[0].geometry.location.lng,
					lat:response.data.results[0].geometry.location.lat
				};
			resolve(Add);
		}
		else if(response.data.status === "ZERO_RESULTS"){
			reject("Unable to find that address");
		}
		else{
			reject("Invalid API key");
		}
		
	}).catch(
		(error) => {
			reject("Unable to connect");
		}
		);
});
}

getGeocode("dlf%phase%4")
	.then(
			(response) => {return weather.getWeather(response)}
		)
	.then(
			(res) => {console.log(`At ${res.formatted_address}, it is currently ${res.des} at ${res.temp} degrees F.`);}
		)
	.catch(
		(error) => {console.log(error);});
		
