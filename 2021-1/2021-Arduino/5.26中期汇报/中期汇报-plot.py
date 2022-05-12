import numpy as np
from matplotlib import pyplot as plt

# x=np.arange(0,20,0.1)
# y=np.sin(x)
# plt.plot(x,y)
# plt.axvline(4,ls=':',c='red')

# tx=[0.01,1,1.01,4]
# ty=[1,1,0,0]
# x,y=[],[]
# for i in range(4):
#     for j in tx:
#         x.append(i*4+j)
#     for j in ty:
        # y.append(j)
# plt.plot(x,y)
# plt.axvline(2*np.pi,ls=':',c='red')

x=[0,1,1.01,2,2.01,3,3.01,5,5.01,6,6.01,9]
y=[1,1,0,0,1,1,0,0,1,1,0,0]
plt.plot(x,y)
plt.axvline(2,ls=':',c='red')
plt.axvline(5,ls=':',c='red')
plt.axvline(9,ls=':',c='red')

plt.axvline(0,c='black')
plt.axhline(0,c='black')
plt.show()