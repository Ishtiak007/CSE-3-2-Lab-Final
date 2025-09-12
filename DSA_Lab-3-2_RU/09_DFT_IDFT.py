import numpy as np
import matplotlib.pyplot as plt
N=50
n=np.arange(N)
fs=8000
t=n/fs

def dft(x):
    N=len(x)
    X=np.zeros(N,dtype=complex)
    for k in range(N):
        for n in range(N):
            X[k]+=x[n]*np.exp(-2j*np.pi*k*n/N)
    return X

def idft(X):
    N=len(X)
    x=np.zeros(N,dtype=complex)
    for n in range(N):
        for k in range(N):
            x[n]+=X[k]*np.exp(2j*np.pi*k*n/N)
        x[n]/=N
    return x

x=np.sin(2*np.pi*1000*t)+0.5*np.sin(2*np.pi*2000*t+4*np.pi)
hannig_window=0.5*(1-np.cos(2*np.pi*n/(N-1)))
x_window=x*hannig_window

x_dft=dft(x)
window_dft=dft(x_window)
freq = np.arange(N) * fs / N
plt.figure(figsize=(14, 10))

plt.subplot(3, 2, 1)
plt.plot(t, x, label="Original", color="g")
plt.plot(t, x_window, label="Windowed", color="r")
plt.title("Time-domain Signal")
plt.grid(True)
plt.legend()

plt.subplot(3, 2, 2)
plt.stem(n, hannig_window, basefmt=" ", label="Hanning Window")
plt.title("Hanning Window")
plt.grid(True)
plt.legend()

plt.subplot(3, 2, 3)
plt.stem(freq[:N//2], np.abs(x_dft)[:N//2], basefmt=" ", label="DFT")
plt.title("DFT Magnitude")
plt.grid(True)
plt.legend()

plt.subplot(3, 2, 4)
plt.stem(freq[:N//2], np.angle(x_window)[:N//2], basefmt=" ", linefmt="r-", markerfmt="ro", label="Phase with Window")
plt.title("Phase Spectrum with Hanning")
plt.grid(True)
plt.legend()

x_reconstructed = idft(x)
x_reconstructed_windowed = idft(x_window)

plt.subplot(3, 2, 5)
plt.plot(t, x_reconstructed.real, label="IDFT", color="g")
plt.plot(t, x_reconstructed_windowed.real, label="IDFT + Hanning", color="r")
plt.title("Reconstructed Signal")
plt.grid(True)
plt.legend()


plt.tight_layout()
plt.show()



