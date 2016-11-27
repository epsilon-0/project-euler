factorial = [1]

for i in range(1, 1001):
  factorial.append(factorial[-1]*i)

def sumOfDigits(k):
  ans = 0
  n = k
  while(n > 0):
    ans += n%10
    n = n//10
  return ans

t = int(input())

for tests in range(t):
  n = int(input())
  print(sumOfDigits(factorial[n]))