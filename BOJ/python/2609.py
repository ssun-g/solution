import sys
import math

input = sys.stdin.readline


def main() -> None:
    A, B = map(int, input().rstrip('\n').split(' '))

    gcd = math.gcd(A, B)
    lcm = abs(A * B) // gcd

    print(gcd)
    print(lcm)


if __name__ == "__main__":
    main()
