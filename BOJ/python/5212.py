import sys

input = sys.stdin.readline

R, C = map(int, input().split(' '))
Map = [str(input().rstrip('\n')) for i in range(R)]
dx = [0, 0, -1, 1]
dy = [-1, 1, 0, 0]
sx = sy = 10 # 50년 후의 지도를 기리기 위한 직사각형의 왼쪽 위 좌표
ex = ey = 0 # 50년 후의 지도를 기리기 위한 직사각형의 오른쪽 아래 좌표

tmp = [[1 if Map[y][x] == 'X' else 0 for x in range(C)] for y in range(R)]
for y in range(R):
    for x in range(C):
        if Map[y][x] == '.': # 현재 위치가 바다일 경우 넘어간다.
            continue

        sea_count = 0

        # 현재 위치 기준 상, 하, 좌, 우 4방향을 살펴보고 바다이면 카운트를 +1 해준다.
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if (nx < 0) or (nx >= C) or (ny < 0) or (ny >= R) or (Map[ny][nx] == '.'):
                sea_count += 1

        # 3방향이 바다이면 50년 후 섬은 잠긴다.
        if sea_count >= 3:
            tmp[y][x] = 0

        # 섬이 남아 있다면 50년 후의 지도를 그리기 위해 최대 사각형의 좌표 값을 업데이트 해준다.
        else:
            sx = min(sx, x)
            sy = min(sy, y)
            ex = max(ex, x)
            ey = max(ey, y)

# 50년 후의 지도 출력
for y in range(sy, ey + 1):
    print(''.join(['X' if tmp[y][x] == 1 else '.' for x in range(sx, ex + 1)]))
