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
	for (var i = notes.length - 1; i >= 0; i--) {
		console.log(notes[i]);
	}
};

getNote = (title) => {
	var notes = fetchNotes();
	var filtered = notes.filter((note) => title===note.title);
	var ret = filtered.length>0 ? filtered[0] : false;
	return ret;

};

removeNote = (title) => {
	var notes = fetchNotes();
	var filtered = notes.filter((note) => title!=note.title);
	saveNotes(filtered);
	return notes.length == filtered.length;
};

module.exports = {
	addNote,
	getNote,
	getAll,
	removeNote
};