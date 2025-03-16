import sys

sys.setrecursionlimit(10 ** 7)


def tps(current, visited):
    global N, W, dp

    check = dp[current][visited]

    # 이미 방문한 마을인 경우
    if check != -1:
        return check

    # 모든 마을을 방문한 경우
    if visited == (1 << N) - 1:
        # 현재 위치에서 시작점으로 되돌아 갈 수 있음
        if W[current][0] != 0:
            return W[current][0]
        # 현재 위치에서 시작점으로 되돌아 갈 수 없음
        else:
            return sys.maxsize

    # 마을 방문 시작
    min_cost = sys.maxsize
    for i in range(N):
        if visited & (1 << i) or W[current][i] == 0:  # 방문할 수 없는 마을이면 패스
            continue

        min_cost = min(min_cost, tps(i, visited | (1 << i)) + W[current][i])  # 가장 비용이 적게 들도록 방문

    dp[current][visited] = min_cost  # 비용 저장

    return dp[current][visited]


def main() -> None:
    global N, W, dp

    input = sys.stdin.readline

    N = int(input().rstrip('\n'))
    W = [list(map(int, input().rstrip('\n').split(' '))) for _ in range(N)]
    dp = [[-1] * (1 << N) for _ in range(N)]

    print(tps(0, 1))


if __name__ == "__main__":
    main()
