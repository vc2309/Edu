var express = require('express');
const hbs=require('hbs');
var app = express();

hbs.registerPartials(__dirname+'/views/partials');
app.set('view engine', 'hbs'); //sets handlebars as the templating engine.
hbs.registerHelper('year', () => {
	return new Date().getFullYear();
});

hbs.registerHelper('exact', () => {
	return Date();
});

app.use(express.static(__dirname + '/public'));
app.get('/', (req,res) => {
	res.render('index.hbs', {
		title:"Hello biatch",
		color : "aqua"
	});
});

app.get('/bad', (req,res) => {

	res.send({
		msg: "Bad request"
	});

});

app.get('/about', (req,res) => {
	res.render('about.hbs', {
		title: "Abt"
	});
});


app.listen(3000, () => {
	console.log("Server running on port 3000");
});