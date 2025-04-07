"""
dp[r][c] : (r, c)에 도착 했을 때 가져올 수 있는 사탕 개수의 최댓값
"""
import sys

input = sys.stdin.readline


def main() -> None:
    N, M = map(int, input().rstrip('\n').split(' '))
    maze = [list(map(int, input().rstrip('\n').split(' '))) for _ in range(N)]

    dp = [[0] * M for _ in range(N)]
    dp[0][0] = maze[0][0]  # 시작점

    # 초기값(아래 이동)
    for r in range(1, N):
        dp[r][0] = dp[r - 1][0] + maze[r][0]

    # 초기값(오른쪽 이동)
    for c in range(1, M):
        dp[0][c] = dp[0][c - 1] + maze[0][c]

    # bottom-up
    for r in range(1, N):
        for c in range(1, M):
            # 도착 전 경로에서 가장 사탕을 많이 갖고 있는 경로 선택 + 현재 사탕개수
            dp[r][c] = max(dp[r - 1][c], dp[r][c - 1], dp[r - 1][c - 1]) + maze[r][c]

    print(dp[N - 1][M - 1])


if __name__ == "__main__":
    main()
