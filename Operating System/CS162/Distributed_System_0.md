Distributed System (Intro)

Intro

	When we talks about distributed system, we may confused this phrase with another system structure -- Parallel System. To make it clear, I'd like to emphasize that we are actually talking about "Distributed System" here, not the other one.

	So what is the difference between these two? 

	Well, they seems to be alike, as they both run on multiple machines etc. However,since we are not going to dive into the concept of "Parallel System", I'll just briefly list some significant differences between these two system structure, for your interests only.

	Distributed System
		- Always refers to difference machines responsible for different parts of task.

		- Usually no centralized state.

		- Usually about different responsibilities or redundance.

	Parallel System
		- Emphasizing on different parts of same task performed on different machines

		- The purpose of using this structure is usually about enhancing performance


Why we use Distributed System?

	- Simple, cheaper components
		Instead of building an computer with 100 cores, we just get 50 dual-core computers.

	- Easy to add to incrementally
		Want expand the system? Buy more computers!

	- Let multiple users cooperate (maybe)
		― Physical components owned by different users
		
		― Enable collaboration between diverse users

