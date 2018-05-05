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
printNote = (note) => {
	console.log(`Title : ${note.title}`);
	console.log(`Body : ${note.body}`);
}
switch(argv._[0])
{
	case "add":
		console.log("Adding note...");	
		var conf=notes.addNote(argv.title, argv.body);
		if(conf){
			console.log("Note added");
			var note = { 
				title : argv.title, 
				body : argv.body
			};
			printNote(note);
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
		var note = notes.getNote(argv.title);
		note? printNote(note) : console.log("Note not found");
	break;

	case "remove":
		console.log("Removing note...");
		notes.removeNote(argv.title)? console.log("Note not valid") : console.log("Note removed");
	break;

	default: console.log("Invalid command");
}

