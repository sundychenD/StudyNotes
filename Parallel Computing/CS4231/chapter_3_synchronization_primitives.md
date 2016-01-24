#### Chapter 3 Synchronization Primitives
---
#### Why Synchronization Primitives?
- No busy wait.
	- CPU spinning but do nothing
	- e.g. while(some_condition) {};


#### Semaphores
```
P() {	// Executed atomically, interrupt disabled
	if (value == false) {
		Add myself to queue;
		Block;
	}
	value = false;	// Actually the lock
}

V() {	// Executed atomically, interrupt disabled
	value = true;
	if (queue not empty) {
		wake up arbitrary process on the queue
	}
}
```

#### Monitors

Use Java as example:


1). Within the "synchronized" section, only one process/thread is allowed to operate.

``` 
synchronized (object) {
	
	// Block my self and put myself on the waiting queue
	
	object.wait();
	
	
	// If queue is not empty, pick arbitrary one from the queue
	// and unblock it.
	
	object.notify();
	
	
	// If queue is not empty, unblock all the process in the queue
	
	object.notifyAll();
}
``` 

2). Hoare-style Monitor:

- process 0 takes over the execution

``` 
	Process 0									Process 1
	
synchronized (object) {	if (x != 1)		object.wait();
										synchronized (object) {											x=1;											object.notify();
		assert(x==1); // x must be 1	x++; }										// x may no longer be 1 here;										}
```

3). Mesa Style (Java Style)

- process 1 continue execute until end
- After P0 returns from wait, it may not acquire the lock immediately. In other words, other thread may sneak in and change the value of x.
- Therefore "while" is used for condition variable, if the value of x get changed, P0 would go back to sleep/block again.

``` 
	Process 0									Process 1
	
synchronized (object) {	while (x != 1)	// Make sure x is 1		object.wait();
										synchronized (object) {											x=1;											object.notify();
											// x may no longer be 1 here;										}
		assert(x==1);	x++; }										
```

4). Nested monitors

This one would cause deadlock.


```
synchronized (ObjA) { 	synchronized (ObjB) {		// Here Java only releases the monitor lock on ObjB 		// and not the monitor lock on ObjA.
		ObjB.wait(); 	}}synchronized (ObjA) { 	synchronized (ObjB) {
		// Hence this piece of code will block 
		// and will not reach ObjB.notify() – deadlock!
				ObjB.notify();	}}
```










