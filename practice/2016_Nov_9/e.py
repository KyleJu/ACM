import fractions

fact = dict()
fact[0] = 1
fact[1] = 1
for i in range(2,11):
  fact[i] = i*fact[i-1]

def choose(n, k):
  if n < k:
    return 0
  else:
    return fact[n]/(fact[n-k]*fact[k])

t = int(input())
for test in range(t):
  n, m, k = [int(x) for x in input().split()]
  if m < k:
    print("0")
    continue
  denom = n**m
  numer = choose(n,k)
  tmp = k**m
  num = k-1
  i = 1
  subtract = True
  while num > 0:
    if subtract: 
      subtract = False
      tmp -= choose(k,i)*num**m
    else:
      subtract = True
      tmp += choose(k,i)*num**m
    num -= 1
    i += 1
  numer *= tmp
  if numer/denom == 1:
    print("1")
  elif numer/denom == 0:
    print("0")
  else:
    gc = fractions.gcd(numer, denom)
    numer = int(numer/gc)
    denom = int(denom/gc)
    print(str(numer)+"/"+str(denom))
