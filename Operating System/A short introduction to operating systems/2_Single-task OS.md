# Single-Task OS

Created 12/03/2016

---

##### 2.1 Memory Map & Register

Memory is a large string of bytes starting with address 0 and increasing up to the maximum address.

No all the memory is available to the user of the machine. Some of it is requried for the operation of the CPU

- <b>Zero Page</b>: First page of the memory reserved for special purpose.
- <b>Stack</b>: For executing subroutines.
- <b>User Programs</b>: Space the user program can 'grow into'
- <b>Screen memory</b>: Memory to store every 'point' or 'unit' on the screen. Might be byte per character or 4 bytes per pixel.
- <b>Memory mapped I/O</b>: Dics controllers contain smaller microprocessors of their own. CPU give them instructions by placing numbers into their register.
- <b>Operating system</b>: OS itself is a large program which often takes up a large part of the available memory.


##### 2.2 Stack

CPU store the current position within a program before jumb into subroutines. Stack frames can be placed on top of the old ones.

Example see stack.c

##### 2.3.1 Interrupts

Interrupts could be hardware triggered signals which causes CPU to stop what it is doing and jump to special subroutine. 

E.G. user presses a key, disc device has fetched data from the disk. 

They can also be generated in software by errors like "division by zero" or "illegal memory address".

When the CPU receives an interrupt, it SAVES the content of its register on the hardware stack and jumps to specal routine which will determin the cause of the inteerrupt and respond to it appropriately.

<b>Interrupt Vectors</b>
It's a region of memory reserved by the hardware for servicing of interrupts.

Each interrupt has a number from 0 to the max number of interrupt types supported on the CPU.

The vector contains the address of the routine which to be executed when interrupt occurs.


##### 2.3.3 Synchronous and Synchronous I/O

To start I/O, CPU writes special values into the registers of device controller.

Device controller would then act on the written value. After it fetch data from the disc, it would place the data in its local buffer, then signal teh CPU by generating an interrupt.

<b>Synchronous</b>: Wait until I'O completes.

<b>Asynchronous</b>: Do other things until the completion interrupt arrives.


##### 2.3.4 Direct Memory Access

DMA controller copies blocks of data at a time without the intervention of the CPU. Once given the info on what and where to copy the data, DMA would not signal until it completes the transfer.

Without DMA, CPU may have to copy the dat one register-full at a time, using up hundres of interrupt and causing a halt to the machine.

















