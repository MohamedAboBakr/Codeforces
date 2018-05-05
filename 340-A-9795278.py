import sys
x,y,a,b=map(int,sys.stdin.readline().split())
def get_lcm(x,y):
    if x>y:
        k=y
        while True:
            if k%x==0:
                return k
            k+=y
    elif x<y:
        return get_lcm(y,x)
    elif x==y: return x

lcm=get_lcm(x,y)
num=(b//lcm)-((a-1)//lcm)
print(num)