from pprint import pprint

def d1(v):
    return (v/983)*1000

def d2(v):
    return (v/6.73)

def d3(v):
    return (v/32.8)*1000

def deviation(measured, theoretical):
    return (measured - theoretical) / theoretical * 100

def dev_sum(m, t):
    arr = []
    for i in range(len(m)):
        arr.append(deviation(m[i], t[i]))
    return arr


def sum_par(resistances):
    s = 0
    for r in resistances:
        s+= 1/r
    return 1/s

#in kO
RL = [30, 150, 500, 1000, 2500, 3300, 4000, 10000, 25000, 70000, 300000]
Ri = 3300
E = 10.08

VL = []
for i in range(len(RL)):
    VL.append(E * RL[i] / (RL[i] + Ri))
#pprint(VL)

PL = []
for i in range(len(VL)):
    PL.append(1000* VL[i]**2 / RL[i])
#pprint(PL)

PT = []
for i in range(len(RL)):
    PT.append(1000 * E**2 / (Ri + RL[i]))
#pprint(PT)

EFF = []
for i in range(len(RL)):
    EFF.append(100* PL[i]/PT[i])
#pprint(EFF)

RL_m = [32.7, 147.5, 499.1, 1003, 2502, 3300, 3999, 10010, 25140, 70200, 307600]
VL_m = [0.09, 0.435, 1.33, 2.367, 4.369, 5.058, 5.549, 7.60, 8.92, 9.58, 9.97]
R = 3.264

PL_m = []
for i in range(len(VL)):
    PL_m.append(1000* VL_m[i]**2 / RL_m[i])
#pprint(PL_m)

PT_m = []
for i in range(len(RL)):
    PT_m.append(1000 * E**2 / (Ri + RL_m[i]))
#pprint(PT_m)

EFF_m = []
for i in range(len(RL)):
    EFF_m.append(100* PL_m[i]/PT_m[i])
pprint(EFF_m)
