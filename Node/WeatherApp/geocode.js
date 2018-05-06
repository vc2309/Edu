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
				callback(null,Add);
			}	
});

}
module.exports = {
	getGeocode
};