import numpy as np
import matplotlib.pyplot as plt

n=np.arange(-10,10,1)

#unit step plot
unit_step=np.where(n>=0,1,0)
plt.figure(figsize=(12,8))
plt.subplot(3,2,1)
plt.stem(n,unit_step)
plt.title("Unit step signal")

#ramp plot
ramp= np.where(n>=0,n,0)
plt.subplot(3,2,2)
plt.stem(n,ramp)
plt.title("Ramp signal")

#exponential
a=1.1
expo=a*n
plt.subplot(3,2,3)
plt.stem(n,expo)
plt.title("Exponential")

#sin,cos
f=0.1
sine=np.sin(2*np.pi*f*n)
cosine=np.cos(2*np.pi*f*n)
plt.subplot(3,2,4)
plt.stem(n,sine)
plt.title("Sine")

plt.subplot(3,2,5)
plt.stem(n,cosine)
plt.title("Cosine")

plt.tight_layout()
plt.show()