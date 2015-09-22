from fractions import Fraction
import sys
for s in sys.stdin:
	n = Fraction(s).denominator
	if (n &(n-1) == 0):
		print "Exact."
	else:
		print "Some precision lost."