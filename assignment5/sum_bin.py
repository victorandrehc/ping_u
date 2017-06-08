# -*- coding: utf-8 -*-

#SUM A+B


def sum_bin(a,b):
	N=len(a)
	result=[0 for i in range(N)]
	i=N-1
	aux=0
	while i>=0:
		result[i]=a[i]^b[i]^aux
		aux= (a[i] and b[i]) or (aux and (a[i]^b[i]))
		i-=1
	return (result,aux)

a=[0,0,0,1,1,1]
#  0,1,2,3,4,5
b=[0,0,0,0,1,1]

print sum_bin(a,b)