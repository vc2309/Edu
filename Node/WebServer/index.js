var express = require('express');
const hbs=require('hbs');
var app = express();
const port = process.env.PORT || 3000;

hbs.registerPartials(__dirname+'/views/partials');
app.set('view engine', 'hbs'); //sets handlebars as the templating engine.
hbs.registerHelper('year', () => {
	return new Date().getFullYear();
});

hbs.registerHelper('exact', () => {
	return Date();
});

app.use(express.static(__dirname + '/public'));

app.use((req,res,next) => {
	res.send('<h1>Under maintainence</h1>');

});
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


app.listen(port, () => {
	console.log("Server running on port ",port);
});