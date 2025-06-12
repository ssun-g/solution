import sys

input = sys.stdin.readline


def main() -> None:
    N, K = map(int, input().rstrip("\n").split(" "))
    arr = list(map(int, input().rstrip("\n").split(" ")))
    arr.sort()
    print(arr[K - 1])


if __name__ == "__main__":
    main()
