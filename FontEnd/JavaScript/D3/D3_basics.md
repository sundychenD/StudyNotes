# D3.js Basics
Created 19 March 2016

---

### \# selection.enter()

Returns the enter selection: placeholder nodes for each data element for which no corresponding existing DOM element was found in the current selection. 

This method is only defined on the update selection, which is returned by the data operator. 

In addition, the enter selection only defines the append, insert, select and call operators; 

##### Example:

As a simple example, consider the case where the existing selection is empty, and we wish to create new nodes to match our data:


```
d3.select("body").selectAll("div")
    .data([4, 8, 15, 16, 23, 42])
  .enter().append("div")
    .text(function(d) { return d; });
```

Assuming that the body is initially empty, the above code will create six new DIV elements, append them to the body in order, and assign their text content as the associated (string-coerced) number:

```
\<div>4\</div>
\<div>8\</div>
\<div>15\</div>
\<div>16\</div>
\<div>23\</div>
\<div>42\</div>

```