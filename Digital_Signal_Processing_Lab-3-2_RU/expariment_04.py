import numpy as np
import matplotlib.pyplot as plt

f=50
a=3
t=np.linspace(0,0.05,1000)
original_signal=a*np.cos(2*np.pi*f*t)
fs1=200
fs2=75
T1=1/fs1
T2=1/fs2

n1=np.arange(0,0.05,T1)
n2=np.arange(0,0.05,T2)
plt.figure(figsize=(10,6))


plt.plot(t,original_signal,'k-',label='x(t)=3cos(100*pi*t)',linewidth=1)
#sampled by 200hz
x1=a*np.cos(2*np.pi*f*n1)
plt.stem(n1,x1,linefmt='r-',markerfmt='ro',basefmt=' ',label=f'sampled by 200 Hz')
#sampled by 75 hz
x2=a*np.cos(2*np.pi*f*n2)
plt.stem(n2,x2,linefmt='g-',markerfmt='go',basefmt=' ',label='Sampled by 75 hz')
plt.legend()
plt.xlabel('Time(sec)')
plt.ylabel('Amplitude')
plt.grid(True)
plt.tight_layout()
plt.show()