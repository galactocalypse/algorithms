# Need to add error-checking.
# Sample Input 1:
# Enter an integer ( <= 9998200081): 9992800079
# Sample Output 1:
# Not prime
# 
# Sample Input 2:
# Enter an integer ( <= 9998200081): 9099999901
# Sample Output 2:
# Prime

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
print primes[l-1]**2
def isprime(x):
	if x < lim:
		return arr[x]
	if primes[l-1]**2 < x:
		return -1
	for i in range(0, l):
		if primes[i]**2 > x:
			return 1
		if x % primes[i] == 0:
			return 0
	return 1

n = int(raw_input("Enter an integer ( <= 9998200081): "))
if n == 1 or n == 0:
	print "Neither prime nor composite"
elif n < 0:
	n = -n
isp = isprime(n)
if isp == 1:
	print "Prime"
elif isp == 0:
	print "Not prime"
else:
	print "Cannot determine with current bounds."

