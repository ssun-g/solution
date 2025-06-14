import sys
import string

input = sys.stdin.readline


def main() -> None:
    alpha = string.ascii_uppercase
    N, B = map(int, input().rstrip('\n').split(' '))
    result = ""

    while N >= B:
        mod = N % B
        # 나머지 더하기
        if mod >= 10:
            result += alpha[mod - 10]
        else:
            result += str(mod)

        N //= B

    # 마지막 몫 더하기
    if N >= 10:
        result += alpha[N - 10]
    else:
        result += str(N)

    # 거꾸로 출력
    print(result[::-1])


if __name__ == "__main__":
    main()
