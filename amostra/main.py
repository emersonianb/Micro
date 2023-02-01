import numpy as np
import matplotlib.pyplot as plt

Fs = 80000
f = 400
amplitude = 620
norm_f  = f/Fs
N = 1/norm_f
n = np.arange(N)

y = (np.sin(2*np.pi*n*norm_f))

table = np.round((2047+y*amplitude)).astype(int)
print(",".join(map(str, table)))
print('Table Size', y.size)

plt.plot(table)
plt.show()