def dfs(node, computers):
    global check

    # 모든 노드 방문
    if 0 not in check:
        return True

    for next_node, connected in enumerate(computers[node]):
        if (connected == 1) and (next_node != node) and (not check[next_node]):
            check[next_node] = 1
            if dfs(next_node, computers):
                return True

    return False


def solution(n, computers):
    global check

    answer = 0

    check = [0] * n
    for i in range(n):
        if not check[i]:
            check[i] = 1
            dfs(i, computers)
            answer += 1

    return answer
