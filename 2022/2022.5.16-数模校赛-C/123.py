import numpy as np
from matplotlib import pyplot as plt
#
m=np.zeros((16,16),dtype=int)
for i in range(16):
    m[i,(i+1)%16]=1
    m[(i+1)%16,i]=1
e=((1,6),(1,12),(2,10),(2,13),(3,7),(3,15),(4,9),(4,12))
d=(-1,3,7,11)
for X,Y in e:
    for j in d:
        m[(X+j)%16,(Y+j)%16]=1
#
rs=[[[]for j in range(16)]for i in range(16)]
for b in range(16):
    s=set(range(16))
    s.remove(b)
    r=[[b]]
    while s:
        t=r.copy()
        ns=set()
        r=[]
        for i in t:
            l=i[-1]
            for j in range(16):
                if m[l][j] and j in s:
                    rs[b][j].append(i+[j])
                    r.append(i+[j])
                    ns.add(j)
        s=s.difference(ns)
#
w=np.loadtxt("data.csv", delimiter=",")
#
ps=[]
for i in range(16):
    t=rs[i]
    for j in range(16):
        if i==j:
            continue
        ps.append(((i,j),t[j]))
mx=[len(p[1])for p in ps]+[2]

ans=999
mx=np.array(mx)
ppp=mx[:-1].prod()
pp={}
for i in range(100):
    pp[ppp//100*i]=i
qq=0
def gen_n():
    n=np.array(([0 for x in range(241)]))
    while n[-1]==0:
        yield n
        n[0]+=1
        i=0
        while n[i]>=mx[i]:
            n[i]=0
            i+=1
            n[i]+=1
for n in gen_n():
    if qq in pp:
        print(pp[qq],'%')
    qq+=1
    c=[0 for x in range(16)]
    d=[0 for x in range(16)]
    for i in range(240):
        (x,y),r=ps[i]
        weight=w[x,y]
        for j in r[n[i]][1:-1]:
            c[j]+=weight
            d[j]+=1
    if max(c)<ans:
        ans=max(c)
        ansn=n.copy()
        maxc=c.copy()
        maxd=d.copy()
np.savetxt('ans.txt',ans,delimiter=',',fmt='%d')
np.savetxt('maxc.txt',maxc,delimiter=',',fmt='%d')
np.savetxt('maxd.txt',maxd,delimiter=',',fmt='%d')
np.savetxt('ansn.csv',ansn,delimiter=',',fmt='%d')