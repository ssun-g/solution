"""
각 위치에서 레몬을 따고 집에 돌아가면 레몬이 몇개가 남는지 확인하면서 가장 많이 가져갈 수 있는 개수를 계산한다.
"""
import sys

input = sys.stdin.readline


def main() -> None:
    N = int(input().rstrip('\n'))
    lemon = list(map(int, input().rstrip('\n').split(' ')))

    max_lemon = 0
    for i in range(N):
        max_lemon = max(max_lemon, lemon[i] - (N + 1 - (i + 1)))  # 가져갈 수 있는 레몬 개수 계산

    print(max_lemon)


if __name__ == "__main__":
    main()
