"""
dp[i]: i 날짜에서 얻을 수 있는 최대 이익

현재 날짜에 상담을 할 경우, 종료되는 위치에 이익을 업데이트.
오늘 상담할 경우 얻는 이익은 dp[i-1] + Pi
"""
import sys

input = sys.stdin.readline


def main() -> None:
    N = int(input().rstrip('\n'))
    day = [list(map(int, input().rstrip('\n').split(' '))) for _ in range(N)]
    dp = [0] * (N + 1)

    for i in range(1, N + 1):
        Ti, Pi = day[i - 1]

        # 오늘 상담할 경우 Ti일 이후 얻을 수 있는 이익 업데이트
        if (i + Ti - 1) < N + 1:
            dp[i + Ti - 1] = max(dp[i + Ti - 1], dp[i - 1] + Pi)

        # 어제보다 이익이 적은 경우 덮어 씌운다.
        dp[i] = max(dp[i], dp[i - 1])

    print(dp[N])


if __name__ == "__main__":
    main()
