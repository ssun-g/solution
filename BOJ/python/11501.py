"""
현재에 주식을 사서 미래에 판매하는 것으로 생각하기 보다, 과거에 사서 현재에 판다는 개념으로 생각하면 좀 더 쉬움.
=> (과거~현재) 중 가장 비싼 가격을 찾아서 과거에 산 주식들을 판다.
=> 예를 들어, 주가가 [1, 1, 3, 1, 2]인 경우 주가가 2인 시간을 현재라고 본다.
"""
import sys

input = sys.stdin.readline


def main() -> None:
    T = int(input().rstrip('\n'))
    for _ in range(T):
        N = int(input().rstrip('\n'))
        stock = list(map(int, input().rstrip('\n').split(' ')))

        highest_price = stock[-1]  # 가장 마지막 날의 가격
        max_profit = 0
        for i in range(len(stock) - 2, -1, -1):
            prev_price = stock[i]
            if prev_price < highest_price:  # 현재 가격보다 싸게 산 주식들을 판다
                max_profit += highest_price - prev_price
            else:  # 더 비싼 주가 업데이트(아무것도 안하는 경우)
                highest_price = prev_price

        print(max_profit)


if __name__ == "__main__":
    main()
