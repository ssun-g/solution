"""

메모리 제한에 주의할 것.

숫자가 3개로 고정되어 있으므로 1149번 문제와 비슷한 방법을 사용
list를 선언하지 않고 dp를 구현하면 된다.

"""
import sys

input = sys.stdin.readline

N = int(input())

max_a = max_b = max_c = min_a = min_b = min_c = 0

for i in range(N):
    a, b, c = map(int, input().rstrip('\n').split(' '))
    min_a, min_b, min_c = a, b, c
    
    if i == 0:
        max_prev_a, max_prev_b, max_prev_c = a, b, c
        min_prev_a, min_prev_b, min_prev_c = a, b, c
        continue

    a += max(max_prev_a, max_prev_b)
    b += max(max_prev_a, max_prev_b, max_prev_c)
    c += max(max_prev_b, max_prev_c)

    min_a += min(min_prev_a, min_prev_b)
    min_b += min(min_prev_a, min_prev_b, min_prev_c)
    min_c += min(min_prev_b, min_prev_c)

    max_prev_a, max_prev_b, max_prev_c = a, b, c
    min_prev_a, min_prev_b, min_prev_c = min_a, min_b, min_c

print(max(a, b, c), min(min_a, min_b, min_c))
