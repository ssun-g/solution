"""
수를 묶는 기준(양수, 음수 배열이 나뉘어 있다고 가정)

(양수)
1. 가장 큰 수를 우선으로 묶는다.
2. 두 수에 0, 1이 포함되어 있다면 묶지 않는 경우가 값이 더 크다.

(음수)
1. 가장 작은 수를 우선으로 묶는다.
2. 가장 큰 값을 위해 무조건 묶는 것이 좋다.
"""
import sys

input = sys.stdin.readline


def main() -> None:
    N = int(input().rstrip('\n'))
    arr = [int(input().rstrip('\n')) for _ in range(N)]
    arr.sort(reverse=True)  # 내림차순 정렬

    # 음수와 양수를 각각 계산 하기 위해 기준(인덱스)을 찾는다.
    negative_index = N
    for i in range(N):
        if arr[i] <= 0:
            negative_index = i
            break

    # 양수 구간
    pos_max_sum = 0
    for i in range(0, negative_index - 1, 2):
        if (arr[i] != 1) and (arr[i + 1] != 1):  # 두 수중 1이 포함 되어 있지 않으면 묶는다.
            pos_max_sum += (arr[i] * arr[i + 1])
        else:
            pos_max_sum += (arr[i] + arr[i + 1])

    if negative_index % 2 != 0:
        pos_max_sum += arr[negative_index - 1]  # 양수 구간의 길이가 홀수이면 마지막 수를 더해준다.

    # 음수 구간
    neg_max_sum = 0
    if (N - negative_index) % 2 != 0:
        neg_max_sum += arr[negative_index]  # 음수 구간의 길이가 홀수이면 마지막 수(가장 큰 수)를 더해준다.

    for i in range(N - 1, negative_index, -2):  # 음수 구간은 작은 수부터 탐색
        neg_max_sum += (arr[i] * arr[i - 1])  # 음수는 무조건 묶는 것이 좋다.

    print(pos_max_sum + neg_max_sum)


if __name__ == "__main__":
    main()
