

// Illustrate that the env variable is getting injected into process.env
console.log("start process. In this process the library path is set to:",process.env["LD_LIBRARY_PATH"]);

// Illustrate that this is irrelevant to the actual dlopen resolution:

const {cfunc} = require("./build/Release/addon");
cfunc();
console.log("done");

setTimeout(function(){
	console.log("you waited a long time");
},1000000);