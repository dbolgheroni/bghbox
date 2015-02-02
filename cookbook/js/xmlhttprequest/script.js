/* run only after page is loaded */
$(function() {
var req = new XMLHttpRequest();

req.open("GET", "note.xml");
req.send();

req.onload = function () {
    xmlDoc = req.responseXML;

    document.getElementById("to").innerHTML = xmlDoc.getElementsByTagName("to")[0].childNodes[0].nodeValue;
    document.getElementById("from").innerHTML = xmlDoc.getElementsByTagName("from")[0].childNodes[0].nodeValue;
    document.getElementById("message").innerHTML = xmlDoc.getElementsByTagName("body")[0].childNodes[0].nodeValue;
};
});
