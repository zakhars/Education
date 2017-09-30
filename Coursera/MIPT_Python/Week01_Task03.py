import sys

num_steps = int(sys.argv[1])
symbol = '#'

for step in range(1, num_steps + 1):
    num_spaces = num_steps - step
    for space in range (num_spaces):
        sys.stdout.write(' ')
    for sym in range(step):
        sys.stdout.write(symbol)
    if (step < num_steps):
        print('')

#Teacher's solution
for i in range(num_steps):
    print(" " * (num_steps - i - 1), "#" * (i + 1), sep="")