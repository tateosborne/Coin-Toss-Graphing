import sys
import matplotlib.pyplot as plt

x = sys.argv[0] + 1
tossNum = [None] * x
dollars = [None] * x

for idx in range(0, x):
    tossNum[idx] = idx
    dollars[idx] = sys.argv[idx]

plt.plot(tossNum, dollars, color = 'blue', marker = 'o')
plt.title('Money Summary Per Toss')
plt.xlabel('Toss Number')
plt.ylabel('Amount of Money')
plt.grid(True)
plt.show()
