var express = require('express');

var app = express();

app.use(express.static(__dirname + '/public'));
app.get('/', (req,res) => {
	res.send('<h1>Hello biatch</h1>');
});

app.get('/bad', (req,res) => {

	res.send({
		msg: "Bad request"
	});

});



app.listen(3000, () => {
	console.log("Server running on port 3000");
});