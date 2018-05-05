n=int(input())
x=list(map(int,input().split()))
b=[]
for i in x:
    b.append(i)
b.reverse()

if x==sorted(x):
    print(0)
    exit()
elif (sorted(x)==b) and n!=2 :
    print(-1)
    exit()
elif x[-1]>x[0]:
    print(-1)
    exit()
elif  x[-1]<x[0] or x[-1]==x[0]:
    r=0
    j=-1
    k=0
    while(x[j]<x[k] or x[j]==x[k]):
        r+=1
        j-=1
        k-=1

    if x[:j+1]==sorted(x[:j+1]):
        print(r)
        exit()
    else:
        print(-1)
        exit()