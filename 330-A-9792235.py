import sys
r,c=map(int,sys.stdin.readline().split())
cake=[]
for i in range(0,r):
    cake.append(input())
good_raws=r
good_columns=c
for i in range(0,r):
    k_raws=0
    for j in range(0,c):
        if cake[i][j]=='S':
            k_raws=1
    if k_raws==1:
        good_raws-=1

rows_eaten_cells=good_raws*c
for j in range(0,c):
    k_columns=0
    for i in range(0,r):
        if cake[i][j]=='S':
            k_columns=1
    if k_columns==1:
        good_columns-=1
columns_eaten_cells = good_columns*(r-good_raws)
print(rows_eaten_cells+columns_eaten_cells)