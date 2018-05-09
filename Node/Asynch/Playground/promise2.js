var request = require('request');

var geocodeAddress = (address) => {
	return new Promise( (resolve, reject) => {
		request({
				url:`https://maps.googleapis.com/maps/api/geocode/json?address=${uri}&key=AIzaSyALzL8WBKsZg8eEkXRzZ6CvUVsd-fmd46A`,
				json: true
			}, 
	(err, response, body) => 
		{	
			if(err)
			{
				reject('BAD_CON');
			}
			else if(body.status==="ZERO_RESULTS")
			{
				reject('BAD_ADD');
			}
			else if(body.status==='OK')
			{
				var Add = {
					formatted_address:body.results[0].formatted_address,
					lng:body.results[0].geometry.location.lng,
					lat:body.results[0].geometry.location.lat
				};
				resolve(Add);
			}	
});
	}
};

geocodeAddress('19146').then( (location) => {
	return weather.getWeather(location);

}, (err) => {
	if(err==="BAD_CON")
	{
		console.log("Unable to connect");
	}
	else if(err==="BAD_ADD")
	{
		console.log("Unable to find that address");
	}
}
).then(return )