(Study Notes of CS162 UC Berkeley)

System Calls

Controlled entry into kernel
	― To well-known location
	― Like every entry save registers
	― Extract arguments out of registers + user memory

+ Dual Mode Operation
  	Hardware provides at least two modes: 
	― "Kernel" (or "supervisor" or "protected")
		● Unix "kernel" runs here (part of OS running all the time)
	
	― "User" mode
		● Normal programs run here
		● Even if "administrator" or "superuser" or "sudo" (Those are not kernel mode!!! Thats just previliged user mode! Have some privilige on filesystem)
	Some operations prohibited in user mode ― e.g. changing the page table pointer


+ POSIX process APIs:
	― fork – copy current into new address space
		● copy-on-write
	― wait – wait for forked process
	― exec – replace current with program on disk 
		● completely new address space
		● inherit file descriptors


+ POSIX IO APIs
	- Low-level (buffered only in kernel space) 
		― open
		― read 
		― write 
		― close
		
	- High-level (buffered in userspace, too) 
		― fopen,
		― fread, fgetc, fgets 
		― fwrite, fputs, fprintf 
		― fclos


+ POSIX IO: Everything is a file
	Uniform interface for
		― Devices (terminals, printers, etc.)
		― Regular files on disk
		― Networking (sockets)
		― Local interprocess communication (pipes, sockets)
	
	Part of the process state
		― accessed with file descriptors