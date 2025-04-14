"""
횟수 구하는 방법은 [1463 - 1로 만들기] 문제와 같고,
추가로 1로 만드는 연산을 하면서 경로를 저장해주어야 한다.
이전 숫자에서 어떤 연산을 통해 현재 숫자에 도달했는지 알 수 있으므로 역트래킹이 가능
"""
import sys

input = sys.stdin.readline


def main() -> None:
    global dp

    N = int(input().rstrip('\n'))
    path = [0] * (N + 1)
    dp = [0] * (N + 1)
    dp[1] = 0

    for i in range(2, N + 1):
        dp[i] = dp[i - 1] + 1  # 기본은 1을 빼는 연산
        path[i] = i - 1
        if (i % 3 == 0) and (dp[i] > dp[i // 3] + 1):  # 3으로 나누어 떨어지고 기존 값이 3으로 나눈 경우보다 큰 경우
            dp[i] = dp[i // 3] + 1
            path[i] = i // 3
        if (i % 2 == 0) and (dp[i] > dp[i // 2] + 1):  # 2로 나누어 떨어지고 기존 값이 2로 나눈 경우보다 큰 경우
            dp[i] = min(dp[i], dp[i // 2] + 1)
            path[i] = i // 2

    # 횟수 출력
    print(dp[N])

    # 경로 추적
    print(N, end=' ')
    while N != 1:
        print(path[N], end=' ')
        N = path[N]


if __name__ == "__main__":
    main()
