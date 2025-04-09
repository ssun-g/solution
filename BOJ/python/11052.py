"""
dp[i]: 카드를 i개 구매 했을 때 가격의 최댓값

카드를 i개 구매할 때의 최댓값(아래 두 가지중 큰 값)
1. i개짜리 카드팩 가격
2. i-N개를 구매 했을 때 가격의 최댓값 + N개짜리 카드팩 가격

"""
import sys

input = sys.stdin.readline


def main() -> None:
    N = int(input().rstrip('\n'))
    card = list(map(int, input().rstrip('\n').split(' ')))

    dp = [0] * (N + 1)
    dp[1] = card[0]  # card[0]: 1개짜리 카드팩 가격

    for i in range(2, N + 1):
        max_cost = 0
        
        # dp[i - j] + card[j - 1]: 카드를(i-j)개 구매 했을 때의 가격의 최댓값 + j개 짜리 카드팩 가격
        for j in range(1, i):
            max_cost = max(max_cost, dp[i - j] + card[j - 1])

        # card[i - 1]: i개 짜리 카드팩 가격
        dp[i] = max(card[i - 1], max_cost)

    print(dp[N])


if __name__ == "__main__":
    main()
