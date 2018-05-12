#!/usr/bin/env python3
"""
ECE406, Winter 2018
Assignment #6, Q6
"""
import numpy as np

def make_change(coins, change_value):
    """
    Input: a list coins[1 ... n]  where coins[i] contains value of ith coin
           an integer change_value that we want to make change for
    Output: a list coins_used[1 ... n] where coins_used[i] gives number of coins 
            of value coins[i] used to make change, or False if change cannot be made
    """
    n=len(coins)
    dp=[[np.inf for i in range (n)] for j in range(change_value)]
    
    for i,j in enumerate(coins):
    	for x,y in enumerate(dp[j-1]):
    		# print(x,i,j)
    		if x==i:

    			dp[j-1][x]=1
    			# print(dp)
    		else:
    			dp[j-1][x]=0
    
    
    rv=change_value
    for i in range(0,change_value+1):
    	rv=i
    	print(i)
    	for j in range(n-1,-1,-1):
    		if coins[j] <= rv+1:
    			print("yes"+str(coins[j]))
    			if not (np.isfinite(dp[rv-1][j])):
	    			if j==0:
	    				print("im updating rv={} j={}".format(rv,j))
    					print("dp[rv-j-1][j]={} dp[j][j]={}".format(dp[rv-j-1][j],dp[j][j]))
		    			dp[rv][j]=dp[rv-j-1][j]+dp[j][j]
		    			rv=rv-( (dp[rv-j-1][j]*coins[j]) + (dp[j][j]*coins[j]) -1)
		    		else:
		    			print("im updating rv={} j={}".format(rv,j))
    					print("dp[rv-j][j]={} dp[j][j]={}".format(dp[rv-j][j],dp[j][j]))
		    			dp[rv][j]=dp[rv-j][j]+dp[j][j]
		    			rv=rv-( (dp[rv-j][j]*coins[j]) + (dp[j][j]*coins[j]) -1)
	    			print("rv {}".format(rv))
	    			print(dp)
	    		
	    	else:
	    		dp[rv][j]=0


    print(dp)


def main():
    """
    Testing your change maker
    """
    # print(make_change([2, 7, 13, 29], 335))
    print(make_change([1, 5, 10, 24], 27))


if __name__ == '__main__':
    main()
