#!/usr/bin/env python3
"""
Assignment 2 Python file
Copy-and-paste your extended_euclid and modexp functions
from assignment 1
"""
import random
import math

def modexp(x, y, N):
    """
    Input: Three positive integers x and y, and N.
    Output: The number x^y mod N
    """
    if y==0: 
        return 1 
    z = modexp(x, int(y/2), N )
    if y%2==0:
        return (z**2)%N 
    else:
        return x*(z**2)%N 


# part (ii) for extended Euclid  -- fill in the code below
def extended_euclid(a, b):
    """
    Input: Two positive integers a >= b >= 0
    Output: Three integers x, y, and d returned as a tuple (x, y, d) 
            such that d = gcd(a, b) and ax + by = d
    """
    if b==0:
        return 1,0,a
    else:
        x,y,d=extended_euclid(b,a%b)
    return y,x-(int(a/b)*y),d

def primality(N):
    """
    Test if a number N is prime using Fermat's little Theorem with
    ten random values of a.  If a^(N-1) mod N = 1 for all values,
    then return true.  Otherwise return false.
    Hint:  you can generate a random integer between a and b using
    random.randint(a,b).
    """
    if N == 2:
        return True

    if N % 2 == 0:
        return False

    #we will carry out the test 100 times to make the probability of failure at most 2^-1000 which is miniscule. if N is smaller than 1000, we just run it N-1 times
    k=1000 if N>1000 else N-1
    for i in xrange(k):
        a = random.randint(1, N-1)
        if modexp(a,N-1,N) != 1:
            return False
    return True


def prime_generator(N):
    """
    This function generates a prime number <= N
    """
    flag=False
    while not flag:
        temp=random.randint(int(N/10),N)
        if primality(temp):
            # print "temp {}".format(temp)
            # print(type(temp))
            return int(temp*1)
            flag=True

def minvert(a,n):
    x,y,d=extended_euclid(a,n)
    t=x if x<0 else y
    t=t+a
    return t
def main():
    """
    Test file for the two parts of the question
    """
    ## Excercise 1:  generating primes and RSA
    ##################
    flag=True
    while flag:
        p = prime_generator(10000000)
        # print(type(p))
        q = prime_generator(10000000)
        # print "{}".format(p,q)
        N = p*q
        e = 5
        x,y,z=extended_euclid((p-1)*(q-1),e)
        flag=True if z!=1 else False
    d=minvert((p-1)*(q-1),e)
    x = 329415
    print("message: {}, N:{}, e:{}".format(x,N,e))
    y=modexp(x,e,N)
    print("encrypted message: {}".format(y))
    print("private key: {}".format(d))
    print("decrypted {}".format(modexp(y,d,N)))

if __name__ == '__main__':
    main()
