# Process and Thread

created 14/03/2016

---

#### 4.1.6 Interprocess Communication

One benefit from multi-tasking is processes can cooperate. In order to achieve this, the following must be donw:

- <b>Communication</b>: Interprcess communication (IPC) involes sending information from one process to another.
  - It can be achieved using a 'MailBox' system, a socket which behaves like a virtual commnication network.
  - Or through the use of 'pipes'. They are system construction which enables one process to open another process if it were a file for writing or reading.

- <b>Share data</b>: A segment of memory available to both processes.
- <b>Waiting</b>: Some process wait for another process to give a signal before continuing. (Synchronization).


#### 4.2.1 Creating processes

Information needed for creating a process.

1. Name: Name of the program which is to run as the new process
2. Process ID and Process Control Block: the system must create a new PCB, or locates an unused block in an array. This block would follow the execution of the program through its course and keeping track of its resources and priority.
	- PCB: Used by OS to manage the process. Information usually includes

		- The process scheduling state, e.g. in terms of "ready", "suspended", etc.
		- Process structuring information: process's children id's, or the id's of other processes related to the current one in some functional way, which may be represented as a queue, a ring or other data structures.
		- Interprocess communication information: various flags, signals and messages associated with the communication among independent processes may be stored in the PCB.
		- Process privileges, in terms of allowed/disallowed access to system resources.
		- Process state: State may enter into new, ready, running, waiting, dead depending on CPU scheduling.
		- Process No: a unique identification number for each process in the operating system.
		- Program counter: a pointer to the address of the next instruction to be executed for this process.
		- CPU registers: indicates various register set of CPU where process need to be stored for execution for running state.
		- CPU scheduling information: indicates the information of a process with which it uses the CPU time through scheduling.
		- Memory management information: includes the information of page table, memory limits, Segment table depending on memory used by the operating system.
		- Accounting information: includes the amount of CPU used for process execution, time limits, execution ID etc.
		- IO status information: includes a list of I/O devices allocated to the process.

3. Locate the program to be executed on the disk and allocate memory for the code segment in RAM.
4. Load the program into code segment and initialize registers of the PCB.
5. Priority.
6. Schedule it for execution.


#### 4.3.3 Levels of threads

Two levels at which threads operate:
- System threads
- User level threads

A kernel level thread behaves like a virtual CPU, or a powerpoint to which user-processes can connet in order to get computing power.


#### Dual mode operation

In dual mode operation, `Previleged` operations in kernel. `Non-previliged` operations in user mode

Events Causing mode switches
- System Calls (issued by user process to request system service)
- Exceptions (Illegal instruction)
- Interrupts (From devices)


#### Interrupt

<b>x86 interrupt view</b>

```python
while(fetch next instruction) {
	run instruction;
	if (there is an interupt) {
		switch to kernel stack if necessary; (Cannot trust user stack)
		save CPU context and error code if any;
		find OS-provided interrupt handler (from handler table);
		jump to handler
		restore CPU context when handler returns;
	}
}
```

#### System Call

User precess cannot perform previleged operations themselves, therefore must request OS to do so on their behalf by issuing system calls

OS must validate system call parameters

<b>System call dispatch</b>
Assign each system call a system call number.

Intialize a system call table.

User process setup system call number and arguments

User process run `int X`

Switch to kernel mode and invoke kernel's interrupt handler for X (interrupt dispatch)

Kernel looks up syscall table using system call number, execute corresponding function

Kenel returns by running iret (interrupt return)
