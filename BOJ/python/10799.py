import sys

input = sys.stdin.readline


def main() -> None:
    pipe = input().rstrip("\n")

    p_cnt = 1
    total = 0
    for i in range(1, len(pipe)):
        if pipe[i] == ")":
            p_cnt -= 1
            if pipe[i - 1] == "(":  # 레이저
                total += p_cnt
            else:  # 레이저로 자른 뒤 남은 막대기 추가
                total += 1
        else:
            p_cnt += 1

    print(total)


if __name__ == "__main__":
    main()
