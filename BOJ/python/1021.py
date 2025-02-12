import sys
from collections import deque


def rot_queue(M, Q, order):
    count = 0  # 2번, 3번 연산 횟수 체크
    idx = 0  # 목표(order) 인덱스

    while idx != M:
        top = Q[0]
        target = order[idx] - 1
        t_idx = Q.index(target)  # 다음에 뽑아야 하는 수의 위치

        if top == target:  # 1번 연산(첫 번째 원소 뽑아내기)
            idx += 1
            Q.popleft()
        elif t_idx <= len(Q) // 2:  # 2번 연산(왼쪽으로 한 칸 이동)
            node = Q.popleft()
            Q.append(node)
            count += 1

        elif t_idx > len(Q) // 2:  # 3번 연산(오른쪽으로 한 칸 이동)
            node = Q.pop()
            Q.appendleft(node)
            count += 1

    return count


def main() -> None:
    input = sys.stdin.readline

    N, M = map(int, input().rstrip('\n').split())
    order = list(map(int, input().rstrip('\n').split()))
    Q = deque(list(range(N)))

    print(rot_queue(M, Q, order))


if __name__ == '__main__':
    main()
