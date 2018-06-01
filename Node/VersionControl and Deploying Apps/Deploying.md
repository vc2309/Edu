# Deploying Apps to Heroku

## Install Heroku CLI
- https://devcenter.heroku.com/articles/heroku-cli
- `heroku login` to set it up
- Set up ssh keys
- `heroku keys:add`
- can always remove using `heroku keys:remove`

## Adapting your code to Heroku
- change `app.listen(...)` in server.js (or whatever)
- use env variable of Heroku
- `const port = process.env.PORT || 3000;`
- then do `app.listen(port,...)`

- Specify script in package.json
- This is a command which will be run when this is executed
- set `"start" : "node server.js"` since Heroku will always look for start script

## Create app in Heroku
- `Heroku create`
- Heroku remote will point to heroku repo