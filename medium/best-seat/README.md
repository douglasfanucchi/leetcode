<p>
  You walk into a theatre you're about to see a show in. The usher within the
  theatre walks you to your row and mentions you're allowed to sit anywhere
  within the given row. Naturally you'd like to sit in the seat that gives you
  the most space. You also would prefer this space to be evenly distributed on
  either side of you (e.g. if there are three empty seats in a row, you would
  prefer to sit in the middle of those three seats).
</p>
<p>
  Given the theatre row represented as an integer array, return
  the seat index of where you should sit. Ones represent occupied seats and zeroes
  represent empty seats.
</p>
<p>
  You may assume that someone is always sitting in the
  first and last seat of the row. Whenever there are two equally good seats,
  you should sit in the seat with the lower index. If there is no seat to sit
  in, return -1. The given array will always have a length of at least one
  and contain only ones and zeroes.
</p>
<h3>Sample Input</h3>
<pre><span class="CodeEditor-promptParameter">seats</span> = [1, 0, 1, 0, 0, 0, 1]
</pre>
<h3>Sample Output</h3>
<pre>4
</pre>