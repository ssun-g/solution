import sys
import heapq

input = sys.stdin.readline
INF = float("inf")


def dijkstra(n, d, start):
    computer = [
        [] for _ in range(n + 1)
    ]  # test case마다 초기화 해주어야 하기 때문에 dijkstra 함수 내에서 선언
    dist = [INF for _ in range(n + 1)]  # 위와 동일
    min_heap = []  # 최소 비용을 찾기 위한 최소 힙
    for _ in range(d):
        a, b, s = map(int, input().rstrip("\n").split(" "))
        computer[b].append((a, s))  # b에 의해 a가 감염되는 것이므로 b->a의 단방향 그래프를 그려준다.

    heapq.heappush(min_heap, (0, start))
    dist[start] = 0
    while min_heap:
        cur_cost, cur_node = heapq.heappop(min_heap)

        if dist[cur_node] < cur_cost:  # 이미 방문했던 노드는 pass
            continue

        for next_node, next_cost in computer[cur_node]:
            if dist[next_node] > cur_cost + next_cost:  # 비용이 더 적게 들면 갱신해준다.
                dist[next_node] = cur_cost + next_cost
                heapq.heappush(min_heap, (dist[next_node], next_node))

    inf_cnt = 0  # 감염된 컴퓨터 수
    max_dist = 0  # 마지막 컴퓨터가 감영되기까지 걸리는 시간
    for i in range(1, len(dist)):
        if dist[i] != INF:
            inf_cnt += 1
            max_dist = max(max_dist, dist[i])

    print(inf_cnt, max_dist)


def solution():
    tc = int(input().rstrip("\n"))
    for _ in range(tc):
        n, d, c = map(int, input().rstrip("\n").split(" "))
        dijkstra(n, d, c)


if __name__ == "__main__":
    solution()
