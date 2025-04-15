"""
dp[i]: i개의 자리가 있을 때, 바꿔 앉을 수 있는 경우의 수
"""
import sys

input = sys.stdin.readline


def main() -> None:
    N = int(input().rstrip('\n'))

    # 가짓수 저장
    dp = [0] * (N + 1)
    dp[0] = 1
    dp[1] = 1
    for i in range(2, N + 1):
        dp[i] = dp[i - 1] + dp[i - 2]

    M = int(input().rstrip('\n'))

    # 바꿔 앉는 개수 구하기
    total = 1
    lastest = 0
    for _ in range(M):
        vip = int(input().rstrip('\n'))
        total *= dp[vip - lastest - 1]
        lastest = vip

    if lastest != N:
        print(total * dp[N - lastest])
    else:
        print(total)


if __name__ == "__main__":
    main()
