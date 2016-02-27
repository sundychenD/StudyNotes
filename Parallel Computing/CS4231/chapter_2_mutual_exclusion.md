# Chapter 2 Mutual Exclusion
<meta> Created 24/02/2016 </meta>

---

##### To Ensure mutual exclusion

- Mutual exclusion
	No more than one process in critical section
	
- Progress
	If one or more process wants to enter and no one is in critical section, one of then can enter critical section

- No Starvation
	If a process wants to enter, it eventually can always enter
	- Need to consider worst-case schedule??????
	
	
##### Peterson's Algorithm

```
Shared bool wantCS[0] = false, bool wantCS[1] =  false, int turn = 0;
Process 0
```

- Prove Mutual Exclusion
	
	Case: Turn = 0
	- If both in CS
	- Then P0 executed "turn = 1" before P1 execute "turn = 0"
	- And wantCS[0] = false as seen by P1
	- However wantCS[0] is set to true by P0 when executed "turn = 1"
	
	
	Case: Turn = 1
	- Symmetric...
	
- Prove Progress

	- If both blocked.
	- If turn = 0, then P0 can enter;
	- If turn = 1, then p1 can enter;
	
- Prove No Starvation

	If P0 waiting:
	
	- then wantCS[1] = true and turn = 1
	- P1 in CS, eventually would exit and set wantCS[1] to false	
	- If P1 acquire again, then it would be block as wantCS[0] = true and turn = 0
	- P0 can then enter
	
	
	
	
##### Lamport's Bakery Alg

Designed for n process

```
RequestCS(int myid) {


```

Compare function:

```
boolean Smaller(int number1, int id1, int number2, int id2) {
```



##### Problems:
// P29 2.5:

k mutual exclusion using bakery

```
initial EMPYT_SLOTS = k

requireLock(id)
	while(canNotEnter[i]) {
		bakeryRequire(id)
			if (EMPTY_SLOTS > 0) {
				canNotEnter[i] = false;
				EMPTY_SLOTS --;
			}
		bakeryRelease(id)
	}

releaseLock(id) {
	EMPTY_SLOTS ++;
	canNotEnter[i] = true;
}
```


