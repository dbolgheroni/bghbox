/* run only after page is loaded */
$(function() {
var req = new XMLHttpRequest();

req.open("GET", "http://localhost:5000/todo/api/v1.0/tasks/1")
req.responseType = "json";
req.send();
req.onload = function () {
    response = req.response;

    $("#id").html(response.task.id);
    $("#title").html(response.task.title);
};
});
