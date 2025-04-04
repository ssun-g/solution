import sys

input = sys.stdin.readline


def main() -> None:
    R, C, Q = map(int, input().rstrip('\n').split(' '))
    picture = [list(map(int, input().rstrip('\n').split(' '))) for _ in range(R)]

    # 구간 합 구하기
    psum = [[0] * (C + 1) for _ in range(R + 1)]
    for y in range(R):
        for x in range(C):
            psum[y + 1][x + 1] = psum[y][x + 1] + psum[y + 1][x] - psum[y][x] + picture[y][x]

    # 정답 출력
    for _ in range(Q):
        r1, c1, r2, c2 = map(int, input().rstrip('\n').split(' '))
        bright = psum[r2][c2] - psum[r1 - 1][c2] - psum[r2][c1 - 1] + psum[r1 - 1][c1 - 1]
        num = (r2 - r1 + 1) * (c2 - c1 + 1)
        print(bright // num)


if __name__ == "__main__":
    main()
