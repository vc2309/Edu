#!/usr/bin/env python3
"""
ECE 406:  File for Exercise 1 of Assignment #3 
"""
import numpy.fft as np


def main():
    """
    Exercise 1:  Using the FFT to multiply two binary numbers.  
    You just need to fill in parts (v) and (vi)
    """
    # The binary numbers and their product
    a_bin = 0b110000001100
    b_bin = 0b100011110000
    c_bin = a_bin * b_bin
    print('The product of a and b is', c_bin)


    # (i) The coefficients of the polynomials A and B
    Acoeff = [0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1]
    Bcoeff = [0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 1]


    # (ii) the value representations of A and B
    Aval = np.fft(Acoeff, 32)
    Bval = np.fft(Bcoeff, 32)


    # (iii) The value representation of C
    Cval = []
    for i in range(len(Aval)):
        Cval.append(Aval[i] * Bval[i])

    # print(Cval)
    # (iv) The coefficients of the polynomial C
    Ccoeff = np.ifft(Cval)

    # we'll get rid of the imaginary parts, which are just numerical errors
    for i, c in enumerate(Ccoeff):
    	# print(c,int(round(c.real)))
    	Ccoeff[i] = int(round(c.real))
    # print(Ccoeff)

    # (v) calculate the product by evaluating the polynomial at 2, i.e., C(2)
    # (You may need to take the real part at the end if there is a small imaginary component)
    prod = 0
    for i, c in enumerate(Ccoeff):
    	prod=prod+((2**i)*c)
    
    print('Using the FFT the product of a and b is', int(round(prod.real)))
    x=0
    c=[]
    # (vi) write code to calculate the binary digits of c directly from the coefficients of C, Ccoeff.
    for i, j in enumerate(Ccoeff):
    	k = int(j.real) + x
    	x, r= divmod(k, 2)
    	c.append(r)
    print("Binary digits of c:- {}".format(c))

if __name__ == '__main__':
    main()
