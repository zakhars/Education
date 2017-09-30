import sys

snum = sys.argv[1]
sum = 0
for c in snum:
    sum += int(c)
print(sum)

#Teacher's solution:
print(sum([int(x) for x in sys.argv[1]]))