var express = require('express');

var app=express();

app.get('/', (req,res) => {

	// res.send('<h1>Hello express!</h1>');
	res.send({
		name: 'Vishnu',
		hobbies: ['food','food','food']
	});
});

app.get('/bad' ,(req,res) => {
	res.send({
		errorMessage: "Unable to find resource"
	});
})

app.listen(3000);