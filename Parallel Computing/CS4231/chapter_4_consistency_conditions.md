#### Consistency Conditions
<meta>Created 25/02/2015</meta>

---

## Informal Definition
The result is the same as if the operation of all processors were executed in some sequential order, and the operation of each indivisdual processor appear in this sequence in the order specified by the program.


## Some Definitions
#### Operation:
A `single invocation/response` pair of a single method of a single shared object by a process.

- Let `e` being a operation
- proc(e): The invoking process
- obj(e): The object
- inv(e): Invocation `event` (Start Time)
- resp(e): Reply `event`(Finish Time)


#### History:

A sequence of invocations and responses ordered by wall clock time.


#### Sequencial History:

Any Invocation is always immediately `followed by its response`

- No Interleaving, other wise called concurrents


#### Legal Sequencial History:

All responses satisfies the "sequential semantics" of the data type.

"Sequential semantics": Semantics result of a `single process` accessing the datatype


#### Equivalent History:

Two histories are equivalent if they have the exactly same set of events => All responses are the same, orders maybe different.

#### Process Order:

Order of event within one process


#### Sequential Consistency:

A history H is sequentially consistent if it is equivalent to some `legal sequential history S` the preserves process order.


#### External ordering

For all the processes, external order: "P1-o1 < P2-o2" (Ordering between 2 process, if they have)
Means: o1 response occur before o2 invocation

#### Local Property

Linearizability is a local property in the sense that H is linearizable if and only if for any object x, H | x is linearizable  `(H | x: All the event on object x)`Sequential consistency is not a local property

#### Regular Register
regular if- When a read  does not overlap with any write, the read returns the value written by one of the most recent writes (Return any one of the three in the purple section)
- When a read overlaps with one or more writes, the read returns the value written by one of the most recent writes or the value written by one of the overlapping writes


#### Safe Register

safe if the implementation always ensures that 
- When a read does not overlap with any write, then it returns the value written by one of the most recent writes
- When a read overlaps with one or more writes, it can return anything
