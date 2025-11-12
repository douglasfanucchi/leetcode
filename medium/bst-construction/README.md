<p>
  Write a <span>BST</span> class for a Binary Search Tree. The class should
  support:
</p>
<ul>
  <li>Inserting values with the <span>insert</span> method.</li>
  <li>
    Removing values with the <span>remove</span> method; this method should
    only remove the first instance of a given value.
  </li>
  <li>Searching for values with the <span>contains</span> method.</li>
</ul>
<p>
  Note that you can't remove values from a single-node tree. In other words,
  calling the <span>remove</span> method on a single-node tree should simply not
  do anything.
</p>
<p>
  Each <span>BST</span> node has an integer <span>value</span>, a
  <span>left</span> child node, and a <span>right</span> child node. A node is
  said to be a valid <span>BST</span> node if and only if it satisfies the BST
  property: its <span>value</span> is strictly greater than the values of every
  node to its left; its <span>value</span> is less than or equal to the values
  of every node to its right; and its children nodes are either valid
  <span>BST</span> nodes themselves or <span>None</span> / <span>null</span>.
</p>
<h3>Sample Usage</h3>
<pre><span class="CodeEditor-promptComment">// Assume the following BST has already been created:</span>
         10
       /     \
      5      15
    /   \   /   \
   2     5 13   22
 /           \
1            14

<span class="CodeEditor-promptComment">// All operations below are performed sequentially.</span>
<span class="CodeEditor-promptParameter">insert</span>(12):   10
            /     \
           5      15
         /   \   /   \
        2     5 13   22
      /        /  \
     1        12  14

<span class="CodeEditor-promptParameter">remove</span>(10):   12
            /     \
           5      15
         /   \   /   \
        2     5 13   22
      /           \
     1            14

<span class="CodeEditor-promptParameter">contains</span>(15): true
</pre>