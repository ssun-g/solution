"""
가장 고리의 개수가 적은 체인부터 사용하여 체인끼리 연결한다.

1. 가장 고리의 개수가 적은 체인이 나머지 체인 개수 이상이면, 해당 체인으로 모두 연결할 수 있다.
2. 나머지 체인의 개수보다 적다면, 모두 연결할 때까지 개수가 적은 체인을 사용한다.
"""
import sys

input = sys.stdin.readline


def main() -> None:
    N = int(input().rstrip('\n'))
    chain = list(map(int, input().rstrip('\n').split(' ')))
    chain.sort()

    count = 0
    remain = N
    if remain == 2:
        print(1)
    else:
        i = 0
        while remain > 1:
            min_ring = chain[i]  # 가장 고리의 개수가 적은 체인의 고리 개수
            remain -= 1
            if remain < min_ring:  # 남은 체인의 개수보다 고리의 개수가 많으면
                count += remain  # 모두 연결 가능
                break
            elif remain == min_ring:  # 남은 체인의 개수와 고리의 개수가 같으면
                count += min_ring  # 고리의 개수만큼 연결
                break
            else:  # 남은 체인의 개수가 고리의 개수보다 적으면
                count += min_ring  # 연결 가능한 개수만큼 연결
                remain -= min_ring  # 남은 체인 개수 갱신
            i += 1

        print(count)


if __name__ == "__main__":
    main()
