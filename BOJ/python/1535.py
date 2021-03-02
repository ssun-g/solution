"""

최대 사람 수가 20명이기 때문에 bruteforce를 사용하여 풀 수 있겠다고 생각했다.
기쁨을 얻을 수 있는 모든 경우의 수를 탐색하여 가장 기쁨을 많이 얻은 경우를 출력해주었다.

"""
import sys

input = sys.stdin.readline # line마다 입력을 받는다.

global answer # answer를 전역 변수로 사용한다.
answer = 0
num = int(input())
health = list(map(int, input().split(" ")))
happiness = list(map(int, input().split(" ")))
check = [0 for i in range(20)] # 방문을 check하기 위한 list


def bruteForce(init, bital, happy):
    # 현재 체력이 0이하가 되면 함수를 종료한다. 그렇지 않으면 
    # 현재까지 얻은 기쁨 값중 가장 큰 값을 업데이트 해준다.
    if bital <= 0:
        return
    else:
        global answer
        answer = max(answer, happy)

    for i in range(init, num):
        # 인사하지 않았다면 인사를 해본다.
        if check[i] == 0:
            check[i] = 1
            # 인사하고 얻은 기쁨과 잃는 체력을 가지고 다음 task를 진행한다.
            bruteForce(i + 1, bital - health[i], happy + happiness[i])
            check[i] = 0


bruteForce(0, 100, 0)
print(answer)
