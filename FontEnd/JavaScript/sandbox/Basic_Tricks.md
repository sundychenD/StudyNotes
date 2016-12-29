### Some Tricks about javascript

<meta>

Created 24/02/2015 
Retrieved from [http://mp.weixin.qq.com/s?__biz=MzAxODE2MjM1MA==&mid=402252398&idx=1&sn=f163fcc3637f57cd53678e7dd3bea19e&scene=2&srcid=0222e5wuCPbbRPxxY1o3tbVX&from=timeline&isappinstalled=0#wechat_redirect](http://mp.weixin.qq.com/s?__biz=MzAxODE2MjM1MA==&mid=402252398&idx=1&sn=f163fcc3637f57cd53678e7dd3bea19e&scene=2&srcid=0222e5wuCPbbRPxxY1o3tbVX&from=timeline&isappinstalled=0#wechat_redirect)
</meta>

---

```
function Foo() {
    getName = function () { alert (1); };
    return this;
}
Foo.getName = function () { alert (2);};
Foo.prototype.getName = function () { alert (3);};
var getName = function () { alert (4);};
function getName() { alert (5);}
```

What's the execution result of the following code?

```
Foo.getName();//2
getName();//4
Foo().getName();//1
getName();//1
new Foo.getName();//2
new Foo().getName();//3
new new Foo().getName();//3
```

##### Q1 
`Foo.getName()`

---
Get the static field of Foo, which got assigned during `Foo.getName = function () {alert (2);}`


##### Q2 
`getName()`

---
invoke the "getName" in the current context field.

here be careful on "Var Hoisting"

- Var Hoisting

	When declaring var or function, they would be lifted to the top of the code:
	
	```
	console.log('x');//true
	var x;
	x = 0;
	```
	
	would be come
	
	```
	var x;
	console.log('x');//true
	x = 0;
	```
	
- Function Expression
	
	both `var getName` and `function getName` declares getName , however `var getName` is an expression, but `function getName` is an declaration.
	
	For "Expression", usually they would be splited into two and execute separately.
	
	```
	console.log(x);//output：function x(){}
	var x=1;
	function x(){}
	``` 
	In real execution, "var x = 1" would be split into "var x" and x = 1; then both var x and function x(){} would be raised onto top, which becomes:
	
	```
	var x;
	function x(){}
	console.log(x);
	x = 1;
	```
	


Therefore the original code execution sequence would become:
	
	```
	function Foo() {...}
	var getName;	//lift declaration
	function getName() {5} // raise declaration, cover var	
	Foo.getName = function () {2};
	Foo.prototype.getName = function(){3};
	getName = function () {4}; // again cover getName
	getName(); // output 4
	```

##### Q3	
`Foo().getName()`

---

Here "Foo()" has been executed first, then call "getName" on the returned object of "Foo()".

Inside "Foo()", the first `getName = function() {alert(1);}` is an assignment!!! as it doesn't have "var" declaration, which mean it would try to find a variable named "getName" in the current context. If cannot find, then go one level up/out. Here it can find the variable one level up/out, which is the `getName` in Q2, and re-assign the it's value to be `function(){alert(1)}`

So here it actually changed the `getName` function in it's outer context.


<i>==== P.S.==== <br>
If still cannot find in the outer context, it would go the outermost environment (here we assume it's in a browser) which would be the `window` object, and create a variable `getName` =========== </i>


Since Foo returns `this`, and `this` always returns the caller context, which is `window` object here, so `this` points to window object.

```
Function Bar() {return this;}
>>> undefined
Foo()
>>> Object Window {...}
```

so the final execution becomes `window.getName()`, and since the `getName` in window has been changed to `alert(1)`, therefore the output is 1.

TWO points has been tested here, first is "CONTEXT FIELD", second is "this" pointer.


##### Q4
`getName()`

---
As we explained in Q3, the execution here is equivalent to 

```
window.getName()
```

which was changed during the execution of `Foo()`, so there would return the same as Q3, which is 1.


##### Q5
`new Foo.getName()`

---
Here the priority of operator is been tested.

the operator (.) has a higher priority than (new), therefore the execution is equivalent to 

```
new (Foo.getName)();
```
it means we use `function() {alert(2);}` as the contruction function, so here it would give 2.

check [https://developer.mozilla.org/zh-CN/docs/Web/JavaScript/Reference/Operators/Operator_Precedence](https://developer.mozilla.org/zh-CN/docs/Web/JavaScript/Reference/Operators/Operator_Precedence) for operator priority.

##### Q6
`new Foo().getName()`

---

here the operator (()) has a higher priority than (new), so the execution order is equivalent to 

```
(new Foo()).getName()
```

Here we first construct an object using function `Foo`, and "Foo" has a return value, so how do we determine what gets returned?

- <b>Return from construction function</b><br>
	Return from function construction
	In traditional language, construction function should not has a return value, the execution should just return the instantiated object.
	
	However in JavaScript the construction function may or maynot have a return value.
	
	<b>CASE 1: No return value</b><br>
	Return as normal, return the instantiated object.
	
	```
	function F() {}
	>>> undefined
	new F()
	>>> F {	}
	```
	
	<b>CASE 2: return non-referential type</b><br>
	return type is (string, number, boolean, null, undefined), then treat it the same as no return type, return the instantiated object.
	
	```
	function F() {return true;}
	>>> undefined
	new F()
	>>> F {}
	```
	
	<b>CASE 3: return referential type</b><br>
	return the referenced object
	
	```
	function F() {return {a:1};}
	>>> undefined
	new F()
	>>> Object {a: 1}
	```
	
in the original question `(new Foo()).getName()`, the contruction function returns `this`, which would pointed to current instantiated object.

Then the `getName()` would call on the instantiated object `Foo()`, however it cannot find any attribute name "getName" in the instantiated object, therefore it would find the prototyped object of `Foo()`, and then give 3.


##### Q7
`new new Foo().getName();`

Same as Q6, here the priority of operator is been tested.

the final execution is equivalent to 

```
new ((new Foo()).getName())();
```

Here we first instantiate `Foo`, and using the `getName` function that is on the `prorotype Foo` as the construction function to build a new object.

Therefore it gives 3.

	
	





















