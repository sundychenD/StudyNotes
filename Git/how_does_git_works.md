# How does git works?
Created 12/03/2016

---

### Where does git store my files? How does git changes my visible files when I switch branches?

Basically, they get stored inside `.git/`, normally you don't see it because it's a hidden folder.

### .git/ folder structure
When a `git init` is been entered in a folder, a `.git/` folder is been created in current directory. and inside it, the file structure look like this:

```
├── COMMIT_EDITMSG
├── HEAD
├── branches
├── config
├── description
├── hooks
│   ├── applypatch-msg.sample
│   ├── commit-msg.sample
│   ├── post-update.sample
│   ├── pre-applypatch.sample
│   ├── pre-commit.sample
│   ├── pre-push.sample
│   ├── pre-rebase.sample
│   ├── prepare-commit-msg.sample
│   └── update.sample
├── index
├── info
│   └── exclude
├── logs
│   ├── HEAD
│   └── refs
│       └── heads
│           ├── master
│           └── test
├── objects
│   ├── info
│   └── pack
└── refs
    ├── heads
    │   ├── master
    │   └── test
    └── tags
```
### Object folder

Noticed the objects/ fodler? 

Each time when you `add/commit` something, git would compress your file into a `blob` type file, which is a binary file, and store the file inside `objects/` folder, and the file name would be a customized Hash value. something like this:

```
├── objects
│   ├── 8d
│   │   └── bd58c5d2c5072aee8741ba2381eac6575f3d38
│   ├── e6
│   │   └── 9de29bb2d1d6434b8b29ae775ad8c2e48c5391
│   ├── e8
│   │   └── 7cae30befd2b2558fabbd94c746bacbaf45c88
│   ├── info
│   └── pack
```

Noticed that the name would be something similar in your log hash value
That's right! Commit hash value `8dbd58c5d2c5072aee8741ba2381eac6575f3d38` is exactly the same as the combination of folder `8d/` and it's file inside `bd58c5d2c5072aee8741ba2381eac6575f3d38`

```
commit 8dbd58c5d2c5072aee8741ba2381eac6575f3d38
Author: Chen Di <sundychenya1018@yahoo.com>
Date:   Sat Mar 12 00:42:29 2016 +0800
    Add test.md
```

Now we somehow knows where did my files go, and how they come back. But why I only add one file but 3 files appears.

The tree files corresponding to (Not in sequencial order)

- The file you just added
- The snap shot of current workspace
- The commit ITSELF!

And inside the compressed object of commit, if we decompress it. it would looks similar to the commit log!

```
git cat-file -p 8dbd58c5d2c5072aee8741ba2381eac6575f3d38
>>>
tree e87cae30befd2b2558fabbd94c746bacbaf45c88
author Chen Di <sundychenya1018@yahoo.com> 1457714549 +0800
committer Chen Di <sundychenya1018@yahoo.com> 1457714549 +0800
Add test.md
```

If we decompress object of file, it would be just a binary blob file.

```
100644 blob e69de29bb2d1d6434b8b29ae775ad8c2e48c5391	test.md
```

### HEAD file

What's inside the HEAD file? It's actually a pointer to your current branch.

```
cat HEAD
>>>
ref: refs/heads/master
```

So it points to here:

```
├── logs
│   ├── HEAD
│   └── refs
│       └── heads
│           ├── master
│           └── test
```
and if we print the `master` file it would be the same as our previous commit hash value! So they are actually a pointer that points to our previous commit.

```
cat refs/heads/master
>>>
8dbd58c5d2c5072aee8741ba2381eac6575f3d38
```





