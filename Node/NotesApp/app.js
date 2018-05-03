//Core mods
const fs = require('fs');
const os = require('os');

//3rd party mods
const _ = require('lodash');
const yargs = require('yargs');

//File mods
const notes = require('./notes.js');

console.log("Starting app...");

const argv = yargs.argv; //yargs version of args

switch(argv._[0])
{
	case "add":
		console.log("Adding note...");	
		var conf=notes.addNote(argv.title, argv.body);
		if(conf){
			console.log("Note added");
		}
		else
		{
			console.log("Note add failed")
		}
	break;

	case "list":
		console.log("Listing notes...");
		notes.getAll();
	break;

	case "read":
		console.log("Reading note...");	
		notes.getNote(argv.title);
	break;

	case "remove":
		console.log("Removing note...");
		notes.removeNote(argv.title);
	break;

	default: console.log("Invalid command");
}