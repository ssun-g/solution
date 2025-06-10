import sys

input = sys.stdin.readline


def main() -> None:
    T = int(input().rstrip("\n"))
    dp = [0] * 101
    dp[1] = 1
    dp[2] = 1
    dp[3] = 1
    for i in range(4, 101):
        dp[i] = dp[i - 2] + dp[i - 3]

    for _ in range(T):
        N = int(input().rstrip("\n"))
        print(dp[N])


if __name__ == "__main__":
    main()
