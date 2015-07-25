Python3 Study Note -- Magic Interface

Python defines interfaces that allows user to create objects that utilize <b>sytactic sugar</b>

e.g.

class Link:
	def __len__(self):
	...

	def __getitem__(self):	
	...

	def __repr__(self):
	...

	def __str__(self):
	...

link = Link(1, Link(2))
>> len(link) 	# use len
2

>> link[1]		# use getitem
1

>> link 		# use repr
Link(1, Link(2))

>> print(link)	# use str
<1, 2>