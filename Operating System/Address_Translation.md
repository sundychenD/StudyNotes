(Study Notes of CS162 UC Berkeley)

Address Translation

+ Address Translation Comparison

	- Segmentation	
		Advantages: 
			Fast context switching:	Segment mapping maintained by CPU
		
		Disadvantages:
			External fragmentation

	- Paging (single- level page)
		Advantages:
			No external fragmentation, fast easy allocation
		
		Disadvantages:
			Large table size ~ virtual memory
			Internal fragmentation
	
	- Paged segmentation / Two(+)-level pages
		Advantages:
			Table size ~ # of pages in virtual memory, fast + easy allocation
		
		Disadvantages:	
			Multiple memory references per page access
	
	- Inverted Table
		Advantages:
			Table size ~ # of pages in physical memory

		Disadvantages:
			Hash function more complex