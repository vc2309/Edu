# Middleware
- Middleware is the parts of code/functions you can insert to run within the server whenever it is running.

## Using middleware with express
- To insert middleware in the express server, we can use the following syntax:

`app.use( (req,res,next) => {//....});`

- Here, req and res are the same as in the get/post fxns, however the parameter `next` is used to make the server carry on to the latter part of the response. To finish off a middleware function and to move to the next, we must run `next();`.

## What do we use Middleware for?
- essentially middleware is in the "middle" of a request sent by a client and the response rendered by the server, so anything which needs to be validated between the request and response can be put into the middleware.
- For example user authentication, API key authentication etc.