from matplotlib import pyplot as plt
a=1.0
y=[]
m=60
# m=365
for i in range(m):
    a*=365-i
    a/=365
    y.append(a)
plt.plot(range(1,m+1),y)
plt.axhline(0.5,linestyle=':',color='g')
plt.show()