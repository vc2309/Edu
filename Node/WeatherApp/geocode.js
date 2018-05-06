var request = require('request');

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
				callback('BAD_ADD',"Unable to find that address");
			}
			else if(body.status==='OK')
			{
				var Add = {
					formatted_address:body.results[0].formatted_address,
					lng:body.results[0].geometry.location.lng,
					lat:body.results[0].geometry.location.lat
				};
				request({
					url:`https://api.darksky.net/forecast/f5001fa98e8de0c4ae799863261d3f17/${Add.lat},${Add.lng}`,
					json: true
				}, 
				(err, response, body) => {
					if(err || response.statusCode !=200)
					{
						callback('BAD_ADD',"Unable to fetch weather");
					}
					else{
						Add.temp = body.currently.temperature;
						Add.des = body.currently.summary;
						callback(null,Add);
					}
				});
				
			}	
});

}
module.exports = {
	getGeocode
};