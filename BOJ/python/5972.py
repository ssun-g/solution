import sys
import heapq as hq  # 이번엔 heapq를 써서 해보았다. PriorityQueue랑 똑같다.

input = sys.stdin.readline
INF = sys.maxsize

N, M = map(int, input().rstrip("\n").split(" "))
vector = [[] for _ in range(N + 1)]
visited = [False for _ in range(N + 1)]
dist = [INF] * (N + 1)

for _ in range(M):
    u, v, cost = map(int, input().rstrip("\n").split(" "))
    vector[u].append((v, cost))  # 방향성 없는 그래프이기 때문에 서로 연결해준다.
    vector[v].append((u, cost))


def dijkstra(start, end, vector: list) -> None:
    heap_min = []
    hq.heappush(heap_min, (0, start))
    dist[start] = 0

    while heap_min:
        cost, cur_node = hq.heappop(heap_min)

        if visited[cur_node]:  # 이미 방문한 노드이면 최소 비용이 담겨 있기 때문에 무시한다.
            continue

        visited[cur_node] = True
        for next_node, next_cost in vector[cur_node]:

            # 다음 노드까지의 비용이 (현재까지의 비용 + 다음 노드로 이동하는 비용) 보다 크다면 새로 갱신해준다.
            if dist[next_node] > cost + next_cost:
                dist[next_node] = cost + next_cost
                hq.heappush(heap_min, (dist[next_node], next_node))


dijkstra(1, N, vector)
print(dist[N])
