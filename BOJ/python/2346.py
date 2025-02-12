import sys
from collections import deque


def main() -> None:
    input = sys.stdin.readline

    N = int(input().rstrip('\n'))
    order = list(map(int, input().rstrip('\n').split()))  # 이동 횟수 리스트
    Q = deque(list(range(1, N + 1)))

    while Q:
        front = Q.popleft()
        print(f"{front} ", end="")

        move = order[front - 1]
        if move < 0:  # 왼쪽 이동
            Q.rotate(-move)
        elif move > 0:  # 오른쪽 이동
            Q.rotate(-(move - 1))


if __name__ == "__main__":
    main()
