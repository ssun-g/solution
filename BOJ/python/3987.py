"""

재채점 되어서 틀렸던 문제.
line 18에서 항성계 전체를 도는 시간으로 탈출 조건을 걸어 두었는데
같은 지점을 방문하더라도 전파 방향이 다르다면 다른 경우인 것을 인지하지 못해서 틀림.
모든 방향을 고려하기 위해 간단히 *4를 해주었다.

"""
import sys

input = sys.stdin.readline


def signal(y, x, direction):
    prop = 0
    while True:
        global N, M
        if prop > N * M * 4:  # 전파 시간이 항성계 전체를 도는 시간(*4는 모든 방향)보다 크다면 무한루프라고 판단.
            break
        if (x < 0) or (y < 0) or (x >= M) or (y >= N) or (Map[y][x] == "C"):
            break  # 전파가 맵 밖으로 나가거나 블랙홀을 만난 경우
        prop += 1

        # 진행 방향에 따라 1초씩 이동한다.
        if direction == "U":
            if Map[y][x] == "/":
                direction = "R"
                x += 1
            elif Map[y][x] == "\\":
                direction = "L"
                x -= 1
            else:
                y -= 1
        elif direction == "R":
            if Map[y][x] == "/":
                direction = "U"
                y -= 1
            elif Map[y][x] == "\\":
                direction = "D"
                y += 1
            else:
                x += 1
        elif direction == "D":
            if Map[y][x] == "/":
                direction = "L"
                x -= 1
            elif Map[y][x] == "\\":
                direction = "R"
                x += 1
            else:
                y += 1
        else:
            if Map[y][x] == "/":
                direction = "D"
                y += 1
            elif Map[y][x] == "\\":
                direction = "U"
                y -= 1
            else:
                x -= 1
    return prop


global N, M, Map
N, M = map(int, input().rstrip("\n").split(" "))
Map = [input().rstrip("\n") for _ in range(N)]
PR, PC = map(int, input().rstrip("\n").split(" "))
PR -= 1 # index가 1부터 시작하기 때문에 -1을 해주었다.
PC -= 1

answer = dict()

# 시작 지점에서 4방향으로 모두 전파해보고 거리를 dict 형태로 저장해준다.
answer["U"] = signal(PR, PC, "U")
answer["R"] = signal(PR, PC, "R")
answer["D"] = signal(PR, PC, "D")
answer["L"] = signal(PR, PC, "L")

dict_key_max = max(answer.keys(), key=lambda x: answer[x]) # dict에서 가장 큰 value값을 가지는 key를 찾는다.
print(dict_key_max)
if answer[dict_key_max] > N * M * 4:
    print("Voyager")
else:
    print(answer[dict_key_max])
