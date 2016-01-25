#### Javascript Event Delegation
---
Src: [EventDelegation](http://javascript.info/tutorial/event-delegation)

1. Senario:
	- We have a table with 100 * 100 cells, and we want to perform some actions (e.g. high light the cell) when the cell is been clicked, how to we achieve this interaction? <br><br>
	

	One of the most straight forward way of doing it is to add the event handler for each cell. However the down side is that we need 100 * 100 handler assigned to each cell, which may result in a performance issue with the page.<br>
	

	Here is when event delegation comes in. For most of the event occured, it would "`bubble up`" to it's parent element and eventually reach "dom" level. So we take the advantage of the "`bubble up`" and add the event handler to the main parent element.
	
	For instance, the parent element is `Table`, so we only need to add one handler to the table element:
	
	```
	table.onclick = function (event) {
		// get the event
		event = event || window.event
		// Find out what's the origin of the event
		var target = event.target || event.srcElement
		// Do something about the event.
	}		
	```
	
	By doing so, we elimite the number of handler to be applied to the element and make the page less memeory consuming. Besides 
	
	It's also a good way to apply action to dinamically changed contents. (e.g. new elements added by Ajax or Jquery)