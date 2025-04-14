"""
dp[y][x] : (x, y) 위치에서 얻을 수 있는 최댓값
"""
import sys

input = sys.stdin.readline


def main() -> None:
    n = int(input().rstrip('\n'))
    arr = [[-1] * n for _ in range(n)]
    dp = [[-1] * n for _ in range(n)]
    for i in range(n):
        num = list(map(int, input().rstrip('\n').split(' '))) + ([-1] * (n - i - 1))
        arr[i] = num

    # 초기값
    dp[0][0] = arr[0][0]
    for y in range(1, n):
        dp[y][0] = dp[y - 1][0] + arr[y][0]
    for x in range(1, n):
        dp[x][x] = dp[x - 1][x - 1] + arr[x][x]

    # 값 채우기
    for y in range(2, n):
        for x in range(1, y + 1):
            dp[y][x] = max(dp[y - 1][x - 1], dp[y - 1][x]) + arr[y][x]  # 이전 숫자 중 큰 값만 선택 한다.

    print(max(map(max, dp)))


if __name__ == "__main__":
    main()
