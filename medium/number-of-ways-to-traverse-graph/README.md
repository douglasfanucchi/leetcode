<div class="html">
<p>
  You're given two positive integers representing the width and height of a
  grid-shaped, rectangular graph. Write a function that returns the number of
  ways to reach the bottom right corner of the graph when starting at the top
  left corner. Each move you take must either go down or right. In other words,
  you can never move up or left in the graph.
</p>
<p>
  For example, given the graph illustrated below, with
  <span>width = 2</span> and <span>height = 3</span>, there are three ways to
  reach the bottom right corner when starting at the top left corner:
</p>
<pre> _ _
|_|_|
|_|_|
|_|_|
</pre>
<ol>
  <li>Down, Down, Right</li>
  <li>Right, Down, Down</li>
  <li>Down, Right, Down</li>
</ol>
<p>
  Note: you may assume that <span>width * height &gt;= 2</span>. In other words,
  the graph will never be a 1x1 grid.
</p>
<h3>Sample Input</h3>
<pre><span class="CodeEditor-promptParameter">width</span> = 4
<span class="CodeEditor-promptParameter">height</span> = 3
</pre>
<h3>Sample Output</h3>
<pre>10
</pre>
</div>
