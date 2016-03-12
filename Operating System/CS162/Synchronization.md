(Study Notes of CS162 UC Berkeley)

Synchronization

+ Synchronization
	Multiple (Virutual) CPUs -> Things can happen "at the same time"

	- Abstractions:
		- Monitors - Lock + Condition Variable
		- Semaphores
		- Locks


		- Monitor Example: Queue

		Lock lock;
		Condition dataready;
		Queue queue;

		AddToQueue(item) {
			lock.Acquire(); // Get Lock queue.enqueue(item); // Add item dataready.signal(); // Signal a waiter, if any lock.Release(); // Release Lock
		}
		RemoveFromQueue() {
			lock.Acquire(); // Get Lock
			while (queue.isEmpty()) {
				dataready.wait(&lock); // If nothing, sleep
			} 
			item = queue.dequeue(); // Get next item lock.Release(); // Release Lock return(item);
		}


+ DeadLock
	
	- DeadLock Example

		Deadlock
		AllocateOrWait(1MB) /* 1 MB free */
							AllocateOrWait(1MB)
		― WAITS FOREVER
		AllocateOrWait(1MB) /* 0 MB free */
							AllocateOrWait(1MB)
							― WAITS FOREVER
	- DeadLock Four Requirements
		Mutual exclusion
		― One thread at a time can use a resource Hold and wait
		
		― Thread holding a resource waits to acquire another resource No preemption
		
		― Resources are released voluntarily – threads can't steal instead of waiting Circular wait:
		
		― There exists a set {T1, ..., Tn} of waiting threads 
		● T1 is waiting for a resource that is held by T2
		● T2 is waiting for a resource that is held by T3
		●...
		● Tn is waiting for a resource that is held by T1


