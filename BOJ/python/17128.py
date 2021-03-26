import sys

input = sys.stdin.readline

N, Q = map(int, input().rstrip('\n').split(' '))
quality = list(map(int, input().rstrip('\n').split(' ')))
joke = list(map(int, input().rstrip('\n').split(' ')))
calc = [1 for _ in range(len(quality))]

# i번째 S = A_i * A_i+1 * A_i+2 * A_i+3
for i in range(N):
    calc[i] = quality[i % N] * quality[(i + 1) % N] * quality[(i + 2) % N] * quality[(i + 3) % N]

total = sum(calc)

for idx in joke:
    for i in range(idx - 3, idx + 1):
        calc[(i - 1) % N] *= -1 # python은 음수 index가 가능하기 때문에 나머지를 그냥 넣어줘도 된다.
        total += 2 * calc[(i - 1) % N]
    print(total)
