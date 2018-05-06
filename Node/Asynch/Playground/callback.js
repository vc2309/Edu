getUser = (id, callback) => {
	var user = {
		id:id,
		name : "Vishnu"
	};
	callback(user);
};

getUser(31, (user) => {

	console.log(user);
});