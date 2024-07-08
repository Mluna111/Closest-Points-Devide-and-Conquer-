<h1>CS320Luna</h1>

<h2>Description</h2>
<p>This project implements an algorithm to find the closest pair of points in a 2D space. The implementation uses a combination of brute force and divide-and-conquer strategies, along with merge sort for sorting points based on their coordinates.</p>

<h2>Languages and Utilities Used</h2>
<ul>
    <li><b>C++</b></li>
</ul>

<h2>Files in the Project</h2>
<ul>
    <li><b>closestDriver.cpp:</b> Main driver file that reads points from a file, finds the closest pair, and outputs the result.</li>
    <li><b>Point.h:</b> Header file defining the Point class and its associated methods.</li>
    <li><b>mergeSort.h:</b> Header file containing the merge sort implementation used to sort points.</li>
</ul>

<h2>Environments Used</h2>
<ul>
    <li><b>Windows 10</b></li>
    <li><b>Linux</b></li>
</ul>

<h2>How to Run</h2>
<ol>
    <li><b>Compile the Program:</b>
        <pre><code>g++ -o closestDriver closestDriver.cpp</code></pre>
    </li>
    <li><b>Execute the Program:</b>
        <pre><code>./closestDriver</code></pre>
    </li>
    <li><b>Follow the prompts</b> to enter the filename containing the points. The file should have each point's coordinates on a new line.</li>
</ol>

<h2>Program Walk-Through</h2>
<p align="center">
    <b>Example Input File (points.txt): </b>
    <pre>
1.0 2.0
3.0 4.0
5.0 6.0
10.0 8.0
        </pre>
        <br/>
        <b>Output: </b>
        <pre>Closest points are: (1, 2) and (3, 4) with distance = 2.82843</pre>
    </p>
<br/>
<br/>
<h2>Program walk-through:</h2>
<p align="center">
<b>Prompted to enter file name and output computed results: </b>
<br/>
<br/>
<img src="https://imgur.com/ICmzgYi.png" height="80%" width="80%" />
<br />
<br />

</p>
