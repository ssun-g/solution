import sys

input = sys.stdin.readline

answer = 0
stack = list()
N = int(input())

# 모든 timestep(1분)마다 탐색
for _ in range(N):
    tmp = input().rstrip("\n").split(" ")

    # 과제가 주어 졌을 때
    if len(tmp) != 1:
        score = int(tmp[1])
        t = int(tmp[2])

        # 과제를 끝내는 데 1분이 걸린다면 받자마자 끝낼 수 있으므로 과제를 바로 완료한다.
        if t == 1:
            answer += score

        # 그렇지 않으면 과제를 받은 즉시 1분간 과제를 수행하고 stack에 넣어준다.
        else:
            stack.append([score, t - 1])

    # 과제가 주어지지 않고, stack이 비어있지 않은 경우
    elif len(stack) != 0:

        # 가장 최근에 주어진 과제를 해결하기 위한 시간이 1분 남았다면 과제를 완료하고 점수를 더한다.
        if stack[-1][1] == 1:
            answer += stack[-1][0]
            stack.pop()

        # 과제를 못 끝냈을 경우(1분 넘게 남았을 경우) 최근 과제를 1분만 수행한다.
        else:
            stack[-1][1] -= 1

print(answer)
