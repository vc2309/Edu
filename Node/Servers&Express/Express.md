# Express

- Express is an npm package used to set up REST API's and static web servers

## Usage
- Conventional method to use express to set up a server is as follows:

---

	var express = require('express');
	var app = express();

---

### Methods
- Now `app` will hold many properties, the two basic ones are the methods `app.get()` and `app.post()`
- As expected, these will handle what happens within the server when a particular request occurs.
- For a client get request at the root route , we will write the following method:

		app.get('/', (req,res) => {
			res.send('Hello Express!');
			})
- the params are as follows:
	1. req : request object
	2. res : response object
- both of these have a lot of data as well as functionality which can be explored in more detail on the express website.

- the app will not yet be able to listen for requests. for this we need to write the following statement:

		app.listen(3000);
- this will listen at localhost:3000/ for now, later we will explore how to deploy an app to an actual web server


### Using chrome dev tools network tab
- Use this to view the request details

### Using local resources
- to access resources such as templates, we can use the following code:
	`app.use(express.static(__dirname+'/public'));`

## Templating
- We use a templating engine called handlebars
- It is a module in npm called hbs
`npm install hbs --save`
- To tell express that we are using handlebars as the templating engine, we use
	`app.set('view engine', 'hbs');`

### Rendering with handlebars
- We make a folder called 'views' in our project directory
- Suppose we make a template called `about.html`, we use the following syntax
