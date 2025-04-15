"""
dp[i][j]: i 위치에서 이동 횟수가 j일 때, 최대로 받을 수 있는 자두의 개수

각 위치에서 가능한 이동 횟수 조합을 모두 찾고, 그 중 가장 많이 받은 자두의 개수를 구한다.
- 이동 횟수가 짝수 : 1번 나무
- 이동 횟수가 홀수 : 2번 나무
"""
import sys

input = sys.stdin.readline


def main() -> None:
    T, W = map(int, input().rstrip('\n').split(' '))
    tree = [int(input().rstrip('\n')) for _ in range(T)]
    dp = [[0] * (T + 1) for _ in range(W + 1)]

    for t in range(1, T + 1):
        for w in range(W + 1):
            current_tree = tree[t - 1]  # 자두가 떨어질 위치
            current_pos = 1 if w % 2 == 0 else 2  # 이동 횟수가 짝수면 1번, 홀수면 2번 나무
            is_possible = 1 if current_tree == current_pos else 0  # 자두를 받을 수 있으면 1, 받을 수 없으면 0

            # 이전 위치에서 현재 위치로 올 때, 이동하지 않은 경우
            dp[w][t] = max(dp[w][t], dp[w][t - 1] + is_possible)

            # 이전 위치에서 현재 위치로 올 때, 이동한 경우
            if w > 0:  # W=0일 땐 이전 위치가 없음
                dp[w][t] = max(dp[w][t], dp[w - 1][t - 1] + is_possible)

    print(max(map(max, dp)))  # 가장 많이 받은 자두의 개수


if __name__ == "__main__":
    main()
