import sys
import math

input = sys.stdin.readline


def GCD(a, b):
    while b != 0:
        temp = b
        b = a % b
        a = temp

    return a


def main() -> None:
    T = int(input().rstrip('\n'))
    for _ in range(T):
        A, B = map(int, input().rstrip('\n').split(' '))

        # gcd = math.gcd(A, B)  # math 라이브러리
        gcd = GCD(A, B)  # 함수 구현
        lcm = abs(A * B) // gcd
        print(lcm)


if __name__ == "__main__":
    main()
