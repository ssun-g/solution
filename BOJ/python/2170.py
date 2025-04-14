"""
1. 시작점을 기준으로 오름차순 정렬
2. 이전의 선과 비교해 겹치는 부분이 있으면 끝점 업데이트
3. 겹치지 않는다면, 이전까지 그은 선의 길이를 구하고 시작점, 끝점 업데이트
"""
import sys

input = sys.stdin.readline


def main() -> None:
    N = int(input().rstrip('\n'))
    line = [list(map(int, input().rstrip('\n').split(' '))) for _ in range(N)]
    line.sort(key=lambda x: (x[0], x[1]))  # 오름차순 정렬, line[0][0]이 시작점

    total = 0
    prev_start, prev_end = line[0]
    for cur_start, cur_end in line[1:]:

        # 선이 겹치는 경우
        if cur_start <= prev_end:
            prev_end = max(prev_end, cur_end)  # 끝점 업데이트

        # 선이 겹치지 않는 경우
        else:
            total += (prev_end - prev_start)  # 이전까지 그은 선의 길이 계산
            prev_start = cur_start  # 시작점 업데이트
            prev_end = cur_end  # 끝점 업데이트

    print(total + (prev_end - prev_start))  # 마지막 선의 길이 계산


if __name__ == "__main__":
    main()
