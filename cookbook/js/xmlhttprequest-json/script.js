/* run only after page is loaded */
$(function() {
var req = new XMLHttpRequest();

req.open("GET", "note.json");
req.responseType = "json";
req.send();
req.onload = function () {
    response = req.response;

    document.getElementById("to").innerHTML = response.to;
    document.getElementById("from").innerHTML = response.from;
    document.getElementById("message").innerHTML = response.body;
};
});
