# Advanced Templating

## Using partials
- Partials are parts of templates which we want to reuse
- In handlebars, we can use this syntax
	`hbs.registerPartials(__dirname+'/views/partials');`

- We then make a folder within the views folder called partials/
		WebServer/
			public/
			views/
				about.hbs
				index.hbs
				partials/
					footer.hbs
			index.js
- Within each template using a partial, to use a partial we do the following:
` {{> footer}}` where footer.hbs is the name of the partial file.

## Using partial helper functions
- To send dynamic data to partials, rather than sending objects repeatedly to all pages using partials, we can simply use partial helper functions.

index.js
---

	hbs.registerHelper( 'year', ()=>{
		return new Date().getFullYear();
		});

---

footer.hbs
---

	<footer> Copyright {{year}}</footer>

---

- The function name must be same as the name of the resource used within the partial as this will be referneced within the HTML.