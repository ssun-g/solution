"""
가까운 마을을 (번호가 작은 마을)로 정의하고, 먼 마을을 (번호가 큰 마을)로 정의한다.

알고리즘
1. 지나온 마을을 되돌아 갈 수 없으므로, 배송을 받을 위치가 가까운 마을을 기준으로 오름차순 정렬한다.
2. 택배 배송 구간마다 트럭에 실려있는 박스 수를 계산한다.
3. 택배를 배송하면서 추가로 실을 수 있는 박스 수를 계산한다.
4. 추가로 싣는 경우 최대 박스 수를 갱신할 수 있다.
"""
import sys
import heapq as hq

input = sys.stdin.readline


def main() -> None:
    N, C = map(int, input().rstrip('\n').split(' '))
    M = int(input().rstrip('\n'))
    express = [list(map(int, input().rstrip('\n').split(' '))) for _ in range(M)]
    express.sort(key=lambda x: x[1])

    capacity = [0] * (N + 1)
    max_capacity = 0
    for send, receive, n_boxes in express:
        max_boxes = max(capacity[send:receive])  # send~receive 구간 택배 배송 중 박스가 최대로 실려 있을 때의 값
        add_boxes = min(n_boxes, C - max_boxes)  # 추가로 트럭에 실을 수 있는 박스 수

        # 추가로 박스를 실을 수 있는 경우 최대 박스 수를 갱신해준다.
        if add_boxes > 0:
            for i in range(send, receive):
                capacity[i] += add_boxes
            max_capacity += add_boxes

    print(max_capacity)


if __name__ == "__main__":
    main()
