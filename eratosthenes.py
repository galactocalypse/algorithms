from math import sqrt
lim = 100001
arr = [1]*lim
arr[0] = arr[1] = 0
for i in range(2, lim, 1):
	if arr[i] == 1:
		for j in range(i*i, lim, i):
			arr[j] = 0

x = 0
primes = [0]*lim

for i in range(2, lim, 1):
	if arr[i]:
		primes[x] = i
		x = x + 1
l = x

def isprime(x):
	if x < lim:
		return arr[x]
	if lim*lim < x:
		return -1
	for i in range(0, l):
		if primes[i]*primes[i] > x:
			return -1
		if x % i == 0:
			return 0
	return 1

n = int(raw_input("Enter a number: "))
if n == 1:
	print "Neither prime nor composite"
elif isprime(n):
	print "Prime"
else:
	print "Not prime"
