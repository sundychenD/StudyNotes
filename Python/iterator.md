Python3 Study Notes -- Iterator

Iterator is an object that provide the next element in a sequence.
Its "__next__" method returns the next element

The build in "next" function invokes the __next__ method on its argument.
If there is no next element, __next__ method stops and raise an "StopIteration" exception

=== e.g.
# "iter" invokes __iter__ on its argument, __iter__ returns a iterator
range_iterator = iter(range(1, 2)) 
>> next(range_iterator)
1

>> next(range_iterator)
StopIteration

In the example above, we use "range" function. "range" creates an implicit sequence of numbers, using lazy-evaluation. Python does not calculate the entire sequence immediately, it would calculate on demand, which in other words, on when the function is called, python would calculate the next number in the sequence. (By using lazy evalutation, it allows range to use O(1) space)

+ Iterables:
	- Object that represents a sequence
	- "__iter__" returns a new iterator

+ Iterator:
	- Object that tracks its current position in a position
	- "__next__" method advance position, return the next element
	- "__iter__" method returns itself
	- CANNOT be reset

+ Compare Iterator and Iterable:
	
	# Range is an iterable. 
	class Range:
		def __init__(self, stop):
			self.stop = stop
		def __iter__(self):
			return range_iterator(self.stop)

	# Range_Iterator is an iterator.
	class Range_Iterator:
		def __init__(self, stop):
			self.stop = stop
			self.cur = 0
		def __iter__(self):
			return self
		def __next__(self):
			if self.cur >= self.stop:
				raise StopIteration
			elem = self.cur
			self.cur += 1
			return elem


+ "for" statement:
	- The "for" statement iterates through a iterable object.
	======
	for <name> in <expression>:
		<suit>
	======
	- the <expression> must be evaluated to an iterable object.
	- For each element in that sequence, bind the <name> to it in each local frame
	- Then Execute <suite>

+ Generator:
	- A generator creates an generator object, which is a type of iterator.
	- Whats special about generator function (object)?
		generator function can yield multiple values

		=== e.g.
		def letter_generator(letter, end):
			while letter < end:
				yield letter
				letter = chr(ord(letter) + 1)

		>> letters = letter_generator('a', 'z')
		>> next(letters)
		'a'
		>> next(letters)
		'b'


+ Generator Examples:

	class ScaleIterator:
	    """An iterator the scales elements of the iterable s by a number k.

	    >>> s = ScaleIterator([1, 5, 2], 5)
	    >>> list(s)
	    [5, 25, 10]

	    >>> m = ScaleIterator(naturals(), 2)
	    >>> [next(m) for _ in range(5)]
	    [2, 4, 6, 8, 10]
	    """
	    def __init__(self, s, k):
	        "*** YOUR CODE HERE ***"
	        self.iterable = iter(s)
	        self.scale = k

	    def __iter__(self):
	        return self

	    def __next__(self):
	        "*** YOUR CODE HERE ***"
	        return (next(self.iterable) * self.scale)


	def scale(s, k):
	    """Yield elements of the iterable s scaled by a number k.

	    >>> s = scale([1, 5, 2], 5)
	    >>> type(s)
	    <class 'generator'>
	    >>> list(s)
	    [5, 25, 10]

	    >>> m = scale(naturals(), 2)
	    >>> [next(m) for _ in range(5)]
	    [2, 4, 6, 8, 10]
	    """
	    "*** YOUR CODE HERE ***"
	    iterator = iter(s)
	    while True:
	        yield next(iterator) * k


	def merge(s0, s1):
	    """Yield the elements of strictly increasing iterables s0 and s1, removing
	    repeats. Assume that s0 and s1 have no repeats. You can also assume that s0
	    and s1 represent infinite sequences.

	    >>> twos = scale(naturals(), 2)
	    >>> threes = scale(naturals(), 3)
	    >>> m = merge(twos, threes)
	    >>> type(m)
	    <class 'generator'>
	    >>> [next(m) for _ in range(10)]
	    [2, 3, 4, 6, 8, 9, 10, 12, 14, 15]
	    """
	    i0, i1 = iter(s0), iter(s1)
	    e0, e1 = next(i0), next(i1)
	    "*** YOUR CODE HERE ***"
	    while True:
	        if e0 < e1:
	            yield e0
	            e0 = next(i0)

	        elif e0 == e1:
	            yield e1
	            e0 = next(i0)
	            e1 = next(i1)
	            
	        elif e0 > e1:
	            yield e1
	            e1 = next(i1)

+ Mind blow
	What sequence is this?

	def mistery:
		yield 1
		for i in mistery():
			yield i + 1

	answer: 1, 2, 3, 4 ..... Its a natural number series.
