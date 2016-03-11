# Global Snapshot

Created 29/02/2016

---

## Some Definition

- #### Global Snapshot
	
	A set of event such that if e2 is in the set and e1 is before e2 in process order, then e1 must be in the set.

- #### Consistent Global Snapshot

	A global snap shot such that if e1 is in the set and e1 is before e2 in send-receive order, then e1 must be in the set.

## Capture a Consistent Global Snapshot


- #### Communication model

	- No message loss
	- Communication channels are `unidirectional`
	- FIFO delivery on each channel
	
- #### FIFO

	- Each process maintains a message number counter for each channel and stamps each message sent	- Receiver will only deliver messages in order


