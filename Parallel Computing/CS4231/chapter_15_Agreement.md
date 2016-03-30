# Agreement
Created 22/03/2016

---

**Motivation**

Set of nodes want to agree on something

If no failure, we can use deterministic computation on n values.

#### Node Crash failure
(Synchronous system, channel reliable)

- Synchronous timing model
  - Message delay has a KOWN upper bound x.
  - Node processing delay has a known upper bound y.

  Synchronous timing model  implies the possibility of accurate failure.

**Goal**
- Termination: All nodes (not failed) eventually decide
- Agreement: Decide on same values
- Validity: If initial inputs are same, that value should be the only possible decision value, otherwise not allowed to decide on anything.

**Inter-locked rounds**
(Applied under a inter-locked rounds)

Every process make progress round by round. No one left behind. Message sent during that round is received during that round.

Make all process proceed in inter-locked rounds. In each round:
- Every process send one message to every other process.
- Every process received one message from every other process.
- Every process do some local computation

**Implementation**

Each process starts a timer at beginning of a round, (t1, t2, t3) corresponding to (send, propagation, process) time. Therefore the length of each round is t1+t2+t3.

If we have a process whose clock is twice as faster as others, we set the round time to be 2(t1+t2+t3). so everyone else can wait for that process.

Considering send & propagation delay, we set round time to be 2(t1+t2+t3)+t1+t2

#### Link failures

- Node do not fail
- Communication channels may fail
- Synchronous time model, message delay & processing delay are known. And upper bounded

#### Randomized Algorithm

- We have a fix round `r`, two processes P1 & P2;
- P1 picks a random integer from [1, r] as `bar`;
- P1 P2 maintains a level variable L1 & L2, differs at most by 1;
- Message contains Level, bar, input
- When L2 is received, L1 = L2 + 1; When L1 is received L2 = L1 + 1;

**P1**

P1 decide on 1 iff
  - P1 sees both P1 P2 inputs are 1 and
  - L1 >= bar

P2 decide on 0 if it does not see P2's input

**P2**

P2 decide on 1 iff
  - P2 sees both P1 P2 inputs are 1 and
  - P2 sees bar and
  - L2 >= bar

P2 decide on 0 iff it does not see P1's input or does not see the bar

**Error occurs when one decide on 0 one decide on 1**

Case 1: **P1 - 1; P2 - 0**

P1: I see P2's input
P2: I don't see P1's input or I don't see the bar

Here P2 receives no message, therefore L2 = 0 & L1 = 1

L1 >= bar && L2 < bar

1 >= bar && 0 < bar

error occurs when bar = 1

Case 2: **P1 - 0; P2 - 1**

P1: I don't see P2's input
P2: I see P1's input and bar

Here P1 receives no message, therefore L1 = 0 & L2 = 1

Error occurs when bar = 1

Case 3: **P1 - 1; P2 - 0 or P1 - 0; P2 - 1**

P1: I see P2's input
P2: I see P1's input and bar

Let Lmax = max(L1, L2)
since one of P1 P2 decide on 0;
  - (L1 < bar L2 >= bar) or
  - (L1 >= bar L2 < bar)

Error occurs when bar = Lmax

Therefore the possibility of having an error is when 1/r (We assume that each time the L1 & L2 is been decided, due to channel lost, the only chance of having a error is when we choose our r to be max(L1, L2), which have the chance of 1/r)
