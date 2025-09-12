import numpy as np
import matplotlib.pyplot as plt

fs=1000
t=np.arange(0,1,1/fs)
signal_clean = np.sin(2*np.pi*50*t)
noise = 0.5*np.sin(2*np.pi*300*t)
signal_noisy= signal_clean+noise

def manual_convolution(x,h):
    N=len(x)
    M=len(h)
    y=np.zeros(N+M-1)

    for n in range(len(y)):
        for k in range(N):
            if 0<=n-k<M:
                y[n]+=x[k]*h[n-k]
    return y

def hanning(N):
    n=np.arange(N)
    return 0.5*(1-np.cos((2*np.pi*n)/N-1))

def lowpassfilter (N,fc,fs):
    n=np.arange(N)
    h=np.sinc(2*fc*(n-(N-1)/2)/fs)*hanning(N)
    h/=np.sum(h)
    return h


h=lowpassfilter(N=31,fc=10,fs=fs)
y=manual_convolution(signal_noisy,h)
t1=np.arange(len(y))/fs

plt.plot(t,signal_noisy,label="Noisy Signal",color='r')
plt.plot(t1,y,label="Filtered signal",color="g")
plt.title("FIR Filter")
plt.grid(True)
plt.legend()
plt.show()