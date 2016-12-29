1 . `undefined` means either the variable is not defined or its value is not initialized.

```JavaScript
typeof undefined // undefined

```

2 . `null` means the value of a variable is specifically assigned with the **null** value.

```JavaScript
typeof null // Object
```

3 . `Object.create(prototypeObject)`

This method create a new object using the object in the argument as a **prototype object**. The newly created object would inherit all the property of the prototyped one.

```JavaScript
var a = {name: 'team captain'}
var b = Object.create(a)
b.name // 'team captain'
```

When changing the object structure of parent object, all the object inherit from the parent object would also change

```JavaScript
a.newPlane = 'Queen Jet'
b.newPlane // 'Queen Jet'
```

4 . `new SomeConstructor()`

Using the `new` keyword to create a new Object, the newly created object would inherit only from a special property of "SomeConstructor" that is `SomeConstructor.prototype`.

```JavaScript
function aFunction() {this.name = 'team captain'}
var b = new aFunction()
b.name // 'team captain'
```

Modifying the object structure of construction function would not have affect on the child objects (Since they inherit from `constructFunction.prototype` rather than the construct function itself). Therefore the only way to add methods/property to child object is by modifying the `constructFunction.prototype` object.

```JavaScript
aFunction.newPlane = 'Queen Jet'
b.newPlane // undefined

aFunction.prototype.newPlane = 'Queen Jet'
b.newPlane // 'Queen Jet'
```

5 . the special property 'prototype'

`prototype` property is a special attribute of **Function Objects** in JavaScript. Itself is an Object and is created from `Object.prototype`. For objects created directly from Object.prototype, they have no attribute called **prototype**

```JavaScript
var a = {}
a.prototype // undefined

function b() {}
b.prototype // Object() {...}
```

6. `__proto__` vs `prototype`

`__proto__` is the actual object (A internal attribute of every **Object** type) that used in the look up chain to resolve methods etc. While `prototype` is a property that is only available in **Function Object** type, and is the object that is used to create `__proto__` when a object is created with `new`

```JavaScript
var a = {}
a.__proto__ // Object() {...}
a.prototype // undefined

function b() {}
b.__proto__ // function() {}
b.prototype // Object() {...}
```
