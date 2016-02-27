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
Process 0RequestCS(0) {	wantCS[0] = true;	turn = 1;	while (wantCS[1] == true &&       	   turn == 1) {};}ReleaseCS(0) {	wantCS[0] = false;}Process 1RequestCS(1) {	wantCS[1] = true;	turn = 0;	while (wantCS[0] == true &&       	   turn == 0) {};}ReleaseCS(1) {	wantCS[1] = false;}
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
RequestCS(int myid) {	choosing[myid] = true;	for (int j = 0; j < n; j++) 	    if (number[ j ] > number[myid]) number[myid] = number[ j ];	number[myid]++;	choosing[myid] = false; 
		for (int  j = 0; j < n; j++) {	    while (choosing[ j ] == true); //Wait others to choose	    while (number[ j ] != 0 &&                     Smaller(number[ j ],  j, number[myid], myid));// Wait for smaller numbers	}}
ReleaseCS(int myid) {	number[myid] = 0;}
```

Compare function:

```
boolean Smaller(int number1, int id1, int number2, int id2) {	if (number1 < number 2) return true;	if (number1 == number2) {		if (id1 < id2) return true; else return false;	}	if (number 1 > number2) return false;}
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



