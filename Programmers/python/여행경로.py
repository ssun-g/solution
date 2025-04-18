import sys

sys.setrecursionlimit(10 ** 7)


def all_visited(departure, arrival):
    global graph, check, answer

    # 모든 항공권을 사용한 경우
    if 0 not in check:
        return True

    # 출발하는 항공편이 없는 경우
    if arrival not in graph:
        return False

    for next_arrival, i in graph[arrival]:
        if not check[i]:
            check[i] = 1
            answer.append(next_arrival)
            if all_visited(arrival, next_arrival):
                return True
            check[i] = 0
            answer.pop()

    return False


def solution(tickets):
    global graph, check, answer

    # 그래프 만들기
    graph = {}
    for i, (f, t) in enumerate(tickets):
        if f in graph:
            graph[f].append([t, i])  # 목적지, 항공권 번호
        else:
            graph[f] = [[t, i]]

    # 알파벳 순 정렬
    graph = {k: sorted(v) for k, v in graph.items()}
    check = [0] * len(tickets)  # 항공권 사용 체크

    # 출발지 고르기(ICN에서 출발하는 항공권이 두 개 이상인 경우)
    for arrival, i in graph["ICN"]:  # 사전순으로 우선인 항공권 먼저 사용
        answer = ["ICN", arrival]
        check[i] = 1
        if all_visited("ICN", arrival):  # 모두 방문한 경우 여행 종료
            return answer
        check[i] = 0
