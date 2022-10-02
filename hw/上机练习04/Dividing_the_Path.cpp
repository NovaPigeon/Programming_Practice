/*
02H:Dividing the Path
查看 提交 统计 提问
总时间限制: 1000ms 内存限制: 65536kB
描述
Farmer John's cows have discovered that the clover growing along the ridge of the hill in his field is particularly good. To keep the clover watered, Farmer John is installing water sprinklers along the ridge of the hill.

To make installation easier, each sprinkler head must be installed along the ridge of the hill (which we can think of as a one-dimensional number line of length L (1 <= L <= 1,000,000); L is even).

Each sprinkler waters the ground along the ridge for some distance in both directions. Each spray radius is an integer in the range A..B (1 <= A <= B <= 1000). Farmer John needs to water the entire ridge in a manner that covers each location on the ridge by exactly one sprinkler head. Furthermore, FJ will not water past the end of the ridge in either direction.

Each of Farmer John's N (1 <= N <= 1000) cows has a range of clover that she particularly likes (these ranges might overlap). The ranges are defined by a closed interval (S,E). Each of the cow's preferred ranges must be watered by a single sprinkler, which might or might not spray beyond the given range.

Find the minimum number of sprinklers required to water the entire ridge without overlap.
输入
* Line 1: Two space-separated integers: N and L

* Line 2: Two space-separated integers: A and B

* Lines 3..N+2: Each line contains two integers, S and E (0 <= S < E <= L) specifying the start end location respectively of a range preferred by some cow. Locations are given as distance from the start of the ridge and so are in the range 0..L.
输出
* Line 1: The minimum number of sprinklers required. If it is not possible to design a sprinkler head configuration for Farmer John, output -1.
样例输入
2 8
1 2
6 7
3 6
样例输出
3
提示
INPUT DETAILS:

Two cows along a ridge of length 8. Sprinkler heads are available in integer spray radii in the range 1..2 (i.e., 1 or 2). One cow likes the range 3-6, and the other likes the range 6-7.

OUTPUT DETAILS:

Three sprinklers are required: one at 1 with spray distance 1, and one at 4 with spray distance 2, and one at 7 with spray distance 1. The second sprinkler waters all the clover of the range like by the second cow (3-6). The last sprinkler waters all the clover of the range liked by the first cow (6-7). Here's a diagram:

                 |-----c2----|-c1|       cows' preferred ranges
     |---1---|-------2-------|---3---|   sprinklers
     +---+---+---+---+---+---+---+---+
     0   1   2   3   4   5   6   7   8

The sprinklers are not considered to be overlapping at 2 and 6.
来源
USACO 2004 December Gold
*/
#include<iostream>
using namespace std;
int main()
{
    return 0;
}