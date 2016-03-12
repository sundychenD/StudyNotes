# What is an OS
Created 12/03/2016

---

##### 1.2.4 Interrupts

Hardware signals which are sent to the CPU by the devices it is connected to. They interrupt the CPU from what it is doing and demand that it spend a few colock cycles servicing a request.

Interrupts have `levels`, high level interrupt can interrupt low level interrupt.

Programs can choose whether they wish to be interrupted by setting an `interrupt mask` which mask out the interrupt it does not want to hear about. It could be dangerous thought, since data can be lost. therefore all systems have NON-MASKABLE interrupts for the most crucial operations.

##### 1.3.3 System calls

They are black-box functions for most frequently needed operations so user don't waste time writing low level code.

##### 1.3.5 File System

###### File Type

Rather than using file extensions to distinguish files, which could be abused by user, OS can introduce a protocol/standard format for executable files. Each time before file execution it first checks if the file obeys the protocol.

###### Links

Allow same file to appear in several places at one time. 

A link is NOT a copy of a file but a pointer to where a file really is.




























