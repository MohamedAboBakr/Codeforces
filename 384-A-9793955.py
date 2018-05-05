n=int(input())
if n%2==0:
    print(int((n*n)/2))
else:
    print(int(((n+1)*(n+1)/4)+((n-1)*(n-1)/4)))
for i in range(1,n+1):
    if i%2==0:
        print(".C"*(n//2)+("." if n%2 else ""))
    else:
        print("C."*(n//2)+("C" if n%2 else ""))