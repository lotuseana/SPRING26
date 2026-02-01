def d(measured, theory):
    return 100*(measured-theory)/theory

print(d(23,22))
print(d(80.2, 68))
print(d(148.1, 150))
print(d(299.8, 300))
print(d(628.6, 588))
print(d(1.227, 1.2))
print(d(2.668, 2.7))
print(d(8.89, 8.2))
print(d(9.88, 10))
print(d(30, 30))
print(d(831, 680))
print(d(5.17, 5.1))