<p>
  Write a <span>DoublyLinkedList</span> class that has a <span>head</span> and a
  <span>tail</span>, both of which point to either a linked list
  <span>Node</span> or <span>None</span> / <span>null</span>. The class should
  support:
</p>
<ul>
  <li>
    Setting the head and tail of the linked list.
  </li>
  <li>
    Inserting nodes before and after other nodes as well as at given positions
    (the position of the head node is <span>1</span>).
  </li>
  <li>Removing given nodes and removing nodes with given values.</li>
  <li>Searching for nodes with given values.</li>
</ul>
<p>
  Note that the <span>setHead</span>, <span>setTail</span>,
  <span>insertBefore</span>, <span>insertAfter</span>,
  <span>insertAtPosition</span>, and <span>remove</span> methods all take in
  actual <span>Node</span>s as input parameters—not integers (except for
  <span>insertAtPosition</span>, which also takes in an integer representing the
  position); this means that you don't need to create any new <span>Node</span>s
  in these methods. The input nodes can be either stand-alone nodes or nodes
  that are already in the linked list. If they're nodes that are already in the
  linked list, the methods will effectively be <i>moving</i> the nodes within
  the linked list. You won't be told if the input nodes are already in the
  linked list, so your code will have to defensively handle this scenario.
</p>
<p>
  If you're doing this problem in an untyped language like Python or JavaScript,
  you may want to look at the various function signatures in a typed language
  like Java or TypeScript to get a better idea of what each input parameter is.
</p>
<p>
  Each <span>Node</span> has an integer <span>value</span> as well as a
  <span>prev</span> node and a <span>next</span> node, both of which can point
  to either another node or <span>None</span> / <span>null</span>.
</p>
<h3>Sample Usage</h3>
<pre><span class="CodeEditor-promptComment">// Assume the following linked list has already been created:</span>
1 &lt;-&gt; 2 &lt;-&gt; 3 &lt;-&gt; 4 &lt;-&gt; 5
<span class="CodeEditor-promptComment">// Assume that we also have the following stand-alone nodes:</span>
3, 3, 6
<span class="CodeEditor-promptParameter">setHead</span>(4): 4 &lt;-&gt; 1 &lt;-&gt; 2 &lt;-&gt; 3 &lt;-&gt; 5 <span class="CodeEditor-promptComment">// set the existing node with value 4 as the head</span>
<span class="CodeEditor-promptParameter">setTail</span>(6): 4 &lt;-&gt; 1 &lt;-&gt; 2 &lt;-&gt; 3 &lt;-&gt; 5 &lt;-&gt; 6 <span class="CodeEditor-promptComment">// set the stand-alone node with value 6 as the tail</span>
<span class="CodeEditor-promptParameter">insertBefore</span>(6, 3): 4 &lt;-&gt; 1 &lt;-&gt; 2 &lt;-&gt; 5 &lt;-&gt; 3 &lt;-&gt; 6 <span class="CodeEditor-promptComment">// move the existing node with value 3 before the existing node with value 6</span>
<span class="CodeEditor-promptParameter">insertAfter</span>(6, 3): 4 &lt;-&gt; 1 &lt;-&gt; 2 &lt;-&gt; 5 &lt;-&gt; 3 &lt;-&gt; 6 &lt;-&gt; 3 <span class="CodeEditor-promptComment">// insert a stand-alone node with value 3 after the existing node with value 6</span>
<span class="CodeEditor-promptParameter">insertAtPosition</span>(1, 3): 3 &lt;-&gt; 4 &lt;-&gt; 1 &lt;-&gt; 2 &lt;-&gt; 5 &lt;-&gt; 3 &lt;-&gt; 6 &lt;-&gt; 3 <span class="CodeEditor-promptComment">// insert a stand-alone node with value 3 in position 1</span>
<span class="CodeEditor-promptParameter">removeNodesWithValue</span>(3): 4 &lt;-&gt; 1 &lt;-&gt; 2 &lt;-&gt; 5 &lt;-&gt; 6 <span class="CodeEditor-promptComment">// remove all nodes with value 3</span>
<span class="CodeEditor-promptParameter">remove</span>(2): 4 &lt;-&gt; 1 &lt;-&gt; 5 &lt;-&gt; 6 <span class="CodeEditor-promptComment">// remove the existing node with value 2</span>
<span class="CodeEditor-promptParameter">containsNodeWithValue</span>(5): true
</pre>