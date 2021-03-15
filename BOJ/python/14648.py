import sys

input = sys.stdin.readline


def part_sum(start: int, end: int, query: list) -> int:
    """
    list의 구간 합을 구해준다.

    Args:
        start (int): 시작 위치 (문제에서 a or c)
        end (int): 끝 위치 (문제에서 b or d)
        query (list): 구간 합을 구할 list

    Returns:
        int: 구간 합을 반환 해준다.
    """
    ret = 0
    for i in range(start, end + 1):
        ret += query[i]

    return ret


n, q = map(int, input().rstrip("\n").split(" "))
query = list(map(int, input().rstrip("\n").split(" ")))
query.insert(0, 0)  # 첫 번째 index를 1로 설정하기 위해 0을 넣어준다.

for _ in range(q):
    command = list(map(int, input().rstrip("\n").split(" ")))
    if command[0] == 1:
        a = command[1]
        b = command[2]
        print(part_sum(a, b, query))
        query[a], query[b] = query[b], query[a]  # python swap
    else:
        a = command[1]
        b = command[2]
        c = command[3]
        d = command[4]
        print(part_sum(a, b, query) - part_sum(c, d, query))
