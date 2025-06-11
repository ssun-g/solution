import sys

input = sys.stdin.readline


def main() -> None:
    T = int(input().rstrip("\n"))
    for _ in range(T):
        A, B = map(int, input().rstrip("\n").split(" "))
        print("yes")


if __name__ == "__main__":
    main()
