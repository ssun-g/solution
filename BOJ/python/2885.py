import sys
import math

input = sys.stdin.readline


def main() -> None:
    K = int(input().rstrip('\n'))

    # 최소 초콜릿 크기 구하기
    chocolate = 0
    for i in range(int(math.sqrt(K)) + 2):
        if K <= (1 << i):
            chocolate = (1 << i)
            break

    print(chocolate, end=' ')

    # 쪼개는 최소 횟수 구하기
    cut_count = 0
    if (K & (K - 1)) != 0:  # 거듭제곱 형태가 아닌 경우에만 계산
        while 0 < K:
            chocolate //= 2  # 초콜릿 자르기
            cut_count += 1
            if chocolate <= K:  # 초콜릿이 더 필요한 경우
                K -= chocolate

    print(cut_count)


if __name__ == "__main__":
    main()
