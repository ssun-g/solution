import sys

input = sys.stdin.readline


def main() -> None:
    octal = input().rstrip('\n')

    decimal = int(octal, 8)
    binary = bin(decimal)

    print(binary[2:])


if __name__ == "__main__":
    main()
