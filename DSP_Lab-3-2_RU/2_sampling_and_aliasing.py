import numpy as np
import matplotlib.pyplot as plt
f_signal = 10  # Hz

t_cont=np.linspace(0,1,1000)
signal_cont=np.sin(2*np.pi*f_signal*t_cont)
fs1=25  # Good sampling (no aliasing)
fs2=15  # Some aliasing
fs3=10  # High chance of aliasing



# plt.subplot(3,1,1)
# plt.stem(t_cont,signal_cont)
# plt.title("Main signal")


def sample_and_plot(fs, indx):
    t_samp=np.arange(0,1,1/fs)
    signal_samp=np.sin(2*np.pi*f_signal*t_samp)

    plt.subplot(3,1,indx)
    plt.plot(t_cont,signal_cont,"k-",label="Original signal")
    plt.stem(t_samp,signal_samp,linefmt='r-',markerfmt='ro',basefmt=' ',label=f'sampled @ {fs} hz')
    plt.legend()
    plt.title(f"sampled as {fs} Hz")

plt.figure(figsize=(10,8))
sample_and_plot(fs1,1)
sample_and_plot(fs2, 2)
sample_and_plot(fs3, 3)


plt.tight_layout()
plt.show()
