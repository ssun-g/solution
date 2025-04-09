"""
시작점(0, 0)부터 목적지(N-1, M-1)까지 dfs로 탐색하면서 경로를 추가해준다.
이미 방문한 경우 메모이제이션을 통해 최적화.

주의:
- 기저 조건이 <목적지 도착>이므로 결과값은 dp[0][0]에 저장된다.
- 경우의 수 = 0인 경우가 있으므로 dp를 -1로 초기화 하자.
"""
import sys

sys.setrecursionlimit(10 ** 7)
input = sys.stdin.readline

move_x = [0, 0, -1, 1]
move_y = [-1, 1, 0, 0]

M, N = map(int, input().rstrip('\n').split(' '))
maps = [list(map(int, input().rstrip('\n').split(' '))) for _ in range(M)]
dp = [[-1] * N for _ in range(M + 1)]


def dfs(x, y) -> int:
    # 목적지 도달시
    if (x == N - 1) and (y == M - 1):
        return 1

    # 이미 방문한 적이 있는 경우
    if dp[y][x] != -1:
        return dp[y][x]

    count = 0
    for dx, dy in zip(move_x, move_y):
        nx = x + dx
        ny = y + dy
        if (0 <= nx < N) and (0 <= ny < M) and (maps[ny][nx] < maps[y][x]):
            count += dfs(nx, ny)

    dp[y][x] = count
    return dp[y][x]


def main() -> None:
    dfs(0, 0)
    print(dp[0][0])


if __name__ == "__main__":
    main()
