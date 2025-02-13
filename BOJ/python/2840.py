import sys
from collections import deque


def print_result(Q, start):
    while Q:
        if Q[0] == start:
            break
        Q.rotate(-1)

    while Q:
        front = Q.popleft()
        if front == 0:
            print("?", end="")
        else:
            print(f"{front}", end="")


def main() -> None:
    input = sys.stdin.readline

    N, K = map(int, input().rstrip('\n').split())
    order = [list(input().rstrip('\n').split()) for _ in range(K)]
    check = {}  # 중복 알파벳 체크
    wheel = deque([0] * N)

    possible = True
    for move, alpha in order[::-1]:
        if wheel[0] == 0:
            wheel[0] = alpha
            if alpha in check:
                possible = False
                break
            else:
                check[alpha] = 1
        elif wheel[0] == alpha:
            pass
        else:
            possible = False
            break

        wheel.rotate(-int(move))

    if possible:
        _, node = order[-1]
        print_result(wheel, node)
    else:
        print("!")


if __name__ == "__main__":
    main()
