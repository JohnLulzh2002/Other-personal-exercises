n=int(input())
factor={}
for i in range(2,n):
    getFactor=[]
    j=2
    t=i
    while i>1:
        c=0
        while i%j==0:
            i//=j
            c+=1
        if c:
            getFactor.append((j,c))
        j+=1
    factor[t]=getFactor
fffact=[0 for i in range(111)]
for i in factor.values():
    for j in i:
        fffact[j[0]]+=j[1]
ans=1
for i in fffact:
    ans*=1+i
print(ans)