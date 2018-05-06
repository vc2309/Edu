
asyncAdd = (a,b) => {
return new Promise((resolve,reject) => {
	setTimeout( () => {
		if(typeof a == typeof b =='number')
		{
			resolve(a+b);
		}
		else{
			reject("types mismatched");
		}
	},  1500);
});
}
asyncAdd('5','7').then(
	(msg) => {console.log(`Answer = ${msg}`);} , 
	(err) => {console.log(err);});


var somePromise = new Promise( (resolve,reject) => {
	resolve('Hey it worked');
	// reject("It didn't work");


});

somePromise.then((message) => {
	console.log("Success: ",message);
},
(err) => {
	console.log("Fail: ",err);
}
);