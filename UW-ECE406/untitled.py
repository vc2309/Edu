#!/usr/bin/env python3
"""
ECE406, Winter 2018
Assignment #6, Q6
"""

# def change_helper(num_coins, change_value, coin_dict, coins_used):
# 	if num_coins[]
# 	idx=coin_dict.get(change_value)
# 	if idx:
# 		coins_used[idx]+=1

# 	else:
# 		re

import numpy as np

def make_change(coins, change_value):
    """
    Input: a list coins[1 ... n]  where coins[i] contains value of ith coin
           an integer change_value that we want to make change for
    Output: a list coins_used[1 ... n] where coins_used[i] gives number of coins 
            of value coins[i] used to make change, or False if change cannot be made
    """
    # 
    # num_coins=[[0 for i in range(change_value)] for j in range(n)]
    coin_dict={j:i for i,j in enumerate(coins)}
    n=len(coins)
    dp=[np.inf for i in range (change_value+1)]
    dp[0] = 0
    for i in range((change_value+1)):
    	for j,k in enumerate(coins):
	    	if (k <= i):
		    	sub_res = dp[i-k]
		    	if (np.isfinite(sub_res) and (sub_res + 1 < dp[i])):
		    		dp[i]=sub_res+1
		    		coin_dict[k]+=1
		    		print(coin_dict)
def main():
    """
    Testing your change maker
    """
    print(make_change([2, 7, 13, 29], 335))
    print(make_change([1, 5, 10, 24], 27))


if __name__ == '__main__':
    main()
