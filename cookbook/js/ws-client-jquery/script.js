/* run only after page is loaded */
$(function() {
console.log("page loaded, executing script"); 

var req = new XMLHttpRequest();

$.getJSON("http://localhost:5000/todo/api/v1.0/tasks/1", function (response) {
    $("#id").html(response.task.id);
    $("#title").html(response.task.title);
});

});
