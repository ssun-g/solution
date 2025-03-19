import sys

input = sys.stdin.readline


def is_repeat(seq):
    max_repeat_len = len(seq) // 2  # 최대로 반복 가능한 부분 수열의 길이

    for i in range(1, max_repeat_len + 1):
        if seq[-i:] == seq[-i * 2 : -i]:
            return True

    return False


def make_good_seq(seq):
    global N

    # 중복 부분 수열이 있는 경우 False 리턴
    if is_repeat(seq):
        return False

    # 수열을 만들었으면 출력하고 True를 리턴하여 함수 전체가 종료 되도록 한다
    if len(seq) == N:
        print(seq)
        return True

    for i in range(1, 4):
        if make_good_seq(seq + str(i)):
            return True

    return False


def main() -> None:
    global N

    N = int(input().rstrip("\n"))

    make_good_seq("")


if __name__ == "__main__":
    main()
