"""

x일에 일을 할 경우 N+1일에 퇴사가 가능한지 체크
가능하다면 x일에 일을 할 것인지(1) 말 것인지(2) 선택

(1) (x + day[x]) 일에 얻을 수 있는 최대 비용 + x일에 일을 함으로써 얻는 비용
(2) (x + 1)일에 얻을 수 있는 최대 비용과 같다.

둘 중 큰 값이 x일에서 얻을 수 있는 최대 비용.

"""
import sys

input = sys.stdin.readline

N = int(input().rstrip("\n"))
cons = [0]


for _ in range(N):
    cons.append(list(map(int, input().rstrip("\n").split(" "))))

dp = [0 for _ in range(len(cons) + 1)]
for i in range(N, 0, -1): # 역순으로 탐색하면서 위의 알고리즘을 구현.
    if i + cons[i][0] > N + 1:
        dp[i] = dp[i + 1]
    else:
        dp[i] = max(dp[i + 1], dp[i + cons[i][0]] + cons[i][1])

print(dp[1])
