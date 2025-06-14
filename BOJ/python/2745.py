import sys
import string

input = sys.stdin.readline


def main() -> None:
    alpha = {string.ascii_uppercase[i]: i + 10 for i in range(26)}
    N, B = map(str, input().rstrip('\n').split(' '))
    B = int(B)

    result = 0
    for i, n in enumerate(reversed(N)):
        if n.isalpha():  # 알파벳인 경우
            result += alpha[n] * (B ** i)
        else:  # 숫자인 경우
            result += int(n) * (B ** i)

    print(result)


if __name__ == "__main__":
    main()
