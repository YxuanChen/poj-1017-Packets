# poj-1017-Packets
poj算法题1017——Packets
[Packets](http://poj.org/problem?id=1017)

**Description**

A factory produces products packed in square packets of the same height h and of the sizes 1*1, 2*2, 3*3, 4*4, 5*5, 6*6. These products are always delivered to customers in the square parcels of the same height h as the products have and of the size 6*6. Because of the expenses it is the interest of the factory as well as of the customer to minimize the number of parcels necessary to deliver the ordered products from the factory to the customer. A good program solving the problem of finding the minimal number of parcels necessary to deliver the given products according to an order would save a lot of money. You are asked to make such a program.

**Input**

The input file consists of several lines specifying orders. Each line specifies one order. Orders are described by six integers separated by one space representing successively the number of packets of individual size from the smallest size 1*1 to the biggest size 6*6. The end of the input file is indicated by the line containing six zeros.

**Output**

The output file contains one line for each line in the input file. This line contains the minimal number of parcels into which the order from the corresponding line of the input file can be packed. There is no line in the output file corresponding to the last “null” line of the input file.

**Sample Input**

0 0 4 0 0 1<br>
7 5 1 0 0 0<br> 
0 0 0 0 0 0<br> 

**Sample Output**

2<br> 
1<br> 

这是一道贪心算法，思想很简单，每次从最大的先放，依次放入，2\*2包裹和1\*1包裹是用来填补空位的。<br>
6\*6：一个包裹最多只能放入1个；<br>
5\*5：一个包裹最多只能放入1个、剩余的只能用1\*1来填充；<br>
4\*4：一个包裹最多只能放入1个，剩余可用5个2\*2填充，不足5个用1\*1填充；<br>
3\*3：一个包裹最多只能放入4个，不满四个用2\*2和1\*1填充（这里需要判断3\*3包裹个数，个数不同余下的空位可用2\*2填充的个数也不同）；<br>
2\*2：判断是否比可利用空间的个数多，多则需要增加包裹数量；<br>
1\*1：同2\*2；<br>
