## Javascript Prototypes
<meta> Created 24/02/2016 </meta>

---

- Functions on the prototype are only created once and shared between each instance.

- Functions created in the constructor are created as new objects for each new object created with the constructor.

##### General Rule: 

functions should be on the prototype since they will generally not be modified for different objects of the same type, and this has a slight memory/performance benefit. 

Other properties like objects and arrays should be defined in the constructor, unless you want to create a shared, static property, in which case you should use the prototype.

```
function Foo(){
    this.bar = [];
}
var fooObj1 = new Foo();
var fooObj2 = new Foo();

fooObj1.bar.push("x");
alert(fooObj2.bar) //[]
```


```
function Foo(){
}

Foo.prototype.bar = []
var fooObj1 = new Foo();
var fooObj2 = new Foo();

fooObj1.bar.push("x");
alert(fooObj2.bar) //["x"]
```