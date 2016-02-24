function Foo() {
    getName = function () { print(1); };
    return this;
}
Foo.getName = function () { print(2);};
Foo.prototype.getName = function () { print(3);};
var getName = function () { print(4);};
function getName() { print(5);}

// Foo.getName();//2
// getName();//4
// Foo().getName();//1
// getName();//1
// new Foo.getName();//2
// new Foo().getName();//3
// new new Foo().getName();//3


function Bar() {
	var getName = function() {print(1);};
	var meow = 1;
	return this;
}

var getName = function() {print(2);};

//Bar().getName();
//Bar;
var newBar = new Bar();
print(newBar.meow);