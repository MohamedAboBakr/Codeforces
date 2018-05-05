import math
n,k=list(map(int,input().split()))
m=k-1
if m<(int(math.ceil(n/2))):
    print(2*m+1)
else:
    t=(m-int(math.ceil(n/2)))*2
    print(t+2)