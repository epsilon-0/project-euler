numTests = int(raw_input())

l = [0,1]

mappedList = dict()
mappedList[1] = 1

countt = 2

while(str(l[-1]) != 5000):
  l.append(l[-1] + l[-2])
  l.pop(0)
  if len(str(l[-1])) not in mappedList:
    mappedList[len(str(l[-1]))] = countt
  countt += 1

for tt in range(numTests):
  n = int(raw_input())
  print(mappedList[n])