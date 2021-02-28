import numpy as np
def percepteon(w,x,theta):
    sum=np.dot(w,x.T)
    if sum>theta:
        return True
    else:
        return False
def AND(x):
    return percepteon(np.array([1,1]),x,1)
a_1=np.array([0,0])
a_2=np.array([0,1])
a_3=np.array([1,0])
a_4=np.array([1,1])
print(AND(a_1))
print(AND(a_2))
print(AND(a_3))
print(AND(a_4))