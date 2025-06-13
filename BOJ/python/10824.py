import sys

input = sys.stdin.readline


def main() -> None:
    A, B, C, D = map(str, input().rstrip('\n').split(' '))
    print(int(A + B) + int(C + D))


if __name__ == "__main__":
    main()
