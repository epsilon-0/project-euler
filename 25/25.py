from math import *

numTests = int(input())

for tt in range(numTests):
  n = int(input())
  logPhi = log((1 + sqrt(5))/2)
  m = ceil(( (log(10) * (n-1)) + (log(5)/2))/logPhi)
  print(m)