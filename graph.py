import sys
import matplotlib.pyplot as plt

lastEntry = sys.argv[-1]
totalTosses = int(lastEntry)
toss = [None] * (totalTosses + 1)
dollars = [None] * (len(sys.argv) - 2)

for idx in range(0, totalTosses + 1):
    toss[idx] = idx

for idx in range(1, len(sys.argv) - 1):
    argStr = sys.argv[idx]
    dollars[idx - 1] = float(argStr)

plt.plot(toss, dollars, color = 'purple', marker = 'o')
plt.title('Money Summary Per Toss')
plt.xlabel('Toss Number')
plt.ylabel('Amount of Money (Dollars)')
plt.grid(True)
plt.show()
