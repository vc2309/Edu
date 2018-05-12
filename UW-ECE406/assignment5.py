#!/usr/bin/env python3
"""
ECE406: Assignment 5, Q4
You will need to install scipy ('pip3 install scipy') for the import command to work.
"""
from scipy.optimize import linprog


def max_flow(cap, s, t):
    """
    Input: A matrix giving the capacity on each edge.  
            If c[i,j] = 0, then the edge (i,j) is not in the graph 
           A source s and sink node t,   
    Output: A matrix giving the flow on each edge, 
            A number giving the value of the max flow.
    """
    n = len(cap)
    bounds=[[] for i in cap]
    lin_cap=[]
    for i,x in enumerate(cap):
        for j in x:
            bounds[i].append((0,j))
    
    c = []
    for i,x in enumerate(cap):
        c.append([])
        if i==s:
            c[i]=[-1 for i in range(n)]
        else:
            c[i]=[0 for i in range(n)]

    
    opt=[]
    for i in range(len(bounds)):
        opt.append((linprog(c=c[i], bounds=bounds[i]))["fun"])

    return -sum(opt), opt
    
    
    

def example():
    """
    The following is an example to get you started
    """
    # nine variables, each has an upper and lower bound
    bounds = [(0, 0), (0, 3), (0, 1), 
              (0, 0), (0, 0), (0, 1),
              (0, 0), (0, 0), (0, 0)]
    
    # an equality constraint
    Aeq = [[0, -1, 0, 1, 1, 1, 0, -1, 0]]
    beq = [0]
    
    # the objective c function
    c = [-1, -1, -1, 0, 0, 0, 0, 0, 0]
    
    # solving
    opt = linprog(c=c, A_eq=Aeq, b_eq=beq, bounds=bounds)
    print("\n example output: \n", opt)


def main():
    """
    Testing your LP.  The following is a single example.  Your alg
    should work for any input.
    """
    example()
    # the output of the example is the following :
    #
    #      fun: -2.0
    #       message: 'Optimization terminated successfully.'
    #           nit: 6
    #         slack: array([ 0.,  2.,  0.,  0.,  0.,  0.,  0.,  0.,  0.])
    #        status: 0
    #       success: True
    #             x: array([ 0.,  1.,  1.,  0.,  0.,  1.,  0.,  0.,  0.])
    #
    # Note:
    # 1) the optimization has a value of opt.val = -2.0.  linprog solves minimization problems.
    #    To solve a maximization we solve:  min -c^T x.
    #
    # 2)  the array opt.x contains the value of each variable.
    #     For example, the value of variable 1 (0 indexing) has value 1.0, which lies between
    #     its lower and upper bounds of 0 and 3.

    
    # TEST PROBLEM -- the optimal solution for this should be 7
    c = [[0, 3, 4, 0, 0],
         [0, 0, 1, 0, 2],
         [0, 0, 0, 5, 0],
         [0, 0, 0, 0, 6],
         [1, 1, 0, 0, 0]]
    s = 0
    t = 4
    
    print(max_flow(c, s, t))
    ##############
    ## Hint: 
    ## To call linprog, you need variables with a single index.  That is, you can't directly
    ## define the variables flow[i,j].  So, you'll have to unwrap these into an array x of length 
    ## n^2.  A common way is to store flow[i,j] in position i * n + j of the array x.
    ##
    ##  Notice, that when thought of like this, example() encodes a max flow problem
    ##  for a graph with three vertices and nine edges.  
    ##  Just three of the edges have non-zero capacity: (0,1), (0,2) and (1,2),
    ##  with capacities of 3, 1, and 1, respectively. s = 0 and t = 2.
    ####################


if __name__ == '__main__':
    main()
