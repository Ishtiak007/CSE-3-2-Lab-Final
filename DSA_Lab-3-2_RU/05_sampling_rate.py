import numpy as np
import matplotlib.pyplot as plt
def make_signal(t):
    signal = 3*np.cos(200*np.pi*t)+5*np.sin(600*np.pi*t)+10*np.cos(1200*np.pi*t)
    return signal

t=np.linspace(0,0.01,1000)
signal = 3*np.cos(200*np.pi*t)+5*np.sin(600*np.pi*t)+10*np.cos(1200*np.pi*t)

#sampling in 800 hz
fs1=800
n1=np.arange(0,0.01,1/fs1)
samp_signal1=make_signal(n1)

#sampling in 1000 hz
fs2=1000
n2=np.arange(0,0.01,1/fs2)
samp_signal2=make_signal(n2)

#sampling in 3000 hz
fs3=3000
n3=np.arange(0,0.01,1/fs3)
samp_signal3=make_signal(n3)


plt.figure(figsize=(10,8))
plt.subplot(4,1,1)
plt.plot(t,signal,'k-',label='original signal',linewidth=1)
plt.grid(True)

plt.subplot(4,1,2)
plt.stem(n1,samp_signal1)

plt.subplot(4,1,3)
plt.stem(n2,samp_signal2)

plt.subplot(4,1,4)
plt.stem(n3,samp_signal3)

plt.xlabel("time")
plt.ylabel("Amplitude")
plt.tight_layout()
plt.show()