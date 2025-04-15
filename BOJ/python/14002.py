"""
알고리즘 자체는 기본적인 LIS이고 경로를 저장하는 것이 중요함.
"""
import sys

input = sys.stdin.readline


def main() -> None:
    N = int(input().rstrip('\n'))
    A = list(map(int, input().rstrip('\n').split(' ')))

    dp = [0] * N
    path = {i: [] for i in range(N)}

    max_len_loc = [1, 0]  # 최장 증가 부분 수열의 길이(초기값 1), 인덱스
    for i in range(N):
        dp[i] = 1
        for j in range(i):
            if (A[j] < A[i]) and (dp[i] < dp[j] + 1):
                dp[i] = dp[j] + 1
                path[i] = path[j].copy()  # 경로 저장
                if max_len_loc[0] < dp[i]:
                    max_len_loc = [dp[i], i]  # 최장 증가 부분 수열의 길이, 인덱스 업데이트

        path[i].append(A[i])

    print(max_len_loc[0])
    print(*path[max_len_loc[1]])


if __name__ == "__main__":
    main()
