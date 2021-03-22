import sys
from queue import PriorityQueue

input = sys.stdin.readline
INF = sys.maxsize

N = int(input().rstrip("\n"))
M = int(input().rstrip("\n"))
vector = [[] for _ in range(N + 1)]  # 노드 간의 비용 저장 (연결된 노드, 비용)
visited = [False for _ in range(N + 1)]  # 노드를 방문했는지 체크
dist = [INF] * (N + 1)  # 시작 노드로부터 index까지의 최소 비용(거리)을 저장 등장할 수 없는 큰 값으로 초기화

for _ in range(M):
    u, v, cost = map(int, input().rstrip("\n").split(" "))
    vector[u].append((v, cost))
start, end = map(int, input().rstrip("\n").split(" "))


def dijkstra(start, end, vector: list) -> None:
    pq = PriorityQueue()
    pq.put((0, start))
    dist[start] = 0

    while not pq.empty():
        cost, cur_node = pq.get()

        if visited[cur_node]:  # 이미 방문한 노드이면 무시한다.
            continue

        visited[cur_node] = True
        for next_node, next_cost in vector[cur_node]:

            # 다음 노드까지의 비용이 (현재까지의 비용 + 다음 노드로 향할 때의 비용)보다 크다면 새로 갱신.
            if dist[next_node] > cost + next_cost:
                dist[next_node] = cost + next_cost
                pq.put((dist[next_node], next_node))


dijkstra(start, end, vector)
print(dist[end])
