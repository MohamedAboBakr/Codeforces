import sys
n,m=map(int,sys.stdin.readline().split())
x=[]
t=[]
for i in range(n):
    x.append(input())
    t.append(0)

for j in range(m):
    o=[]
    for i in range(n):
        o.append(int(x[i][j]))
    b=max(o)
    for k in range(n):
        if o[k]==b:
            t[k]+=1


num=0
for i in range(n):
    if t[i]>0:
        num+=1

print(num)