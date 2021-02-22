N, L = map(int, input().split())
answer = 0
for i in range(N):
    D, R, G = map(int, input().split())
    rest = (D + answer) % (R + G)
    if rest <= R:
        answer += R - rest
print(answer+L)
