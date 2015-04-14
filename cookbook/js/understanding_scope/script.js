/* run only after page is loaded */
$(function() {
console.log("page loaded, executing script"); 

var x = 1;

var func1 = function () {
    var x = 2;
    console.log("inside func1: ", x);


    var func11 = function() {
        var x = 3;
        console.log("inside func11 in func1: ", x);
    }

    func11();
    console.log("inside func1: ", x);
}

console.log("outside func1: ", x);
func1();

});
