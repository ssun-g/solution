"""
dp[i][j] : 길이가 i이고 마지막 숫자가 j일 때 가능한 오르막 수의 개수
"""
import sys

input = sys.stdin.readline


def main() -> None:
    N = int(input().rstrip('\n'))
    dp = [[0] * 10 for _ in range(N + 1)]

    # 초기값 (길이가 1인 경우)
    for i in range(10):
        dp[1][i] = 1

    # bottom-up
    for i in range(2, N + 1):  # 길이가 2~N까지
        for j in range(10):  # 마지막 숫자가 0~9
            for k in range(j, 10):
                # 길이가 i-1일 때의 마지막 숫자가 j라면, 길이가 i일 때의 마지막 숫자 k의 범위는(j~9)
                dp[i][j] += dp[i - 1][k]
                dp[i][j] %= 10007

    # sum(dp[N]): 길이가 N일 때의 오르막 수의 개수의 합
    print(sum(dp[N]) % 10007)


if __name__ == "__main__":
    main()
