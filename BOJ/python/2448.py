import sys

input = sys.stdin.readline

N = int(input().rstrip("\n"))

arr = [[" " for _ in range(N * 2)] for _ in range(N)]


def star(y, x, size):
    if size == 0:
        return
    if size % 3 == 0:
        arr[y][x] = "*"
        arr[y + 1][x - 1] = "*"
        arr[y + 1][x + 1] = "*"
        arr[y + 2][x - 2] = "*"
        arr[y + 2][x - 1] = "*"
        arr[y + 2][x] = "*"
        arr[y + 2][x + 1] = "*"
        arr[y + 2][x + 2] = "*"

    next_size = size // 2

    star(y, x, next_size)
    star(y + next_size, x - next_size, next_size)
    star(y + next_size, x + next_size, next_size)


star(0, N - 1, N)

for i in range(N):
    print("".join(arr[i]))
