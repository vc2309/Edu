#!/usr/bin/env python3
"""
ECE406
Python file for assignment 3, Exercise 5

we will use the queue module to implement a FIFO queue.
- you can create a queue with Q = queue.Queue(max_size)
- you can inject v onto the queue with Q.put(v)
- you can eject from the queue with Q.get()
"""
import queue

def bfs(g, s, d):
    q = [s]
    while queue:
        p = q.pop(0)
        
        path=g[p]
        
        nxt = path[-1]
        # print(path,nxt)
        if nxt == d:
            return len(path)
        for neighbor in g[nxt]:
            np = path
            np.append(neighbor)
            for node in np:
                q.append(node)

def shortest_v_paths(adj, vertex_s):
    """
    Input:  1) A directed graph represented as an adjacency list adj:
                adj[1] is a list containing the neighbors of vertex 1
                (by default, vertices are numbered from 0 to |V| - 1)
            2) a vertex_s in 0,...,|V|-1

    Output: a matrix of distances, where M[i,j] gives the length of the shortest
            path from vertex i to vertex j passing through vertex_s
    """
    # < your code goes here.  feel free to change the name of the variables.
    # can represent pairwise distances as a list of lists,
    # where dist[i][j] gives distance from i to j
    all_paths=[[0 for j in range(len(adj))] for i in range(len(adj))]
    for i,j in enumerate(all_paths):
        for k,l in enumerate(all_paths[i]):
            all_paths[i][k]=all_paths[i][k]+bfs(adj,i,vertex_s)+bfs(adj,vertex_s,k)
            print(all_paths[i][k])

    print(all_paths)

    # example to demonstrate list of lists (you can delete)
    # num_vertices = len(adj)
    # dist = list()
    # for i in range(num_vertices):
    #     dist.append([0] * num_vertices)

    # return dist


def main():
    """
    A simple test case for your algorithm with four vertices 0,1,2,3
    """
    adj = [[1],
           [2, 3],
           [1, 3],
           [0]]

    # test case:
    print(shortest_v_paths(adj, 3))
    # In this graph, 
    # 1) the shortest path from 3 to 3 passing through 3 has length 0
    # 2) The shortest path from 0 to 2 passing through 3 is
    # 0 -> 1 -> 3 -> 0 -> 1 -> 2 having a length of 5


if __name__ == '__main__':
    main()
