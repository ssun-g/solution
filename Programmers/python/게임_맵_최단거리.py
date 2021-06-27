# (x, y) 좌표 표현
class Point:
    def __init__(self, x, y):
        self.x = x
        self.y = y


dx = [0, 0, -1, 1]
dy = [-1, 1, 0, 0]


def solution(maps):
    que = []

    rows = len(maps)
    cols = len(maps[0])

    check = [[-1 for _ in range(cols)] for _ in range(rows)]

    que.append(Point(0, 0))
    check[0][0] = 1  # 시작 지점 설정
    while len(que) != 0:
        cur = que.pop(0)
        if (cur.x == cols - 1) and (cur.y == rows - 1):  # 상대 진영에 도달하면 종료
            return check[rows - 1][cols - 1]

        for i in range(4):
            nx = cur.x + dx[i]
            ny = cur.y + dy[i]
            if (
                (0 <= nx)
                and (nx < cols)
                and (0 <= ny)
                and (ny < rows)
                and (check[ny][nx] == -1)
                and (maps[ny][nx] == 1)
            ):
                que.append(Point(nx, ny))
                check[ny][nx] = check[cur.y][cur.x] + 1

    return -1
