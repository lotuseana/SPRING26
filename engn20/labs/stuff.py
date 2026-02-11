def d1(v):
    return (v/983)*1000

def d2(v):
    return (v/6.73)

def d3(v):
    return (v/32.8)*1000

def deviation(measured, theoretical):
    return (measured - theoretical) / theoretical * 100


""""
print(d1(2.048));
print(d1(4.08));
print(d1(6.06));
print(d1(8.03));
print(d1(10.04));
print(d1(12.10));
"""

"""
print(d2(2.043));
print(d2(4.04));
print(d2(6.02));
print(d2(8.05));
print(d2(10.03));
print(d2(12.06));
"""

"""
print(d3(2.078));
print(d3(4.00));
print(d3(5.98));
print(d3(8.01));
print(d3(10.00));
print(d3(12.07));
"""

print(deviation(2.05, 2.083))
print(deviation(4.17, 4.15))
print(deviation(6.15, 6.16))
print(deviation(8.14, 8.17))
print(deviation(10.22, 10.21))
print(deviation(12.25, 12.31))

print("\n")

print(deviation(274, 303.57))
print(deviation(570, 600.3))
print(deviation(860, 894.5))
print(deviation(1158, 1200))
print(deviation(1490, 1451))
print(deviation(1790, 1755))

print("\n")

print(deviation(63.2, 62.25))
print(deviation(121.6, 121.95))
print(deviation(185.3, 182.32))
print(deviation(246.6, 244.21))
print(deviation(305.2, 304.88))
print(deviation(365.6, 367.99))