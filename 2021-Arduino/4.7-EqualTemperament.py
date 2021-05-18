q=2**(1/12)
print(q)
n=440.0
feq=[0,2,4,5,7,9,11]
c=0
for i in range(13):
    # print(i,n,sep='\t')
    if (i%12)in feq:
        c+=1
        # print(c,int(n),1e6/n,sep='\t')
        print(int(1e6/n),end=',')
    n*=q