#### Javascript Event Loop
---
What is event loop? What is asynchronized calls? What is a call back?


###### Intro

```
console.log("Hi");
setTimeOut(function() {console.log("Woo!")}, 5000);
console.log("There");
```
Output:

```
>>> Hi
>>> There
>>> Woo!
```

Javascript runtime is a single thread runtime environment, which means you cannot have other threads doing different things? So why isn't the output to be:

```
>>> Hi
>>> Woo!
>>> There
```

##### The WebAPI

For functions like `setTimeOut, Ajax`, they are browser apis (<b>Not built in Google V8 Javascript Engine</b>). When they get called in the Javascript runtime, the browser would provide <b>extra threads</b> to run those things. (e.g. setTimeOut). And at the same time, the code that calls the webAPIs would be pushed out of the runtime stack so the other code can continue their execution.


##### The CallBack Stack

```
Runtime:
------
console.log(...)
// Something goes on
------
CallBackQueue: [callbackOne, callbackTwo, callbackThree ...]
```

After browserAPI code finish their execution, they would not directly go back into runtime stack, instead, they would be queue up in the `CallBack Queue` to wait until the runtime stack is all clean. 

After the runtime stack is call clean, they would be pushed to the runtime stack one by one and finish their execution.


##### Browser Rendering

Interestingly, the way the browser render itself works similar to the call back functions.

Every 60ms, the browser re-render (Re-draw) the page once. And when there is something going on in the runtime stack, the rendering would actually stops in the same way as the call back queue. 

```
Runtime:
------
console.log(...)
// Something goes on
------
RenderQueue: [render 577]
CallBackQueue: [callbackOne, callbackTwo, callbackThree ...]
```

The render event would queue up on the `Render Queue` and wait until the runtime stack is clean. Afterwards they would be pushed into the runtime stack so the page can be re-rendered again.

This explains that sometimes when javascript is deadling with heavy computation, the buttons animations are all seems get stucked.