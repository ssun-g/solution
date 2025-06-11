import sys

input = sys.stdin.readline


def main() -> None:
    N = int(input().rstrip("\n"))
    points = [list(map(int, input().rstrip("\n").split(" "))) for _ in range(N)]
    points.sort(key=lambda x: (x[1], x[0]))

    for x, y in points:
        print(x, y)


if __name__ == "__main__":
    main()
