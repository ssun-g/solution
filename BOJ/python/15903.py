"""
가장 작은 수를 고를 때 전체 합이 작아진다.
"""
import sys
import heapq as hq

input = sys.stdin.readline


def main() -> None:
    n, m = map(int, input().rstrip('\n').split(' '))
    card = list(map(int, input().rstrip('\n').split(' ')))

    hq.heapify(card)  # 최소힙

    for _ in range(m):
        psum = 0

        # 가장 작은 수 꺼내서 더하기
        for _ in range(2):
            psum += hq.heappop(card)

        # 다시 넣기
        for _ in range(2):
            hq.heappush(card, psum)

    print(sum(card))


if __name__ == "__main__":
    main()
