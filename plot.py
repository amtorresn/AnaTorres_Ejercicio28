import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D

data = np.loadtxt("datos.dat")
x = np.arange(0,200,1)
y = np.arange(0,101,1)
fig = plt.figure()

plt.subplot(1,2,1)
plt.imshow(data)
plt.xlabel("Indice X")
plt.ylabel("Indice T")
plt.xlim(0,200)

plt.subplot(1,2,2)

x = np.arange(0, 2, 0.01)
y = data[0,:]
y2 = data[-1,:]
plt.plot(x,y, label = "Tiempo inicial")
plt.plot(x,y2, label = "Tiempo final")
plt.xlabel("Indice X")
plt.ylabel("Temperatura")
plt.legend()
plt.savefig("fig.png")