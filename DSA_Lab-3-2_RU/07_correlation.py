import numpy as np
import matplotlib.pyplot as plt
x=np.array([1,3,-2,4])
y=np.array([2,3,-1,3])
z=np.array([2,-1,4,-2])
length=np.arange(-len(y)+1,len(x))
x_y = np.correlate(x,y,mode='full')
y_z = np.correlate(y,z,mode='full')

plt.figure(figsize=(10,8))
plt.subplot(2,1,1)
plt.stem(length,x_y,basefmt='k-',linefmt='r-',markerfmt='ro')
plt.title("Correleation of x(n) and y(n)")
plt.grid(True)
plt.xlabel('lag')
plt.ylabel("correlation coeffecient")



plt.subplot(2,1,2)
plt.stem(length,y_z,basefmt='k-',linefmt='g-',markerfmt='go')
plt.title("Correleation of y(n) and z(n)")
plt.grid(True)
plt.xlabel('lag')
plt.ylabel("correlation coeffecient")

plt.tight_layout()
plt.show()


