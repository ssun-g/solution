import sys

input = sys.stdin.readline

N, K = map(int, input().split(' '))

global game_of_death
global check
global depth
game_of_death = [int(input()) for _ in range(N)]
check = [0 for _ in range(len(game_of_death))] # 지목 당한 적이 있는지 체크하기 위한 list
depth = [-1 for _ in range(len(game_of_death))] # 몇 번째로 지목 되었는지 확인하기 위한 list


def playGame(cur, d):
    global game_of_death
    global check
    global depth

    next = game_of_death[cur] 

    # 다음에 지목할 사람이 이미 지목된 적이 있으면 
    # 계속 cycle이 돌 것이기 때문에 더 이상 진행하는 것은 의미가 없다.
    if check[cur] == 1:
        return

    # 지목 된 적이 없으면 게임을 계속 진행한다.
    check[cur] = 1
    depth[cur] = d
    playGame(next, d + 1)


playGame(0, 0)
print(depth[K])
