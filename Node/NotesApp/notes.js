const fs = require('fs');

console.log("starting notes.js ..");

fetchNotes = () => {
	var notes = [];

	try{
		var notesString = fs.readFileSync('notes-data.json');
		notes = JSON.parse(notesString);
	}
	catch(e)
	{

	}

	return notes;
}

saveNotes = (notes) => {

	fs.writeFileSync('notes-data.json',JSON.stringify(notes));
}

addNote = (title, body) => {	//ES5 Alternative to module.exports.addNote = function() {}
	console.log("Adding note", title);
	
	var note = {
		title,
		body
	};

	var notes = fetchNotes();
	var checkDups = notes.filter((note) => title == note.title);

	if(checkDups.length === 0){
		notes.push(note);
		saveNotes(notes);
		return note;
	}
	
};

getAll = () => {
	console.log("Getting all...");
	var notes = fetchNotes();
};

getNote = (title) => {
	console.log("Getting note", title);
};

removeNote = (title) => {
	console.log("Removing note", title);
};

module.exports = {
	addNote,
	getNote,
	getAll,
	removeNote
};