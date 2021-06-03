import sys

input = sys.stdin.readline


def eratos(n):
    """
    Sieve of Eratosthenes

    Args:
        n (int): search prime number from 2 to n+1

    Returns:
        list: list of prime number
    """
    is_prime = [True] * (n + 1)
    for i in range(2, n + 1):
        if is_prime[i]:
            for j in range(i + i, n + 1, i):
                is_prime[j] = False

    return [i for i in range(2, n + 1) if is_prime[i]]


answer = 0
N = int(input().rstrip("\n"))


prime_list = eratos(N)
left = right = Sum = 0

# all of cases (prime number sum)
while left <= right:
    if Sum >= N:
        Sum -= prime_list[left]
        left += 1
    elif right == len(prime_list): # out of range
        break
    else:
        Sum += prime_list[right]
        right += 1

    if Sum == N:
        answer += 1

print(answer)
