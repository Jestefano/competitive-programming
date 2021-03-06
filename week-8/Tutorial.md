So, this week we focus on DFS and some of its applications. The following are the resources:

- https://cp-algorithms.com/graph/depth-first-search.html

- https://cp-algorithms.com/graph/bridge-searching.html
- https://cp-algorithms.com/graph/cutpoints.html
- https://cp-algorithms.com/graph/search-for-connected-components.html
- https://cp-algorithms.com/graph/finding-cycle.html
- https://cp-algorithms.com/graph/bipartite-check.html
- https://cp-algorithms.com/graph/topological-sort.html
- Another way of doing (special) topological sort: [link](https://www.youtube.com/watch?v=tFpvX8T0-Pw&t=267s)

Don't get overwhelm by the amount of links, you can read all of it in less than 3-4 hours since they are not that long.

Remarks that I have learned through coding or thinking:

- We use the dfs toposort for the general problem and to check if there exists a topological order (by checking if there is a cycle). But if you want an specific solution you should use Kahn's algorithm.
- Even though there are only tree-edges and backward-edges in an undirected graph, once we run DFS sometimes we are going to evaluate whether a back-edge is a forward-edge. We need to be careful with that once we implement our algorithms.
- If we have an undirected graph and we want to transform it to a directed graph, we can follow the edges trees (to go down) and the backward edges to go up, this way we maximize the number of connected components. The exception of this rule are the bridges, where you need the two directions, otherwise you are going to lose some connectivity.
- Adding to the previous note, we can consider each group of nodes connected by edges but not bridges as a big node, where the new edges are the bridges. This forms a tree. Even more, if we try to transform an undirected tree in a directed tree, there is going to be a node that has 0 out-degree (prove it!), with this we can maximize the minimum cost of a node.
