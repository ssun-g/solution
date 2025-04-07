import sys
from collections import deque

input = sys.stdin.readline


def iscycle(tree, check, node):
    check[node] = 1

    q = deque([[node, -1]])  # [방문할 노드, 부모 노드]
    while q:
        cur_node, parent = q.popleft()
        for next_node in tree[cur_node]:
            if not check[next_node]:
                check[next_node] = 1
                q.append([next_node, cur_node])
            elif next_node != parent:  # 방문한 노드인데 부모 노드가 아닌 경우(사이클 존재)
                return True

    return False


def main() -> None:
    case_num = 1

    while True:
        n, m = map(int, input().rstrip('\n').split(' '))
        if (n == 0) and (m == 0):
            break

        # 그래프 생성
        graph = [[] for _ in range(n + 1)]
        check = [0] * (n + 1)
        for _ in range(m):
            a, b = map(int, input().rstrip('\n').split(' '))
            graph[a].append(b)
            graph[b].append(a)

        # 트리 개수 세기(트리가 없음 = 사이클 존재)
        count = 0
        for i in range(1, n + 1):
            if (not check[i]) and (not iscycle(graph, check, i)):
                count += 1

        # 출력
        if count == 0:
            print(f"Case {case_num}: No trees.")
        elif count == 1:
            print(f"Case {case_num}: There is one tree.")
        else:
            print(f"Case {case_num}: A forest of {count} trees.")

        case_num += 1


if __name__ == "__main__":
    main()
