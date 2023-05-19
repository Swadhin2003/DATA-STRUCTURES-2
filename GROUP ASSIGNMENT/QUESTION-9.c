//9.Write a algorithm to find the nearest ATM of a given Bank from a given location. Then, find the subsequent neighbouring ATMSs as per user’s requirement.
/*Input: Source node, Destination node, No. of hops
Output: Shortest path from source to destination
1. Let the source node be S and the destination node be D.
2. Find the shortest path from S to D using Dijkstra's algorithm.
3. Let the shortest path be P.
4. If P has only one node, then print "No path found".
5. Otherwise, print the path from S to D.
6. And find the adjacent nodes present near the destination node.
7. If present, print those adjacent nodes.
8. Exit.*/