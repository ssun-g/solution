import sys

input = sys.stdin.readline


def main() -> None:
    A, B, C = map(int, input().rstrip('\n').split(' '))
    print((A + B) % C)
    print(((A % C) + (B % C)) % C)
    print((A * B) % C)
    print(((A % C) * (B % C)) % C)


if __name__ == "__main__":
    main()
