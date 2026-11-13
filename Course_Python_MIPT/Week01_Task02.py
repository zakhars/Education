import sys


s_num = sys.argv[1]
summa = 0
for c in s_num:
    summa += int(c)
print(summa)

# Teacher's solution:
print(sum([int(x) for x in sys.argv[1]]))
