"""
dp[i]: i번째 위치에서 구할 수 있는 가장 큰 값.
(이전에 값들을 모두 더한 값, 현재 값)을 비교하여 더 큰 값으로 업데이트 한다.
"""
import sys

input = sys.stdin.readline


def main() -> None:
    n = int(input().rstrip('\n'))
    arr = list(map(int, input().rstrip('\n').split(' ')))
    dp = [0] * n
    dp[0] = arr[0]

    for i in range(1, n):
        dp[i] = max(dp[i - 1] + arr[i], arr[i])  # dp[i-1]이 음수인 경우 더할 필요가 없다

    # print(max(dp))
    print(dp)


if __name__ == "__main__":
    main()
