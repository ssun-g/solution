"""

같은 조에 속한 원생들은 서로 인접해야 한다는 조건이 있기 때문에
조가 될 수 있는 모든 경우의 수를 구하고 각 비용을 우선순위 큐에 저장해주었다.
내림차순으로 정렬하기 위해 비용에 취해서 저장한다.

그 후, 그룹이 총 K개가 나와야 하므로 K-1만큼 연결을 끊어주고 
나머지 비용들을 다 더해주면 조가 나뉘게 된다.

Example:
10 5
1 3 8 9 11 15 18 19 20 27

원생간의 모든 비용을 구하면

2 5 1 2 4 3 1 1 7 => 모두 더하면 조가 1개일 때의 비용이 된다.
K=5이므로 비용이 큰 순서대로 4번 조를 나눠준다.
첫 번째는 비용7이 삭제되므로 예제에서 20, 27은 같은 조가 될 수 없는 것을 뜻한다.
두 번째는 비용5가 삭제, (3, 8)은 같은 조가 될 수 없다.
세 번째는 4삭제 (11, 15)는 같은 조가 될 수 없다.
마지막 3삭제 (15, 18)은 같은 조가 될 수 없다.
비용이 같은 경우 아무거나 삭제해도 된다.

최종 비용은 2 1 2 1 1 7이 되고,
나뉜 조는 (1 3) (8 9 11) (15) (18 19 20) (27)가 된다.


"""
import sys
from queue import PriorityQueue

input = sys.stdin.readline

answer = 0
N, K = map(int, input().rstrip("\n").split(" "))
group = list(map(int, input().rstrip("\n").split(" ")))
cost = PriorityQueue(N)

for i in range(1, N):
    cost.put(-(group[i] - group[i - 1]))  # 내림차순으로 정렬하기 위해 음수값으로 저장해준다.

while not cost.empty():
    c = cost.get()
    if K > 1:  # K-1번 조를 나눠 준다.
        K -= 1
    else:
        answer += c

print(-answer)
