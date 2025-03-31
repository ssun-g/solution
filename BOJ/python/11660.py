"""
x가 행이고, y가 열이다.
이거 때문에 쓸데없이 한참 헤맸다...
"""
import sys

input = sys.stdin.readline


def main() -> None:
    N, M = map(int, input().rstrip('\n').split(' '))
    arr = [list(map(int, input().rstrip('\n').split(' '))) for _ in range(N)]
    psum = [[0] * (N + 1) for _ in range(N + 1)]

    # 구간 합 구하기
    for x in range(N):
        for y in range(N):
            psum[x + 1][y + 1] = psum[x][y + 1] + psum[x + 1][y] - psum[x][y] + arr[x][y]

    # 출력
    for _ in range(M):
        x1, y1, x2, y2 = map(int, input().rstrip('\n').split(' '))
        print(psum[x2][y2] - psum[x1 - 1][y2] - psum[x2][y1 - 1] + psum[x1 - 1][y1 - 1])


if __name__ == "__main__":
    main()
