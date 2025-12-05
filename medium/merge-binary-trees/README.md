<p>
    Write a function that takes in two Binary Trees, merges them, and returns
    the resulting tree. If two nodes overlap during the merge, the value of the
    merged node should be the sum of the overlapping nodes' values.
  </p>
  <p>
    Note that your solution can either mutate the input trees or return a new
    tree.
  </p>
  <p>
    Each <span>BinaryTree</span> node has an integer <span>value</span>, a
    <span>left</span> child node, and a <span>right</span> child node. Children
    nodes can either be <span>BinaryTree</span> nodes themselves or
    <span>None</span> / <span>null</span>.
  </p>
  <h3>Sample Input</h3>
  <pre>tree1 =   
          1
        /   \
       3     2
     /   \
    7     4

</pre>
<pre>
tree2 =
          1
        /   \
       5     9
     /      / \
    2      7   6
</pre>
  <h3>Sample Output</h3>
  <pre><span class="CodeEditor-promptParameter">output</span> =  
          2
        /   \
      8      11
    /  \    /  \
  9     4  7    6
</pre>