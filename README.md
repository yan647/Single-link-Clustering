# Single-link-Clustering

Description
Given n nodes in a two-dimensional space, we want to use single-link custering method to find k clusters. This is equivalent to finding an MST (Minimum spanning tree) of these nodes and deleting k-1 longest edges.

Your job is to output the length of the (k-1)-th longest edges of the MST.

Input
 There are multiple cases. For each case, the first line includes n and k (2<=k<=n<=100). The following n lines give the coordinates of n nodes. You may use Euclidean distance to measure the distance between two nodes.

Output
 For each case, output the length of the (k-1)-th longest edges. The precision is set to 2 digits after the decimal point.

Sample Input
6 2
1 1
2 1
1 2
3 3
4 2
4 3

Sample Output
2.24

对程序进行了注释
