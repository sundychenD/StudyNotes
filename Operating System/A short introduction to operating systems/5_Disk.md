# Disk

#### 5.3 Disks

Hard disk is an device thus OS must use a device controller to talk to it.

A device controller is a microprocessors with small decision making computers of their own.

On intelligent drives, the disk keeps a `defect list` which contains a list of bad sectors. The list would keep updating as the disk been used.

#### 5.3.5 Partitions

Partition is a group of cylinders which lie next to each other. Thus allow us to divide up the storage of data to special areas.

In order to use partition,  we need to create a file system on it. Which involves reserving space for OS and suitable markers for  navigating over the surface of the disk.

Partition can overlap however filesystem **CANNOT**, otherwise they will destroy each other.

#### 5.4 filesystem

File system is a interface to the disk. It's said to be created on a disk by running a special program, usually referred as `formatting`.

Popular filesystem interface is hierachical one.

**links** are pointers to other files. A link is not a copy of a file but a alias for the true route to the file through the hierachical system.

**File** Contains the file name/path and a pointer to the filesystem inode.

**Hard Links** A pointer points to the actual filesystem inode.

**Symbolic Link** is a small file which contains the name/path of the true file. We can create a symbolic link to a non-existing file, or delete the file to which a symbolic link points.

#### 5.4.2 File types and device nodes

MS-DOS use filename extension to mark file types.

UNIX does not make particular distinction on the basis of filename. It keeps a flag to say whether a file is executable or not.

Some files in UNIX are not real files but a `handle` to devices, usually called device nodes. They are a way to `into` a device through a filesystem interface.

#### 5.4.3 Permission and access

Each file has one `owner` and belongs to one group. The owner of the file is the only one who can decide whether others can read or write to the file and to which group it belongs.

When a file is created by a given user, that user is automatically the owner of the file. Different OS has their distinctive mechanism on deciding the list of users that are able to access the file.
