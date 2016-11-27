t = int(input())

for tests in range(t):
  p = str(2**int(input()))
  ans = 0
  for c in p:
    ans += int(c)
  print(ans)
