"""
- nCr = n! / (n-m)!*r!
- 0의 개수는 2, 5의 개수중 적은것으로 결정됨
"""
import sys

input = sys.stdin.readline


# 인수 개수 세기(n: 구할 수, t: 개수를 셀 인수)
def calc_expo(n, t):
    cnt = 0
    while n > 0:
        cnt += n // t
        n //= t

    return cnt


def main() -> None:
    n, m = map(int, input().rstrip('\n').split(' '))

    cnt_five = calc_expo(n, 5) - (calc_expo(m, 5) + calc_expo(n - m, 5))  # n!의 5의 개수 - m!의 5의 개수 + (n-m)!의 5의 개수
    cnt_two = calc_expo(n, 2) - (calc_expo(m, 2) + calc_expo(n - m, 2))  # n!의 2의 개수 - m!의 2의 개수 + (n-m)!의 2의 개수

    print(min(cnt_five, cnt_two))


if __name__ == "__main__":
    main()
