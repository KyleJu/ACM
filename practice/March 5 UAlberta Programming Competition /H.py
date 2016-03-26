from fractions import Fraction
import fileinput

first = True
for line in fileinput.input():
    if first:
        first = False
        continue
    f = Fraction(line.replace(' ', ''))
    if (100000000 % f.denominator == 0):
        print('{:.08f}'.format(float(f)))
    else:
        print("ERROR")