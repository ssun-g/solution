import sys

input = sys.stdin.readline


def main() -> None:
    password = input().rstrip("\n")

    # 맨 앞 숫자가 0인 경우 틀린 암호
    if password[0] == "0":
        return 0

    # dp 초기 값
    dp = [0] * (len(password) + 1)
    dp[0] = 1
    dp[1] = 1

    for i in range(2, len(password) + 1):
        prev_num = int(password[i - 2])
        cur_num = int(password[i - 1])
        two_digits = prev_num * 10 + cur_num  # 두자리로 합쳤을 때의 수

        # 바로 직전 상태에서 한자리 암호를 추가하는 경우
        if cur_num > 0:
            dp[i] += dp[i - 1] % 1000000

        # 2단계 이전 상태에서 두자리 암호를 추가하는 경우
        if 10 <= two_digits <= 26:
            dp[i] += dp[i - 2] % 1000000

    return dp[len(password)] % 1000000


if __name__ == "__main__":
    print(main())
