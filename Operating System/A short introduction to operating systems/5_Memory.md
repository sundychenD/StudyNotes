# Memory & Storage
Created 24/03/2016

---

#### 5.1.1 Physical Address space

Not every address is wired up to a memory chip. Some addresses may reserved for

- Memory Mapped I/O - Individual registers belonging to other chips and hardware devices.

- Interrupt vector - CPU itself requires some work space, including interrupt vector and processor stack

- OS itself. It usually takes a fair chunk of memory, on microcomputers its in ROM, on multiuser systems are loaded from disk into RAM.

**Physical address space** consist of every possible address to which memory on chips are connected.


#### 5.1.2 Word size

The size of a work on any system is defined by the size of the registers in the CPU. E.G. CPU using 1 byte registers can manipulate no more than one byte at a time.

#### 5.1.4 Address binding

We introduce a distinction between logical and physical addresses. A user program write to only "logical address", not knowing where the program will end up in the physical address space. The address would when converted to physical addresses automatically.

Instead of converting addresses during the program loading time, we make the conversion when the program is been executed (at runtime), where we can reorganize the use of physical memory `dynamically` at any time.

#### 5.1.5 Shared library

On old system, During the compile time, the `linker` attaches a whole copy of standard libraries to each program. It makes a simple "Hello World" program to have thousands of kb's long on the disc.

The solution is to use `runtime linker`. When the shared library is been loaded into RAM when one of its functions is needed.

Advantages:

- Save disc space. Only one copy of the shared library on the disc.

- Save RAM. Since library in the RAM can be shared by several programs.

Disadvanatge:

- Performance penalty occurring at loading time to run time. The first time a function is accessed, the library must be loaded from disc during execution. However it could be outweighed in the long run as it would other wise loaded by programs n time by each program.

![Fig5.2](images/Chpt_5/Fig 5.2.png)

#### 5.1.6 Page

Quantize the logical memory into smallish pieces, usually 2-4kb big, called **pages**, which would be mapped to the exact same size of physical memory, called **frame**.

#### 5.1.8 malloc() function

Malloc obtains `logical` memory for the caller, the acquisition of physical memory is taken care or by the system on behalf on malloc, by deeper level kernel commands.

#### 5.1.9 Fragmentation

**Internal Fragmentation**: Wasted by malloc in trying to fit data into logical memory segment.

**External Fragmentation**: Having holes between segments in physical memory.

`External Fragmentation` is eliminated by the `page` concept.

`Internal fragmentation` can be minimized by choosing a smaller page size for the system. So on average fewer bytes will be wasted per page. However, we ended up with more pages.

#### 5.2 Virtual memory

Free up RAM by putting idle memory on to disc.

User program is not aware of the swapping!

When a physical frame is been swapped out, a flag is been set on to the corresponding logical page. And a process attempts to read from that page of logical memory, the existence of flag would cause a page fault, which is an interrupt that would be handled by OS. OS would then load the missing page back to a free frame and rebind it to the logical page table. And when control returns to the waiting process, the missing page would automatically restored as if it had never been gone.

#### 5.2.4 Thrashing

System get into a state where there are so many processes competing for limited resources that it spends more time servicing page faults and swapping in and out processes than it does executing the processes.

To recover from thrashing is to suspend processes and forbid new ones.
