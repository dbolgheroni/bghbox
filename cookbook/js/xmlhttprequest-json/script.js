/* run only after page is loaded */
$(function() {
var req = new XMLHttpRequest();

req.open("GET", "note.json");
req.responseType = "json";
req.send();
req.onreadystatechange = function () {
    console.log("readyState: %d", req.readyState);

    /* check to see if it's done, check http://developer.mozilla.org/en-US/docs/Web/API/XMLHttpRequest */
    if (req.readyState == 4) {
        response = req.response;

        document.getElementById("to").innerHTML = response.to;
        document.getElementById("from").innerHTML = response.from;
        document.getElementById("message").innerHTML = response.body;
    }
};
});
