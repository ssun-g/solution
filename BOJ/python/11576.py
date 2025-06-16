import sys

input = sys.stdin.readline


# 진법 변환
def A_to_B(A, B, num):
    # A to Decimal
    decimal = 0
    for i, n in enumerate(reversed(num)):
        decimal += n * (A ** i)

    # Decimal to B
    result = []
    while B <= decimal:
        mod = decimal % B
        decimal //= B
        result.append(mod)

    result.append(decimal)

    return result[::-1]


def main() -> None:
    A, B = map(int, input().rstrip('\n').split(' '))
    m = int(input().rstrip('\n'))
    num = list(map(int, input().rstrip('\n').split(' ')))

    print(*A_to_B(A, B, num))


if __name__ == "__main__":
    main()
