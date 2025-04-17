"""
1. 임의의 시작점을 찾는다.
2. 인접한 노드들을 탐색하면서 색칠하는 것으로 생각한다.
3. 서로 같은 색을 칠해야 하는 경우 이분 그래프가 아님
"""
import sys
from collections import deque

input = sys.stdin.readline


def bfs(node: int, graph: list) -> bool:
    global check

    check[node] = 1

    q = deque([[node, 1]])  # [노드번호, 색]
    while q:
        cur_node, cur_color = q.popleft()
        for next_node in graph[cur_node]:
            if check[next_node] == cur_color:  # 같은 색으로 칠해야 하는 경우
                return False

            if check[next_node] == 0:  # 다음 노드 방문
                check[next_node] = cur_color * -1
                q.append([next_node, cur_color * -1])

    return True


def main() -> None:
    global check

    K = int(input().rstrip('\n'))
    for _ in range(K):
        V, E = map(int, input().rstrip('\n').split(' '))

        # 그래프 그리기
        graph = [[] * (V + 1) for _ in range(V + 1)]
        for _ in range(E):
            u, v = map(int, input().rstrip('\n').split(' '))
            graph[u].append(v)
            graph[v].append(u)

        # 탐색 시작
        check = [0] * (V + 1)
        is_bipartite = True
        for i in range(1, V + 1):
            if check[i] == 0:  # 방문하지 않은 노드
                if not bfs(i, graph):
                    is_bipartite = False
                    break

        if is_bipartite:
            print("YES")
        else:
            print("NO")


if __name__ == "__main__":
    main()
