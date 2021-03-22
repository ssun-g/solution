import sys
import heapq as hq

input = sys.stdin.readline
INF = sys.maxsize

N, M, X = map(int, input().rstrip("\n").split(" "))
vector = [[] for _ in range(N + 1)]

for _ in range(M):
    u, v, cost = map(int, input().rstrip("\n").split(" "))
    vector[u].append((v, cost))


def dijkstra(start, end, graph: list) -> list:
    """
    최단 경로 구하기
    Args:
        start (int): 시작 위치
        end (int): 목표 위치
        graph (list): 노드 간의 거리가 담겨 있는 graph

    Returns:
        list: start에서부터 각 노드까지의 최단 거리
    """
    visited = [False for _ in range(N + 1)]  # 노드 방문 여부 체크
    dist = [INF] * (N + 1)  # start로부터 각 노드까지의 최단 거리(비용) 저장
    heap_min = []  # 비용이 가장 적게드는 노드를 방문하기 위한 최소 힙
    hq.heappush(heap_min, (0, start))  # 시작 노드를 heap에 넣어준다. (비용, 노드)
    dist[start] = 0

    while heap_min:
        cost, cur_node = hq.heappop(heap_min)

        if visited[cur_node]:  # 이미 방문한 노드이면 넘어간다.
            continue

        visited[cur_node] = True
        for next_node, next_cost in graph[cur_node]:

            # 다음 방문할 노드의 비용이 (현재까지의 비용 + 다음 노드로 이동하는 비용) 보다 크다면 비용을 갱신한다.
            if dist[next_node] > cost + next_cost:
                dist[next_node] = cost + next_cost
                hq.heappush(heap_min, (dist[next_node], next_node))

    return dist


answer = 0
for i in range(1, N + 1):
    itoX = dijkstra(i, X, vector)  # 각 학생들이 X 마을로 이동하는 거리
    Xtoi = dijkstra(X, i, vector)  # 각 학생들이 X 마을에서 자신의 집으로 돌아오는 거리
    answer = max(answer, itoX[X] + Xtoi[i])  # 그 중 가장 많은 시간을 소비하는 학생을 찾는다.

print(answer)
