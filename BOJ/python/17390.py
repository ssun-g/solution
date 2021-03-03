import sys

input = sys.stdin.readline

N, Q = map(int, input().rstrip("\n").split(" "))

# index의 시작이 1이기 때문에 arr의 크기를 1 늘려준다.
# 그 후, 정렬을 통해 비내림차순 수열을 만들어 준다.
arr = list(map(int, input().rstrip("\n").split(" ")))
arr.append(0)
arr = sorted(arr)

part_sum = [0 for _ in range(len(arr))]

for i in range(1, N + 1):
    part_sum[i] = arr[i] + part_sum[i - 1]

for _ in range(Q):
    L, R = map(int, input().rstrip("\n").split(" "))
    print(part_sum[R] - part_sum[L - 1]) # L ~ R 까지의 합.
