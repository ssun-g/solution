"""
가장 긴 증가하는 부분 수열 문제(LIS)와 거의 똑같음.
"""
import sys

input = sys.stdin.readline

N = int(input().rstrip('\n'))
A = list(map(int, input().rstrip('\n').split()))
dp = [0] * N

answer = 1
for i in range(N):
    dp[i] = 1
    for j in range(i):
        if (A[j] > A[i]) and (dp[i] < dp[j] + 1):  # 이전 수보다 작으면 최대 길이 갱신
            dp[i] = dp[j] + 1
            answer = max(answer, dp[i])

print(answer)
