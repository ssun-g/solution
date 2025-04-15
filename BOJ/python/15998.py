"""
dp[i] : i를 1, 2, 3의 합으로 나타내는 방법.

다음과 같은 3가지 방법이 가능함.
  - (i-1) + 1
  - (i-2) + 2
  - (i-3) + 3

dp[i] = dp[i-1] + dp[i-2] + dp[i-3]
"""
import sys

input = sys.stdin.readline


def main() -> None:
    T = int(input().rstrip('\n'))

    # 미리 dp 배열을 만들어 놓는다.(시간초과 해결)
    dp = [0] * 4
    dp[1] = 1
    dp[2] = 2
    dp[3] = 4
    for i in range(4, 1000001):
        dp.append((dp[i - 1] + dp[i - 2] + dp[i - 3]) % 1000000009)

    for _ in range(T):
        n = int(input().rstrip('\n'))
        print(dp[n] % 1000000009)


if __name__ == "__main__":
    main()
