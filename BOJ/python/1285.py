"""

행, 열 방향으로 동전을 뒤집을 때 2번 이상 뒤집을 필요가 없다. (원래의 상태와 같아지기 때문)
따라서 행 or 열 방향으로 뒤집는 경우를 모두 구한 뒤 (2^N)
나머지 방향으로 동전을 뒤집으면서 뒷면이 위로 향하는 동전의 개수를 최소화하면 된다.

"""
import sys

input = sys.stdin.readline

N = int(input().rstrip("\n"))
init_state = [list(map(str, input().rstrip("\n"))) for _ in range(N)]

for b in range(1 << N):
    tmp = [[0 for _ in range(N)] for _ in range(N)]

    for i in range(N):
        if b & (1 << i):  # 모든 행에 대해 뒤집는 경우의 수를 저장한다.
            tmp[i] = ["T" if init_state[i][j] == "H" else "H" for j in range(N)]
        else:
            tmp[i] = ["T" if init_state[i][j] == "T" else "H" for j in range(N)]

    answer = 400
    cnt = 0
    for rows in range(N):  # 행 방향으로 모두 구했으니 열 방향으로 뒤집는다.
        t_cnt = 0
        h_cnt = 0
        for cols in range(N):
            if tmp[cols][rows] == "T":
                t_cnt += 1
            else:
                h_cnt += 1
        cnt += t_cnt if t_cnt < h_cnt else h_cnt  # 뒷면이 위를 향하는 동전의 개수를 최소로 하는 방향으로 뒤집는다.

    answer = cnt if cnt < answer else answer

print(answer)
