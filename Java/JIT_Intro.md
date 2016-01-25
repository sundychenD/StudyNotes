#### What is JIT?
---
Note: This is only an breif idea about what is JIT in general
there would be no discussion about the detailed working mechanisms or implementation on JVM JIT.

---

###### Into:

<b>JIT</b> Is a compiling approach applied in JVM in order to optimize the interpretation process of translating Java bytecode to machine level instructions.

In general, there are 2 approaches applied to the optimization in order to make the program runs faster. <b>JIT</b> therefore usually describe to a compliler on taking  either or both of the approaches optimizing the interpretation of code. 


###### Approach 1: Avoid Repetitive Interpretation

When JVM is doing interpretation, it go through and translate the code line by line. <br>
For some codes that are repeatly executed, we let the JIT compiler to translate this critical section of code only once and store it in the memory so that whenever we encounter the same portion of bytecode, we just use the converted one.


###### Approach 2: Avoid Compiling "Dead/ Useless" Code.

 E.G.
 
 ```
 Code 1:
 a = 10
 b = 20
 c = a + b
 print(c)
 
 Code 2:
 a = 10
 b = 20
 d = a - b	// Useless computation
 c = a + b
 print(c)
 ```
 
 In "Code 2", the value of `d` is never used in the rest of the program, so why do we need the compute `d`? <br>
 So the Idea here is to let the compiler "avoid" compiling all these dead/useless code before converting the whole program into machine level instructions.
 
 
 
 
 
 
 
 
 
 
 
 
  