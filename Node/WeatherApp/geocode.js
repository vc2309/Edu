var axios = require('axios');

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

module.exports = {
	getGeocode
};