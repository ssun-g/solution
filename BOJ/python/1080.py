"""
문제를 풀기 위해 순서가 강제되어 있다고 가정해본다.

1. (0, 0)부터 (N, M)까지 탐색하면서 행렬 A의 원소와 행렬 B의 원소가 다르면 뒤집는다.
2. 한 번 확인한 원소는 다시 확인 하지 않으므로 최소 횟수를 보장함.
"""
import sys

input = sys.stdin.readline


def flip_matrix(A, sx, sy):
    result = []
    # 뒤집지 않는 부분 유지(0 ~ sy)
    for y in range(0, sy):
        result.append(A[y])

    # 뒤집기
    for y in range(sy, sy + 3):
        s = ""
        row = A[y]
        for x in range(sx, sx + 3):
            s += "1" if row[x] == "0" else "0"

        result.append(row[0:sx] + s + row[sx + 3:])

    # 뒤집지 않는 부분 유지(sy+3, n)
    for y in range(sy + 3, len(A)):
        result.append(A[y])

    return result


def main() -> None:
    N, M = map(int, input().rstrip('\n').split(' '))
    A = [input().rstrip('\n') for _ in range(N)]
    B = [input().rstrip('\n') for _ in range(N)]

    count = 0
    for y in range(N - 2):
        is_equal = False
        for x in range(M - 2):
            if A[y][x] != B[y][x]:  # A, B의 원소가 다르면 뒤집어야 함
                A = flip_matrix(A, x, y)
                count += 1

            # 행렬 A, B가 동일한 경우
            if A == B:
                is_equal = True
                break

        if is_equal:
            break

    if A == B:
        print(count)
    else:
        print(-1)


if __name__ == "__main__":
    main()
