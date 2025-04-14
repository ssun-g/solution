"""
예상 순위 = 실제 순위가 되는 경우가 불만도 최소.
즉, 예상 순위가 높은 순으로 정렬 하면 된다.
"""
import sys

input = sys.stdin.readline


def main() -> None:
    N = int(input().rstrip('\n'))
    rank = [int(input().rstrip('\n')) for _ in range(N)]
    rank.sort()  # 예상 순위가 높은 순으로 정렬

    total = 0
    for i, r in enumerate(rank):
        total += abs(r - (i + 1))  # 불만도 계산

    print(total)


if __name__ == "__main__":
    main()
