import sys

input = sys.stdin.readline

N, Q = map(int, input().rstrip('\n').split(' '))
quality = list(map(int, input().rstrip('\n').split(' ')))
joke = list(map(int, input().rstrip('\n').split(' ')))
calc = [1 for _ in range(len(quality))]

for i in range(N):
    calc[i] = quality[i % N] * quality[(i + 1) % N] * quality[(i + 2) % N] * quality[(i + 3) % N]

total = sum(calc)

for idx in joke:
    for i in range(idx - 3, idx + 1):
        calc[(i - 1) % N] *= -1
        total += 2 * calc[(i - 1) % N]
    print(total)
