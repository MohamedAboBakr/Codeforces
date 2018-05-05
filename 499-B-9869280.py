n,m = map(int, input().split())
d = {}
for _ in range(m):
    a,b = input().split()
    d[a] = b if len(a)>len(b) else a
print(' '.join([d[word] for word in input().split()]))