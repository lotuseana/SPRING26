
def gcd(a, b):
    #euclids algorithm
    while (b != 0):
        t = b
        b = a % b
        a = t
    return a

def lcm(a, b):
    return abs(a*b) // gcd(a, b)

def simplify_frac(f):
    f_split = f.split("/")
    divisor = gcd(int(f_split[0]), int(f_split[1]))
    f_split[0] = int(f_split[0]) // divisor
    f_split[1] = int(f_split[1]) // divisor
    return f_split

class GenericMatrix(object):
    def __add__(self, other):
        return None
    def __mul__(self, other):
        return None
    def __addMatrix__(self, other):                             
        # Element-wise matrix addition (same dimensions).
        if len(self.matrix) != len(other.matrix) or (len(self.matrix) > 0 and len(self.matrix[0]) != len(other.matrix[0])):
            return None

        result = []
        for i in range(len(self.matrix)):
            row = []
            for j in range(len(self.matrix[0])):
                row.append(self.__add__(self.matrix[i][j], other.matrix[i][j]))
            result.append(row)
        return result
    def __multiplyMatrix__(self, other):
        result = []
        n = len(self.matrix[0])
        for i in range(len(self.matrix)):
            row = []
            for j in range(len(other.matrix[0])):
                element = self.__zero__()
                for k in range(n):
                    element = self.__add__(
                        element,
                        self.__mul__(self.matrix[i][k], other.matrix[k][j]),
                    )
                row.append(element)
            result.append(row)
        return result
    def __str__(self):
        return str(self.matrix)
    
class IntegerMatrix(GenericMatrix):
    def __init__(self, matrix):
        self.matrix = matrix
    def __add__(self, a, b):
        return a + b
    def __mul__(self, a, b):
        return a * b
    def __zero__(self):
        return 0
    
class RationalMatrix(GenericMatrix):
    def __init__(self, matrix):
        self.matrix = matrix
    def __add__(self, a, b):
        a = simplify_frac(a)
        b = simplify_frac(b)
        denom = lcm(a[1], b[1])
        a_num = a[0] * (denom // a[1])
        b_num = b[0] * (denom // b[1])
        return str(a_num + b_num) + "/" + str(denom)

    def __mul__(self, a, b):
        a = simplify_frac(a)
        b = simplify_frac(b)
        return str(a[0] * b[0]) + "/" + str(a[1] * b[1])
    
    def __zero__(self):
        return "0/1"

def main():
    m1 = [[1, 2, 3],  
          [4, 5, 6],                  
          [1, 1, 1]]     
    
    m2 = [[1, 1, 1],                     
          [2, 2, 2], 
          [0, 0, 0]]
    
    a = IntegerMatrix(m1)
    b = IntegerMatrix(m2)

    print(a, "*", b, "=", a.__addMatrix__(b))
    print(a, "*", b, "=", a.__multiplyMatrix__(b))

    m3 = [['1/5', '1/6', '1/7'],  
          ['2/5', '1/3', '2/7'],                  
          ['3/5', '1/2', '3/7']]
    
    m4 = [['1/6', '1/7', '1/8'],  
         ['1/3', '2/7', '1/4'],                  
         ['1/2', '3/7', '3/8']]
    
    c = RationalMatrix(m3)
    d = RationalMatrix(m4)

    print(c, "*", d, "=", c.__addMatrix__(d))
    print(c, "*", d, "=", c.__multiplyMatrix__(d))

main()