import sys

input = sys.stdin.readline


def main() -> None:
    T = int(input().rstrip('\n'))
    for _ in range(T):
        N = int(input().rstrip('\n'))
        if N == 0:
            print(1, 0)
        elif N == 1:
            print(0, 1)
        else:
            dp = [[0, 0]] * (N + 1)  # [0개수, 1개수]
            dp[0] = [1, 0]  # 초기값
            dp[1] = [0, 1]  # 초기값
            for i in range(2, N + 1):
                dp[i] = [dp[i - 1][0] + dp[i - 2][0], dp[i - 1][1] + dp[i - 2][1]]

            print(dp[N][0], dp[N][1])


if __name__ == "__main__":
    main()
