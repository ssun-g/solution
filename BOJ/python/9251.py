import sys

input = sys.stdin.readline

str_a = input().rstrip()
str_b = input().rstrip()

dp = [[0 for _ in range(len(str_b) + 1)] for _ in range(len(str_a) + 1)]


# 기본적인 LCS 알고리즘 구현
for i in range(1, len(str_a) + 1):
    for j in range(1, len(str_b) + 1):
        if str_a[i - 1] == str_b[j - 1]:  # 현재 문자(인덱스가 1부터 시작)가 같다면 LCS에 포함시킨다.
            dp[i][j] = dp[i - 1][j - 1] + 1
        else:  # 현재 문자가 다르다면 이전까지의 문자열 중 길이가 긴 문자열을 기준으로 길이를 갱신
            dp[i][j] = dp[i - 1][j] if dp[i][j - 1] < dp[i - 1][j] else dp[i][j - 1]

print(dp[len(str_a)][len(str_b)])
