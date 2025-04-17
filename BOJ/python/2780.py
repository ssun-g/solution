"""
dp[i][j] : 길이가 i, 마지막 숫자가 j인 경우 가능한 비밀번호의 경우의 수

1. 0~9까지 인접 하는 숫자를 저장 해준다.
2. 시간 초과 방지를 위해 dp 배열을 미리 만들어 놓는다.
3. dp[i][j] += dp[i-1][k] (k는 j와 인접하는 숫자 목록)
"""
import sys

input = sys.stdin.readline


def main() -> None:
    T = int(input().rstrip('\n'))

    # 인접 하는 숫자
    near = [[7],
            [2, 4],
            [1, 3, 5],
            [2, 6],
            [1, 5, 7],
            [2, 4, 6, 8],
            [3, 5, 9],
            [0, 4, 8],
            [5, 7, 9],
            [6, 8]]

    dp = [[0] * 10 for _ in range(1001)]
    dp[1] = [1] * 10

    for i in range(2, 1001):
        for j in range(10):
            for k in near[j]:
                dp[i][j] += dp[i - 1][k] % 1234567

    for _ in range(T):
        N = int(input().rstrip('\n'))
        print(sum(dp[N]) % 1234567)


if __name__ == "__main__":
    main()
