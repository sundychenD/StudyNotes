#### Chapter 3 Synchronization Primitives
---
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