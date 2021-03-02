import sys
input = sys.stdin.readline

def solve(length, ants):
    fast_time = late_time = 0
    for i in range(len(ants)):
        fast_time = max(fast_time, min(abs(length - ants[i]), ants[i]))  # 각 개미의 최단 시간
        late_time = max(late_time, max(abs(length - ants[i]), ants[i]))  # 각 개미의 최장 시간

    return fast_time, late_time


tc = int(input())
for i in range(tc):
    length, num_of_ants = map(int, input().split())
    ants = [int(input()) for k in range(num_of_ants)]
    fast, last = solve(length, ants)
    print(fast, last)
