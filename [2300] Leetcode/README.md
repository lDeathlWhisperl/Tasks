# <a href="https://leetcode.com/problems/successful-pairs-of-spells-and-potions/">Task</a> :octocat:

You are given two positive integer arrays ```spells``` and ```potions```, of length ```n``` and ```m``` respectively, where ```spells[i]``` 
represents the strength of the <code>i<sup>th</sup></code> spell and ```potions[j]``` represents the strength of the <code>j<sup>th</sup></code> potion.
<br><br>

You are also given an integer ```success```. A spell and potion pair is considered **successful** if the **product** of their strengths is 
**at least** ```success```.
<br><br>

Return *an integer array* ```pairs``` *of length* ```n``` *where* ```pairs[i]``` *is the number of potions that will form a 
successful pair with the* <code>i<sup>th</sup></code> *spell*.

<hr></hr>

## Example 1:
**Input:** spells = [5,1,3], potions = [1,2,3,4,5], success = 7 <br>
**Output:** [4,0,3] <br>
**Explanation:** <br>
\- 0<sup>th</sup> spell: 5 * [1,2,3,4,5] = [5,<ins>**10**</ins>,<ins>**15**</ins>,<ins>**20**</ins>,<ins>**25**</ins>]. 4 pairs are successful. <br>
\- 1<sup>st</sup> spell: 1 * [1,2,3,4,5] = [1,2,3,4,5].     0 pairs are successful. <br>
\- 2<sup>nd</sup> spell: 3 * [1,2,3,4,5] = [3,6,<ins>**9**</ins>,<ins>**12**</ins>,<ins>**15**</ins>].   3 pairs are successful. <br>
Thus, [4,0,3] is returned. <br>

## Example 2:
**Input:** spells = [3,1,2], potions = [8,5,8], success = 16 <br>
**Output:** [2,0,2] <br>
**Explanation:** <br>
\- 0<sup>th</sup> spell: 3 * [8,5,8] = [<ins>**24**</ins>,15,<ins>**24**</ins>]. 2 pairs are successful. <br>
\- 1<sup>st</sup>  spell: 1 * [8,5,8] = [8,5,8]. 0 pairs are successful. <br>
\- 2<sup>nd</sup> spell: 2 * [8,5,8] = [<ins>**16**</ins>,10,<ins>**16**</ins>]. 2 pairs are successful. <br>
Thus, [2,0,2] is returned.
