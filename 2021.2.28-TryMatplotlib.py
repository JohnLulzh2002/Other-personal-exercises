import numpy
import matplotlib.pyplot as plt
from matplotlib.image import imread
# from os import getcwd
# print(getcwd())
# 发现VSCode的相对路径有问题，后来修改设置修正问题

# x=numpy.arange(0,7,0.1)
# y1=numpy.sin(x)
# y2=numpy.cos(x)
# plt.plot(y1,y2,label="circle")
# plt.plot(x,y1,label="sin")
# plt.plot(x,y2,linestyle="--",label="cos")
# plt.xlabel("x")
# plt.ylabel("y")
# plt.title("test")
# plt.legend()
# plt.show()

img=imread("8.jpg")
# img=imread("C:/Users/lzh20/Desktop/8.jpg")
plt.imshow(img)
plt.show()