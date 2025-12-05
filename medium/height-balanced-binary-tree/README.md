<p>
  You're given the root node of a Binary Tree. Write a function that returns
  <span>true</span> if this Binary Tree is height balanced and
  <span>false</span> if it isn't.
</p>
<p>
  A Binary Tree is height balanced if for each node in the tree, the difference
  between the height of its left subtree and the height of its right subtree is
  at most <span>1</span>.
</p>
<p>
  Each <span>BinaryTree</span> node has an integer <span>value</span>, a
  <span>left</span> child node, and a <span>right</span> child node. Children
  nodes can either be <span>BinaryTree</span> nodes themselves or
  <span>None</span> / <span>null</span>.
</p>
<h3>Sample Input</h3>
<pre><span class="CodeEditor-promptParameter">tree</span> = 
       1
     /   \
    2     3
  /   \     \
 4     5     6
     /   \
    7     8
</pre>
<h3>Sample Output</h3>
<pre>true
</pre>