import sys

input = sys.stdin.readline


def main() -> None:
    is_prime = [True] * 1001
    is_prime[0] = False
    is_prime[1] = False

    # 2부터 sqrt(1000)까지
    for i in range(2, int(1000 ** 0.5) + 1):
        if is_prime[i]:
            # i의 배수는 소수가 아님
            for j in range(i * i, 1001, i):
                is_prime[j] = False

    N = int(input().rstrip('\n'))
    num = list(map(int, input().rstrip('\n').split(' ')))

    cnt = 0
    for n in num:
        if is_prime[n]:
            cnt += 1

    print(cnt)


if __name__ == "__main__":
    main()
