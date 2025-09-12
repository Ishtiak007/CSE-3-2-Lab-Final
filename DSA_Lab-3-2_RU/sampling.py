import numpy as np
import matplotlib.pyplot as plt

f=10
t_cont=np.linspace(0,1,1000)
singnal_cont=np.sin(2*np.pi*f*t_cont)
fs1=25
fs2=15
fs3=10

plt.subplot(3,1,1)
plt.stem(t_cont,singnal_cont)
plt.title("Main signal")

def sampl_and_plot(fs,indx):
    t_samp=np.arange(0,1,1/fs)
    singnal_samp=np.sin(2*np.pi*f*t_samp)
    plt.subplot(3,1,indx)
    plt.plot(t_cont,singnal_cont,"k-",label ="Original signal")
    plt.stem(t_samp,singnal_samp,linefmt='r-',markerfmt='ro',basefmt=' ',label='sampled @ {fs} hz')
    plt.title(f"samples as {fs} Hz")

plt.figure(figsize=(10,8))
sampl_and_plot(fs1,1)
sampl_and_plot(fs2,2)
sampl_and_plot(fs3,3)

plt.tight_layout()
plt.show()