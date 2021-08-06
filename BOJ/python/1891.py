import sys

sys.setrecursionlimit(10 ** 8)
input = sys.stdin.readline

d, fr = map(int, input().rstrip("\n").split(" "))
dx, dy = map(int, input().rstrip("\n").split(" "))

# 시작 좌표 찾기
fr = list(str(fr))
init_x = init_y = 2 ** d  # 이동시키려는 사분면 조각의 좌표 저장
size = 2 ** (d - 1)
for num in fr:
    if num == "1":
        init_y -= size
    elif num == "2":
        init_x -= size
        init_y -= size
    elif num == "3":
        init_x -= size
    elif num == "4":
        pass

    size //= 2

# 목적지의 좌표
dest_x = init_x + dx
dest_y = init_y - dy


def dnc(sx, sy, ex, ey, size, quad):
    # 목적지에 도착했으면 위치 출력
    if (dest_x == ex) and (dest_y == ey) and (len(quad) == d):
        print(quad)
        exit(0)

    # 해당 사분면에 존재하지 않으면 넘어간다.
    if not ((sx < dest_x) and (dest_x <= ex) and (sy < dest_y) and (dest_y <= ey)):
        return

    dnc(sx + size // 2, sy, ex, ey - size // 2, size // 2, quad + "1")  # 1사분면
    dnc(sx, sy, ex - size // 2, ey - size // 2, size // 2, quad + "2")  # 2사분면
    dnc(sx, sy + size // 2, ex - size // 2, ey, size // 2, quad + "3")  # 3사분면
    dnc(sx + size // 2, sy + size // 2, ex, ey, size // 2, quad + "4")  # 4사분면


dnc(0, 0, 2 ** d, 2 ** d, 2 ** d, "")
print(-1)  # 도달할 수 없으면 -1 출력
