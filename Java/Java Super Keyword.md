### Super Keyword
---

resources: [https://docs.oracle.com/javase/tutorial/java/IandI/super.html](https://docs.oracle.com/javase/tutorial/java/IandI/super.html)

#### Accessing Superclass members

When a method overrides one of its superclass's methods, we can invoke the overriden method through `super`

E.G.

```
public class Superclass {
	public void printMethod() {
		System.out.println("Printed in Superclass");
	}
}
public class Subclass extends Superclass {
	// overrides printMethod in Superclass
	public void printMethod() {
		super.printMethod();
		System.out.println("Printed in subclass");
	}
	public static void main(String[] args) {
		Subclass s = new Subclass();
		s.printMethod();
	}
}
>>>
>>> Printed in Superclass.
>>> Printed in Subclass
```

#### Subclass Constructors

Calls the superclass constuctor and then add initialzation code of its own

`invokation of a superclass constructor must be the first line in the subclass constructor`

Systax for calling a superclass constuctor is

```
super();
or
super(parameter list); // Constructor with a matching parameter list is called.
```

E.G.

```
public Bicycle {
	public int height;
	public int gear;
	public Bicycle(height, gear) {
		this.height = height;
		this.gear = gear;
	}
}
public MountainBike extends Bicycle {
	public light;
	public MountainBike(height, gear, height) {
		super(height, gear);
		this.light = light;
	}
}
```

<b>\# Note</b><br>

---
If a constructor does not explicitly inovke a superclass constuctor, Java compiler automatically inserts a call to the no-argument constructor of the superclass.

And if super class does not have a no-argument constructor, a compile-time error would be thrown.

However `Object` does have such a constructor, so if `Object` is the only superclass, then there is no problem.

---

#### Constructor Chaining

When a super class constructor is invoked, either explicitly or implicitly, a whole chain of constructors get called. Be aware of this when there is a long line of class descent.