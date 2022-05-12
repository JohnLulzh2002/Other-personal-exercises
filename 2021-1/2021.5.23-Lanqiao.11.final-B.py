points=[(0,0),(2020,11),(11,14),(2000,2000)]
n=int(input())
def dist(x,y):
    global points
    m=99999
    for p in points:
        d=abs(x-p[0])+abs(y-p[1])
        if d<m:
            m=d
    return m
count=0
for i in range(-2200,4100):
    for j in range(-2200,4100):
        if dist(i,j)<=n:
            count+=1
print(count)