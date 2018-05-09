var axios = require('axios');

getWeather = (Add) => {
	return new Promise ( (resolve,reject) => {
		axios.get(`https://api.darksky.net/forecast/f5001fa98e8de0c4ae799863261d3f17/${Add.lat},${Add.lng}`)
			.then(
				(response)=>{
					
					if (response.status===200) 
						{console.log(response.status);
							var result={};
							result.temp = response.data.currently.temperature;
							result.des = response.data.currently.summary;
							result.formatted_address = Add.formatted_address;
							resolve(result);
						}
					else
					{
						reject("Unable to fetch weather");
					}
				})
			.catch(
				(err)=>{
					
					reject("Unable to fetch weather");
				}
				);
	});
}

// getGeocode("122009")
// 	.then(
// 		(response) => {console.log(JSON.stringify(response,undefined,2));})
// 	.catch(
// 		(error) => {console.log(error);});

module.exports = {
	getWeather
};