import sys
import copy
from itertools import combinations
from collections import deque

input = sys.stdin.readline

move_x = [0, 0, -1, 1]
move_y = [-1, 1, 0, 0]


# 바이러스 퍼트리기
def spread_virus(virus_pos, walls):
    global N, M

    q = deque(virus_pos)
    temp_walls = copy.deepcopy(walls)

    while q:
        cx, cy = q.popleft()
        for dx, dy in zip(move_x, move_y):
            nx = cx + dx
            ny = cy + dy
            if (0 <= nx < M) and (0 <= ny < N) and (temp_walls[ny][nx] == 0):
                temp_walls[ny][nx] = 2
                q.append([nx, ny])

    return safe_area(temp_walls)


# 안전지대 영역 구하기
def safe_area(maps) -> int:
    area = 0
    for m in maps:
        area += m.count(0)

    return area


def main() -> None:
    global N, M

    N, M = map(int, input().rstrip("\n").split(" "))
    maps = [list(map(int, input().rstrip("\n").split(" "))) for _ in range(N)]

    # 바이러스 위치, 벽을 세울수 있는 위치 저장
    virus_pos = [(x, y) for y in range(N) for x in range(M) if maps[y][x] == 2]
    empty_spaces = [(x, y) for y in range(N) for x in range(M) if maps[y][x] == 0]

    max_area = 0
    for walls in combinations(empty_spaces, 3):  # 벽 3개 세우기
        for x, y in walls:
            maps[y][x] = 1

        max_area = max(max_area, spread_virus(virus_pos, maps))

        for x, y in walls:
            maps[y][x] = 0

    print(max_area)


if __name__ == "__main__":
    main()
