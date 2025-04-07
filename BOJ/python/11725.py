import sys
from collections import deque

input = sys.stdin.readline


def bfs(tree: list, node: int) -> list:
    check = [0] * len(tree)  # 노드 방문 여부 확인
    check[node] = 1

    parent = [0] * len(tree)  # 부모 노드 체크

    q = deque([node])
    while q:
        cur_node = q.popleft()
        for next_node in tree[cur_node]:
            if not check[next_node]:
                check[next_node] = 1
                parent[next_node] = cur_node
                q.append(next_node)

    return parent


def main() -> None:
    N = int(input().rstrip('\n'))
    tree = [[] for _ in range(N + 1)]

    # 트리(그래프) 생성
    for _ in range(N - 1):
        a, b = map(int, input().rstrip('\n').split(' '))
        tree[a].append(b)
        tree[b].append(a)

    parent = bfs(tree, 1)

    for i in range(2, N + 1):
        print(parent[i])


if __name__ == "__main__":
    main()
