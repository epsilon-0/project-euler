import datetime

tests = int(input())

for tt in range(tests):
  y1, m1, d1 = map(int, input().strip().split())
  y2, m2, d2 = map(int, input().strip().split())
  startYear = y1 % 2800
  endYear = startYear + y2 - y1
  startDate = datetime.date(startYear, m1, d1)
  endDate = datetime.date(endYear, m2, d2)
  count = 0
  while(startDate.day != 1):
    startDate = startDate + datetime.timedelta(days=1)
  while(startDate <= endDate):
    if(startDate.day == 1 and startDate.weekday() == 6):
      count += 1
    if(startDate.month <= 11):
      startDate = datetime.date(startDate.year, startDate.month + 1, 1)
    else:
      startDate = datetime.date(startDate.year + 1, 1, 1)
  print(count)