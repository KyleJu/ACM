import math
 
l = [float(x) for x in raw_input().split()]
n = l[0]
k = l[1]
x = math.log(n,2)
if x > k:
    print("You will become a flying monkey!")
else:
    print("Your wish is granted!")
