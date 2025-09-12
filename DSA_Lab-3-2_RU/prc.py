import numpy as np
import matplotlib.pyplot as plt

# Signal parameters
f = 5
fs = 50
t = np.arange(0, 1, 1/fs)

# Signal: 5Hz + 15Hz sine waves
x_t = np.sin(2 * np.pi * f * t) + 0.5 * np.sin(2 * np.pi * 3 * f * t)

# 6-point averaging filter (moving average)
def avg_filter(x):
    y = np.zeros_like(x)
    N = 6
    for i in range(N-1, len(x)):
        y[i] = np.mean(x[i-N+1:i+1])
    return y

# 6-point differencing filter (simple difference)
def diff_filter(x):
    y = np.zeros_like(x)
    N = 6
    for i in range(N, len(x)):
        y[i] = x[i] - x[i-N]
    return y

y_avg = avg_filter(x_t)
y_diff = diff_filter(x_t)

# Plotting
plt.figure(figsize=(12, 6))

plt.subplot(3,1,1)
plt.plot(t, x_t)
plt.title("Sampled Analog Signal")
plt.grid()

plt.subplot(3,1,2)
plt.plot(t, y_avg, color='orange')
plt.title("6-point Averaging Filter Output")
plt.grid()

plt.subplot(3,1,3)
plt.plot(t, y_diff, color='green')
plt.title("6-point Differencing Filter Output")
plt.grid()

plt.tight_layout()
plt.show()
