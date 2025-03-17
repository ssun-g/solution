"""
pypy3 제출
"""
import sys
from collections import deque

input = sys.stdin.readline

move_x = [0, 0, -1, 1]
move_y = [-1, 1, 0, 0]


def bfs(x, y) -> int:
    global H, W, maps

    q = deque([[x, y, 0]])  # x, y, depth
    
    check = [[0] * W for _ in range(H)]
    check[y][x] = 1

    max_depth = 0
    while q:
        cx, cy, depth = q.popleft()
        max_depth = max(max_depth, depth)
        
        for dx, dy in zip(move_x, move_y):
            nx = cx + dx
            ny = cy + dy
            if (0 <= nx < W) and (0 <= ny < H) and (not check[ny][nx]) and (maps[ny][nx] == 'L'):
                check[ny][nx] = 1
                q.append([nx, ny, depth + 1])
                
    return max_depth
                


def main() -> None:
    global H, W, maps

    H, W = map(int, input().rstrip("\n").split(" "))
    maps = [list(input().rstrip("\n")) for _ in range(H)]

    answer = 0
    for y in range(H):
        for x in range(W):
            if maps[y][x] == "L":
                answer = max(answer, bfs(x, y))

    print(answer)


if __name__ == "__main__":
    main()
