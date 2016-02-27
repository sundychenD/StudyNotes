# Java Thread
Created 27/02/2016

---

### Thread vs Runnable

Two ways to create customize thread

1. By Implement Interface Runnable

```
public class MyRunnable implements Runnable {
    public void run() {
        //Code
    }
}

public static void main(String[] args) {
	Thread myThread = new MyThread(new MyRunnable(), "thread name");
	myThread.start();
}
```

2. By Inherit From Thread

```
public class MyThread extends Thread {
    public MyThread() {
        super("MyThread");
    }
    public void run() {
        //Code
    }
}

public static void main(String[] args) {
	Thread myThread = new MyThread()
	myThread.start();
}
```


`Thread` is a class, use it only when we need to override thread behaviors.
Other wise use `Runnable`, which only changes what a thread's work is.


### Multiple Threads

To have a fixed pool of threads, use 

```
private static void multiThreadPool() { 	
	// Get a pool of 10 threads.
	ExecutorService threadPool = Executors.newFixedThreadPool(10);
	// Execute a runnable 1000 times.
   	for (int i = 0; i < 1000; i++) {
		threadPool.execute(new MyRunnable());
	}
}
```

