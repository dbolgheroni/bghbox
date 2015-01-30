/* run only after page is loaded */
$(window).bind("load", function() {
var req = new XMLHttpRequest();

req.open("GET", "note.xml");
req.send();
req.onreadystatechange = cb;

function cb() {
    console.log("readyState: %d", req.readyState);

    /* check to see if it's done, check http://developer.mozilla.org/en-US/docs/Web/API/XMLHttpRequest */
    if (req.readyState == 4) {
        xmlDoc = req.responseXML;

        document.getElementById("to").innerHTML = xmlDoc.getElementsByTagName("to")[0].childNodes[0].nodeValue;
        document.getElementById("from").innerHTML = xmlDoc.getElementsByTagName("from")[0].childNodes[0].nodeValue;
        document.getElementById("message").innerHTML = xmlDoc.getElementsByTagName("body")[0].childNodes[0].nodeValue;
    }
};
});
