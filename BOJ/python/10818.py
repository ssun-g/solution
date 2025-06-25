import sys

input = sys.stdin.readline


def main() -> None:
    N = int(input().rstrip('\n'))
    arr = list(map(int, input().rstrip('\n').split(' ')))
    arr.sort()

    print(f"{arr[0]} {arr[-1]}")


if __name__ == "__main__":
    main()
