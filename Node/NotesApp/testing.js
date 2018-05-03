console.log("Starting up app..");
const fs = require('fs');	//File system module
const os = require('os');	//Operating system module
const notes = require('./notes.js');
var user = (os.userInfo())["username"];
const _ = require('lodash');

fs.appendFile('greetings.txt','\nwat u sayin '+user, function (err) {

	if(err)
	{
		console.log("error");
	}
});

fs.appendFileSync('sync-greeting.txt',`wat u saying ${user}\n`);

var res = notes.addNote();
console.log(res);

console.log(notes.add(9,22));

console.log(_.isString(true));
var arr = [1,2,3,3,2,3,5,8];
var filtarr = _.uniq(arr);
console.log(filtarr);