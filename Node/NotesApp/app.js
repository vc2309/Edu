//Core mods
const fs = require('fs');
const os = require('os');

const req_title = {
			describe: 'Title of note',
			demand: true, //Means its required
			alias: "t"
		   };
const req_body = {
		describe: 'Body of note',
		demand: true,
		alias: "b"
	};

//3rd party mods
const _ = require('lodash');
const yargs = require('yargs')	
const argv = yargs
.command('add', 'Add a new note',{
		title: req_title,
		body: req_body
	})	//(COMMAND, DESCRIPTION, OBJECT of options.)

.command('list','List all notes')

.command('remove', 'Remove a specific note',{
	title: req_title
})

.command('read', 'Read a specific note',{
	title: req_title
})

.help()	//Lists all commands, options with --help flag


//File mods
const notes = require('./notes.js');

console.log("Starting app...");


printNote = (note) => {
	console.log(`Title : ${note.title}`);
	console.log(`Body : ${note.body}`);
}
switch(argv.argv.c_[0])
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

