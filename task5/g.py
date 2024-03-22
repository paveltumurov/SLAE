import matplotlib as plt
import matplotlib.pyplot as plt
import numpy as np
import csv
X,X1,X2,X3,X4,X5, X6, X7 = [], [], [], [], [], [], [], []
Y, Y1,Y2,Y3,Y4,Y5, Y6, Y7 = [], [], [], [], [], [], [], []
with open ('jac_it.txt', 'r') as datafile:
    plotting = csv.reader(datafile, delimiter=' ') 
    for ROWS in plotting:
        X.append(float(ROWS[0]))
        Y.append(float(ROWS[1]))
x1 = np.array(X)
y1 = np.array(Y)


with open ('gz_it.txt', 'r') as datafile:
    plotting = csv.reader(datafile, delimiter=' ') 
    for ROWS in plotting:
        X1.append(float(ROWS[0]))
        Y1.append(float(ROWS[1]))

with open ('mpi_it.txt', 'r') as datafile:
    plotting = csv.reader(datafile, delimiter=' ') 
    for ROWS in plotting:
        X2.append(float(ROWS[0]))
        Y2.append(float(ROWS[1]))
with open ('cheb.txt', 'r') as datafile:
    plotting = csv.reader(datafile, delimiter=' ') 
    for ROWS in plotting:
        X6.append(float(ROWS[0]))
        Y6.append(float(ROWS[1]))

with open ('jac_time.txt', 'r') as datafile:
    plotting = csv.reader(datafile, delimiter=' ') 
    for ROWS in plotting:
        X3.append(float(ROWS[0]))
        Y3.append(float(ROWS[1]))

with open ('gz_time.txt', 'r') as datafile:
    plotting = csv.reader(datafile, delimiter=' ') 
    for ROWS in plotting:
        X4.append(float(ROWS[0]))
        Y4.append(float(ROWS[1]))
with open ('mpi_time.txt', 'r') as datafile:
    plotting = csv.reader(datafile, delimiter=' ') 
    for ROWS in plotting:
        X5.append(float(ROWS[0]))
        Y5.append(float(ROWS[1]))
with open ('cheb_time.txt', 'r') as datafile:
    plotting = csv.reader(datafile, delimiter=' ') 
    for ROWS in plotting:
        X7.append(float(ROWS[0]))
        Y7.append(float(ROWS[1]))


graph, ax = plt.subplots(figsize=(8,6),dpi=400)
# ax.axis(xmin=50, xmax=215, ymin=50, ymax=215)
ax.set_ylabel('Норма невязки')
ax.set_xlabel('Количесвто итераций')
ax.minorticks_on()
ax.grid(which='major')
ax.grid(which='minor', linestyle=':')
ax.plot(X, Y, label="Метод Якоби")
ax.plot(X1, Y1, label="метод Гаусса-Зейделя")
ax.plot(X2, Y2, label="метод простых итераций")
ax.plot(X6, Y6, label="Чебышевское ускорение")
ax.plot()
ax.legend()
graph.savefig('iter.png')

graph, ax = plt.subplots(figsize=(8,6),dpi=400)
# ax.axis(xmin=50, xmax=215, ymin=50, ymax=215)
ax.set_ylabel('время')
ax.set_xlabel('tolerance')
ax.minorticks_on()
ax.grid(which='major')
ax.grid(which='minor', linestyle=':')
ax.plot(X3, Y3, label="Метод Якоби")
ax.plot(X4, Y4, label="метод Гаусса-Зейделя")
ax.plot(X5, Y5, label="метод простых итераций")
ax.plot(X7, Y7, label="Чебышевское ускорение")
ax.plot()
ax.legend()
graph.savefig('time.png')





# graph, ax = plt.subplots(figsize=(8,6),dpi=400)
# # ax.axis(xmin=50, xmax=215, ymin=50, ymax=215)
# ax.set_ylabel('$r^2(m)$, мм$^{2}$')
# ax.set_xlabel('$m$')
# ax.minorticks_on()
# ax.grid(which='major')
# ax.grid(which='minor', linestyle=':')
# ax.plot(x1, y1, label="csr 1%")
# ax.plot(X3, Y3, label="dense 1%")
# graph.savefig('graph2.png')


# ax.savefig('graph1.png')

# plt.plot(X2, Y2, label="csr 10%")
# plt.plot(X4, Y4, label="dense 10%")
# plt.savefig('graph2.png')