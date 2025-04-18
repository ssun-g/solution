"""
신기한 소수:
  - 4자리 수가 ABCD라고 가정하면, A, AB, ABC, ABCD가 모두 소수여야 함.
"""
import sys

input = sys.stdin.readline

N = int(input().rstrip('\n'))


# 소수 판별
def is_prime(n):
    if n <= 1:
        return False
    if n <= 3:
        return True
    if n % 2 == 0 or n % 3 == 0:
        return False

    i = 5
    while i * i <= n:
        if n % i == 0 or n % (i + 2) == 0:
            return False
        i += 6

    return True


def bf(num, digit):
    # 자리수가 N이라면
    if digit == N:
        print(num)
        return

    for i in range(10):
        next_num = num * 10 + i
        if is_prime(next_num):  # 소수이면 다음 길이로 넘어간다
            bf(next_num, digit + 1)


def main() -> None:
    bf(2, 1)
    bf(3, 1)
    bf(5, 1)
    bf(7, 1)


if __name__ == "__main__":
    main()
