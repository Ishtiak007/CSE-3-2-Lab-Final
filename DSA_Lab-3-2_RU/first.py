import numpy as np
import matplotlib.pyplot as plt

# Original continuous-time signal: x(t) = 3cos(100πt) → f = 50 Hz
f = 50       # Analog signal frequency in Hz
A = 3        # Amplitude

# Time duration to visualize (0 to 0.05 sec → one or more cycles)
t = np.linspace(0, 0.05, 1000)
x_t = A * np.cos(2 * np.pi * f * t)

# Two sampling rates
fs1 = 200  # Hz → Good (above Nyquist: 2*f = 100 Hz)
fs2 = 75   # Hz → Below Nyquist → Aliasing expected

# Sampling periods
T1 = 1 / fs1
T2 = 1 / fs2

# Sampling time vectors
n1 = np.arange(0, 0.05, T1)
n2 = np.arange(0, 0.05, T2)

# Discrete-time signals (samples)
x_n1 = A * np.cos(2 * np.pi * f * n1)
x_n2 = A * np.cos(2 * np.pi * f * n2)

# Plotting
plt.figure(figsize=(10, 6))

# Continuous signal
plt.plot(t, x_t, 'k-', label='x(t) = 3cos(100πt)', linewidth=1)

# Sampled at 200 Hz
plt.stem(n1, x_n1, linefmt='r-', markerfmt='ro', basefmt=' ', label='Sampled at 200 Hz')

# Sampled at 75 Hz
plt.stem(n2, x_n2, linefmt='b-', markerfmt='bo', basefmt=' ', label='Sampled at 75 Hz')

plt.title('Sampling of x(t) = 3cos(100πt) at 200 Hz and 75 Hz')
plt.xlabel('Time (sec)')
plt.ylabel('Amplitude')
plt.legend()
plt.grid(True)
plt.tight_layout()
plt.show()
