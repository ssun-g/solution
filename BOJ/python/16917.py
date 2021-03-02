import sys

input = sys.stdin.readline

answer = 0
sauce, fried, halfnhalf, X, Y = map(int, input().split(" "))

# 양념 + 후라이드 가격이 반반 치킨을 두 마리(양념 한 마리, 후라이드 한 마리)사는 가격보다 싸다면 따로 시키는 것이 저렴하다.
if sauce + fried < 2 * halfnhalf:
    answer += sauce * X + fried * Y

# 그렇지 않다면 우선 양념, 후라이드 중 적게 구매하려는 치킨의 마리 수에 맞춰서 반반 치킨으로 시킨다.
else:
    answer += halfnhalf * 2 * min(X, Y)

    # 양념 치킨을 더 많이 시키는 경우
    if X > Y:
        # 양념 한 마리 가격 보다 반반 치킨 두 세트의 가격이 더 비싸다면
        # 양념으로 시키는 것이 더 싸고, 그렇지 않으면 양이 넘치더라도 반반 치킨으로 사는 편이 더 싸다.
        if sauce < 2 * halfnhalf:
            answer += (X - Y) * sauce
        else:
            answer += (X - Y) * 2 * halfnhalf

    # 후라이드 치킨을 더 많이 시키는 경우 (양념 치킨의 경우와 같다.)
    elif Y > X:
        if fried < 2 * halfnhalf:
            answer += (Y - X) * fried
        else:
            answer += (Y - X) * 2 * halfnhalf

print(answer)
