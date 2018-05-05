s=[]
for i in input():
    if s and i==s[-1]: s.pop()
    else: s+=[i]
print("".join(s))