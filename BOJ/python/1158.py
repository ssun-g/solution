import sys
from collections import deque


def main() -> None:
    input = sys.stdin.readline

    N, K = map(int, input().rstrip('\n').split())
    queue = deque(list(range(1, N + 1)))
    count = 0  # 순서 체크

    print("<", end='')
    while len(queue) != 1:  # 출력 형식을 맞추기 위해 마지막 사람은 제거하지 않음
        front = queue.popleft()  # 가장 앞 사람을 뽑는다
        count += 1
        if count % K == 0:  # K번째이면 제거
            print(f"{front}, ", end='')
        else:  # K번째가 아니면 맨 뒤로 보낸다
            queue.append(front)

    print(f"{queue[-1]}>")  # 마지막 사람 출력


if __name__ == "__main__":
    main()
