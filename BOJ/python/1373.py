import sys

input = sys.stdin.readline


def bin_to_oct(binary_num):
    cnt = 0
    eight_num = 0
    result = ""
    for i, n in enumerate(reversed(binary_num)):
        eight_num += int(n) * (2 ** (i % 3))

        if cnt % 3 == 2:  # 세자리씩 끊기
            result += str(eight_num)
            eight_num = 0

        cnt += 1

    result += str(eight_num)

    return int(result)


def main() -> None:
    binary_num = input().rstrip('\n')

    decimal = int(binary_num, 2)
    octal = oct(decimal)

    print(octal[2:])  # 접두어(0o) 제거
    # print(bin_to_oct(bin))  # 함수


if __name__ == "__main__":
    main()
