# Metro-Map-Navigator

Dijkstras-Algorithm:

INTRODUCTION: 
This project represents a real-time use case of Dijkstra's algorithm to efficiently find the shortest path from a given source Node to all other Nodes.  

For real-time applications, we can consider using the HYDERABAD METRO map as a practical example to implement Dijkstra’s algorithm. The Hyderabad Metro network consists of multiple interconnected stations, making it an ideal case for finding the shortest and most efficient routes between locations. By representing the metro stations as nodes and the distances or travel times between them as weighted edges, Dijkstra’s algorithm can help commuters quickly determine the fastest path from one station to another.

Algorithm Steps:
1. Initialization
   -Create an array distance[] to store the shortest distance from the source to each station. Initialize all distances to infinity (INT_MAX) except the source         station, which is 0.
   -Create a priority queue pq to process stations in increasing order of distance.
   -Push the source station into the priority queue with distance 0.
2. Processing the Queue
   -While the priority queue is not empty:
   -Extract the station u with the smallest distance from the priority queue.
   -For each neighbor v of u:
      1.Calculate the potential distance through u as distance[u] + weight(u,v) (here, all edges have weight = 1).
      2.If this new distance is smaller than the current distance[v], update distance[v] and push (distance[v], v) into the priority queue.
3. Termination
   -The algorithm finishes when the priority queue becomes empty.
   -At this point, the array distance[] contains the shortest distance from the source station to all other stations. If distance[i] is still INT_MAX, station i is     unreachable from the source.
4. Output
   -Print the shortest distance from the source station to every other station.
   -If a station is unreachable, display: unreachable.

Time Complexity: O((V+E)logV)
Space Complexity: O(V+E)
