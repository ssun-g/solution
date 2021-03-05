"""

주사위 게임에 참가하는 사람들의 상금을 sum이라는 list에 모두 저장해준 뒤
max(sum)을 사용해 가장 많은 상금을 받은 사람을 출력.

같은 눈이 두 개 나오는 경우는 1,000원+(같은 눈)*100원의 상금을 받으므로
(1, 2), (1, 3)이 같을 경우와 (2, 3)이 같을 경우를 나눴다.

"""
import sys

input = sys.stdin.readline

N = int(input().rstrip("\n"))
sum = list()
for i in range(N):
    dice = list(map(int, input().rstrip("\n").split(" ")))

    if dice[0] == dice[1] == dice[2]: # 같은 눈 3개가 나오는 경우
        sum.append(10000 + (dice[0] * 1000))
    elif (dice[0] == dice[1]) or (dice[0] == dice[2]): # 같은 눈이 두 개 나오는 경우 1
        sum.append(1000 + (dice[0] * 100))
    elif dice[1] == dice[2]: # 같은 눈이 두 개 나오는 경우 2
        sum.append(1000 + (dice[1] * 100))
    else: # 모두 다른 눈이 나오는 경우
        sum.append(100 * max(dice))
print(max(sum))
