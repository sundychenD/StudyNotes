# Chapter 3 Multi-tasking and multi-user OS

Created 13/03/2016

---

"Kernel" manages all the system resources.

##### 3.1.2 Previleges & Security

Certain command and system calls may not be available to normal users directly. For multi-user system, "Super-user" is a previliged user who has the permission to do anything.

E.G. normal user should not be able to control the devices.


##### 3.1.3 Tasks - two-mode operation

Make OS all-powerful and allow no user to access system resouces without going via OS.

Two-mode operation: "previliged mode" for executing OS instructions and "user mode" for working on user programs.

When running user mode a task must ask OS for resources through system calls.

##### 3.1.4 I/O & Memory Protection

Prevent user programs to write to arbitrary address in the memeory. A malicious user may change the address in the interrupt vector to point to a routine of their own making, which would then be executed in previliged mode.

<b>Solution</b>: Let OS define a segment fo memory for each user process. And every address that user program refers to, should be checked by OS. 

When a user attempt to read/write a memory outside of its allowed segment, a "SEGMENTATION FAULT" is generated and control returns to the OS.

Checking is usually hard-wired into the hardware and cannot be switched off.

##### 3.1.5 Time Sharing

Sometimes user program goes into infinite loop so control never returns to OS. We need to make sure OS always remains in control.

Two possiblity

- OS fetch instruction from user program and execute it personally, it never directly give it to the CPU. This is not efficient however sometimes used for making simulators and debuggers.
- Switch off OS while user program executes. A hardware timer is used for switching. 
	- When handling control to a user program, OS uses a hardware timer to ensure that control will return after a certain time.
	- When timer counts down to ZERO it would generate a non-maskable interrupt, whereupon control returns to OS.
	
##### 3.2 Memory Map

Each user program have memory area to work in and a stack to keep track of subroutine calls and local variables.

Each program also have its own I/O sources. However they are virtual I/O stream.

OS arranges things so that the virtual I/O looks just as normal I/O.

##### 3.3 Kernel and shells

<b>UNIX Kernel</b>: The park of OS which handles all the details of sharing and devices.

Kernel can be access through system calls.


<b>Shell</b> A command line interface that wraps the kernel and provide a interface for user to log onto machines and manipulate files.

##### 3.4 Service: Daemons

UNIX kernel is a very large program, however it does not perform all the services required in a OS.

Keep the kernel to a minimum, it only deals with sharing of resources. Other jobs for OS are implemented by writing program which run along side user's programs.

Indeed, they are just "User Programs", the only difference is they are owned by the system.

Usually they are called daemons.


















































