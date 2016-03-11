# Chapter 12 Message Ordering
Created 11/03/2016

---

#### Causal Ordering

If s1 happened before s2, and r1 and r2 are on the same process, the r1 must before r2.


#### Ensure Causal Order

- Let each process maintain a N x N matrix M.



- M[i, j] # of messages sent from i to j, as known by process i.



- If i send a message to j, M[i, j] ++, and send M with the message



- When received, accept message only when
	- M[k, j] 		>= T[k, j]
	- M[i, j] + 1 	 = T[i, j]
	- Other wise delay.
	
	
#### Causal Order for broadcast

With the previous causal order protocol been enforced.

Let each process maintain a message log for all message delivered.

When sending a message, append the message to log and send the whole log

Upon receiving a log, scan the log sequentially, for any message not seen, append the message to local log and deliver it.

#### Total Ordering
All message delivered to all processes in exactly the same order.

 - Also called atomic broadcast.
 
Total ordering does not imply causal ordering.

 - E.G.
 - Let A send S1, S2 to all other process, and have then all been delivered as S2, S1. Total ordering here is been maintained but violate causal ordering.
 
#### Usage: Replicated State Machine

- e.g. Database

- Multiple copies of the same state machine for performance/availability

- Each state machines must execute instructions in exactly same order.


#### Coordinator for Total Order Broadcast

Let a process to be the coordinator, every other process would send their messages to coordinator and let it broadcast.

Coordinator assign a sequence number to each message.

Message delivered according to sequence number order.

- Problem
 - Coordinator is the bottleneck
 - Coordinator can fail


#### Skeen's algorithm for total order broadcast

Each process maintains a Logical lock and a message buffer for undelivered messages.

Deliver/remove a message if
 - All messages in buffer have been assigned numbers
 - The message has the smallest number
 
 ![alt Skeens algo](images/SkeensAlgo.png =400x200)

	
	
	
	
	
	
