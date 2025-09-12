import numpy as np
import matplotlib.pyplot as plt

# Random signal with noise
np.random.seed(0)
t = np.linspace(0, 1, 200)
x = np.sin(2 * np.pi * 5 * t) + 0.5 * np.random.randn(len(t))

# 6-point Averaging Filter
def avg(y):
    y_avg = np.zeros_like(y, dtype=float)
    for n in range(5, len(y)):
        y_avg[n] = np.sum(y[n-5:n+1]) / 6
    return y_avg

# 6-point Differencing Filter
def diff(y):
    y_diff = np.zeros_like(y, dtype=float)
    for n in range(len(y)):
        if n >= 5:
            y_diff[n] = (y[n] - y[n-1] + y[n-2] - y[n-3] + y[n-4] - y[n-5]) / 6
    return y_diff

# Apply filters
y_avg = avg(x)
y_diff = diff(x)

# Plotting
plt.figure(figsize=(10, 8))

plt.subplot(3, 1, 1)
plt.plot(t, x, label='Original', color='gray')
plt.title('Original Signal')
plt.grid(True)

plt.subplot(3, 1, 2)
plt.plot(t, y_avg, label='Averaging Filter', color='green')
plt.title('6-Point Averaging Filter Output')
plt.grid(True)

plt.subplot(3, 1, 3)
plt.plot(t, y_diff, label='Differencing Filter', color='red')
plt.title('6-Point Differencing Filter Output')
plt.grid(True)

plt.tight_layout()
plt.show()
