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


#in ohms
r1_1 = 986  
r2_1 = 2150
r3_1 = 4616
r_1 = [r1_1, r2_1, r3_1]

e_1 = 10.09

#in volts
va_th_1 = 10.09

#print(r1_1 + sum_par([r2_1, r3_1]))
r_tot_1 = 2452.80

#print(e_1/r_tot_1)
#in A
i_tot_1 = 0.00411

#print(va_th_1 - i_tot_1 * r1_1)
vb_th_1 = 6.038
vc_th_1 = 6.038

va_exp_1 = 10.09
vb_exp_1 = 6.036
vc_exp_1 = 6.036

ir1_th_1 = 0.00411
#print(i_tot_1 * (r3_1 / (r3_1 + r2_1)))
ir2_th_1 = 0.00280
#print(i_tot_1 * (r2_1 / (r3_1 + r2_1)))
ir3_th_1 = 0.00131

i_th_1 = [ir1_th_1, ir2_th_1, ir3_th_1]

ir1_exp_1 = 0.00411
ir2_exp_1 = 0.00280
ir3_exp_1 = 0.00131

i_exp_1 = [ir1_exp_1, ir2_exp_1, ir3_exp_1]

#print(dev_sum(i_exp_1, i_th_1))

r1_2 = 3255
r2_2 = 2155
r3_2 = 4623
r4_2 = 6830

r_series = 13608

e_2 = 20.07

vb_th_2 = 20.07
vc_th_2 = 20.07
#print(e_2 - e_2 * (r2_2/r_series))
vd_th_2 = 16.89
#print(e_2 * (r4_2/r_series))
ve_th_2 = 10.07

v_th_2 = [vb_th_2, vc_th_2, vd_th_2, ve_th_2]

vb_exp_2 = 20.05
vc_exp_2 = 20.05
vd_exp_2 = 16.87
ve_exp_2 = 10.05

v_exp_2 = [vb_exp_2, vc_exp_2, vd_exp_2, ve_exp_2]

#print(dev_sum(v_exp_2, v_th_2))

#print(sum_par([r1_2, r2_2+r3_2+r4_2]))
r_tot_2 = 2626.7
#print(e_2/r_tot_2)
is_th_2 = 0.00764
#print(is_th_2 * (r_tot_2/r1_2))
# print(is_th_2 * (r_tot_2/r_series))
ir1_th_2 = 0.00617
ir2_th_2 = 0.00147

i_th_2 = [is_th_2, ir1_th_2, ir2_th_2]

is_exp_2 = 0.00765
ir1_exp_2 = 0.0062
ir2_exp_2 = 0.00148

i_exp_2 = [is_exp_2, ir1_exp_2, ir2_exp_2]

print (sum_par([3.255, 10, 13.608]))

#print (dev_sum(i_exp_2, i_th_2))
