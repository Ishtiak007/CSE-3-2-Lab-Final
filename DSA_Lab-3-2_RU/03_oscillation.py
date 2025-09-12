import numpy as np
import matplotlib.pyplot as plt

n = np.arange(0, 20)  # সময়
x1 = np.sin(np.pi * n)         # ω = π
x2 = np.sin((np.pi/2) * n)     # ω = π/2
x3 = np.sin((np.pi/4) * n)     # ω = π/4

plt.stem(n, x1, linefmt='r-', markerfmt='ro', basefmt=' ', label="ω=π")
plt.stem(n, x2, linefmt='g-', markerfmt='go', basefmt=' ', label="ω=π/2")
plt.stem(n, x3, linefmt='b-', markerfmt='bo', basefmt=' ', label="ω=π/4")
plt.legend()
plt.title("Rate of Oscillation for Different ω")
plt.grid(True)
plt.show()
