"""
dp[i]: 카드를 i개 구매 했을 때 가격의 최댓값

카드를 i개 구매하는 경우의수(아래 두 가지중 최댓값 비교)
1. i개짜리 카드팩 구매
2. i-N개를 구매 했을 때 가격의 최댓값 + N개짜리 카드팩 구매

"""
import sys

input = sys.stdin.readline


def main() -> None:
    N = int(input().rstrip('\n'))
    card = list(map(int, input().rstrip('\n').split(' ')))

    dp = [0] * (N + 1)
    dp[1] = card[0]

    for i in range(2, N + 1):
        max_cost = 0
        for j in range(1, i):
            max_cost = max(max_cost, dp[i - j] + card[j - 1])

        dp[i] = max(card[i - 1], max_cost)

    print(dp[N])


if __name__ == "__main__":
    main()
