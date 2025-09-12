import numpy as np
import matplotlib.pyplot as plt

def unit_step(n):
    return np.array([1 if i>=0 else 0 for i in n])

def manual_convolution(x,h):
    N=len(x)
    M=len(h)
    y=np.zeros(N+M-1)

    for n in range(len(y)):
        for k in range(N):
            if 0<=n-k<M:
                y[n]+=x[k]*h[n-k]
    return y

n=np.arange(0,10)
x=unit_step(n)
h=unit_step(n)-unit_step(n-5)

y=manual_convolution(x,h)

n_y=np.arange(0,len(y))

plt.figure(figsize=(10,8))

plt.subplot(3,1,1)
plt.stem(n,x,basefmt=" ",linefmt='k-',markerfmt='ko')
plt.title("Input X[n]=u(n)")
plt.xlabel("n")
plt.ylabel("x[n]")
plt.grid(True)

plt.subplot(3,1,2)
plt.stem(n,h,basefmt=" ",linefmt='r-',markerfmt='ro')
plt.title("Impulse responce h[n]=u(n)-u(n-5)")
plt.xlabel("n")
plt.ylabel("y[n]")
plt.grid(True)

plt.subplot(3,1,3)
plt.stem(n_y, y, basefmt=" ", linefmt='g-', markerfmt='go')
plt.title("Output y[n] = x[n] * h[n]")
plt.xlabel("n")
plt.ylabel("y[n]")
plt.grid(True)



plt.tight_layout()
plt.show()