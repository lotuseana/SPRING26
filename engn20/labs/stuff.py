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

# e in V
e1 = 8.09

# r in ohms
r1 = 982
r2 = 2152
r3 = 3274
r4 = 6720

r = [r1, r2, r3, r4]


T_V_A = 8.09
T_V_B = 8.09
T_V_C = 8.09
tv_1 = [T_V_A, T_V_B, T_V_C]

M_V_A = 8.08
M_V_B = 8.09
M_V_C = 8.08

mv_1 = [M_V_A, M_V_B, M_V_C]

#in ohms
R_TOT_TH = 674.30

#in mA
I_TOT_TH = 12.00

# print(e1/r1)
# print(e1/r2)
I_R1_TH = 8.24
I_R2_TH = 3.76

# print(I_TOT_TH * (R_TOT_TH/r1))    
# print(I_TOT_TH * (R_TOT_TH/r2))   
I_R1_TH_CDR = 8.24
I_R2_TH_CDR = 3.76
I_TOT_TH_CDR = 12.00

I_R2_M = 8.21
I_R2_M = 3.67

I_TOT_M = 11.83

# print(deviation)

e2 = 10.01

# for ri in r:
#     print(1000*e2/ri)

# print(deviation(8.21, 8.24))
# print(deviation(3.67, 3.76))
# print(deviation(11.83, 12))

I_TH_2 = [10.19, 4.65, 3.06, 1.49, 19.39, 4.55 ]

R_TOT_2 = sum_par(r)

# print(1000*e2/R_TOT_2)

I_TH_TOT_2 = 19.39

I_TH_IX = 4.55

I_M_2 = [10.22, 4.65, 3.06, 1.48, 19.21, 4.56]

print(dev_sum(I_M_2, I_TH_2))

# DEV_1 = [0.1387235610403899, 0.21933640901080342, -0.12808538781356146]

# r4 = 6.70
# r = [r1, r2, r3, r4]
# r_sum = sum(r)
# vdr = []

# e2 = 20

# # for ri in r:
# #     vdr.append(e2*(ri/r_sum))
# # print (vdr)
# v_ac = e2*((r1+r2)/r_sum)
# v_b = e2*((r2+r3+r4)/r_sum)

# # print(v_ac)
# # print(v_b)
# tv_2 = [1.5028636884306987, 3.2867506681939673, 4.977472317678503, 10.232913325696831, 4.789614356624666, 18.497136311569303]

# mv_2 = [1.504, 3.294, 4.986, 10.25, 4.798, 18.53]

# DEV_2 = [0.07560975609756189, 0.22056226765798873, 0.17132555998773188, 0.166977611940295, 0.17507971938775274, 0.17766906118404402]
