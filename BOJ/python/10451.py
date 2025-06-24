import sys

sys.setrecursionlimit(10 ** 7)

input = sys.stdin.readline


# 한 번 방문할 때 연결된 노드는 모두 방문
def dfs(n):
    global arr, check

    next_node = arr[n - 1]
    if not check[next_node]:  # 방문하지 않은 노드인 경우에만 방문
        check[next_node] = 1
        dfs(next_node)


def main() -> None:
    global arr, check

    # 입력
    T = int(input().rstrip('\n'))
    for _ in range(T):
        N = int(input().rstrip('\n'))
        arr = list(map(int, input().rstrip('\n').split(' ')))
        check = [0] * (len(arr) + 1)
        cnt = 0

        # 그래프 순회
        for n in arr:
            if not check[n]:  # 방문하지 않은 노드만 방문
                check[n] = 1
                dfs(n)
                cnt += 1

        print(cnt)


if __name__ == "__main__":
    main()
