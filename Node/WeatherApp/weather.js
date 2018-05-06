var request = require('request');

getWeather = (Add, callback) => {
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
						var result={};
						result.temp = body.currently.temperature;
						result.des = body.currently.summary;
						callback(null,result);
					}
				});
}

module.exports = {
	getWeather
};