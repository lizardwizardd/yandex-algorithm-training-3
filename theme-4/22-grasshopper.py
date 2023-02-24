N, k = map(int, input().split())

if k > N:
    k = N

desk = [0] * (N + k)
desk[k] = 1

for i in range(k, N + k):
    for j in range(i - 1, i - k - 1, -1):
        desk[i] += desk[j]

print(desk[N + k - 1])