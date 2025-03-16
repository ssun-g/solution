import sys
from collections import deque

sys.setrecursionlimit(pow(10, 7))
input = sys.stdin.readline


def bfs(k, start):
    global video, check

    ret = 0
    check[start] = 1

    q = deque()

    for next_node, usado in video[start]:
        q.append([next_node, usado])

    while q:
        node, usado = q.popleft()
        check[node] = 1
        if k <= usado:
            ret += 1
            for next_node, next_usa in video[node]:
                if not check[next_node]:
                    check[next_node] = 1
                    q.append([next_node, min(next_usa, usado)])

    return ret


def main() -> None:
    global video, check

    N, Q = map(int, input().rstrip("\n").split(" "))
    video = [[] for _ in range(N + 1)]
    for _ in range(N - 1):
        p, q, r = map(int, input().rstrip("\n").split(" "))
        video[p].append([q, r])
        video[q].append([p, r])

    for _ in range(Q):
        k, v = map(int, input().rstrip("\n").split(" "))
        check = [0] * (N + 1)
        print(bfs(k, v))


if __name__ == "__main__":
    main()
