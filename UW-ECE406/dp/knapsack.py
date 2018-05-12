
ht={2:5,
3:10,
4:20} #hash table to store all knapsack return vals
v=[2,5,10,20] #vals (coin type)
w=[2,2,3,4] #weights (coin weight)

def knapsack(wi):
	if ht.get(wi):
		return ht[wi]

	ht[wi]=max([knapsack(wi-w[i]) + v[i] for i in range(len(w))])

knapsack(100)
