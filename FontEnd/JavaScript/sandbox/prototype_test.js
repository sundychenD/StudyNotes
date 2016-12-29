function Human1(age, gender) {
	this.age = age;
	this.gender = gender;
	this.sayHi = function() {print("hi!")};
}

var myFather = new Human1(30, "male"); 
try {
	print(myFather.age) 			// 30
} catch (e) {
	print(e);
}






function Human2() {}

var myMother = Human2();
try {
	print(myMother);		// undefined
	print(myMother.age); 	// TypeError, cannot read property 'age' of undefined
} catch (e) {
	print(e);
}






function Human3() {}
Human3.prototype.age = 30

var myMother = Human3()
try {
	print(myMother); // undefined
} catch (e) {
	print(e);
}






function Human3() {}
Human3.prototype.age = 30

var myMother = new Human3()
try {
	print(myMother.age); // 30
} catch (e) {
	print(e);
}







function Human4() {
	this.sayHi = function() {print("hi");}
}

var myMother = new Human4(); 
try {
	myMother.sayHi();				// "hi"
	print(Human4.prototype.sayHi); 	// undefined
	print(Human4.sayHi);			// undefined
} catch (e) {
	print(e);
}






function Human5() {}
Human5.prototype.sayHi = function() {print("hi");}

var myMother = new Human5(); 
try {
	myMother.sayHi();				// "hi"
	print(Human5.prototype.sayHi); 	// undefined
} catch (e) {
	print(e);
}
	