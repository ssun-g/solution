"""
dp[i][j] : (i, j)위치에 도달할 수 있는 경로의 개수
"""
import sys

input = sys.stdin.readline


def main() -> None:
    N = int(input().rstrip('\n'))
    board = [list(map(int, input().rstrip('\n').split(' '))) for _ in range(N)]

    dp = [[0] * N for _ in range(N)]
    dp[0][0] = 1

    for y in range(N):
        for x in range(N):
            step = board[y][x]
            if step == 0:
                continue

            if y + step < N:
                dp[y + step][x] += dp[y][x]
            if x + step < N:
                dp[y][x + step] += dp[y][x]

    print(dp[N - 1][N - 1])


if __name__ == "__main__":
    main()
