import sys

N, M = map(int, sys.stdin.readline().split())
pokemon = {}

for i in range(N):
    mon = sys.stdin.readline().strip()
    pokemon[i+1] = mon

reverse = dict(map(reversed, pokemon.items()))

for i in range(M):
    order = sys.stdin.readline().strip()
    if order.isdigit():
        print(pokemon[int(order)])
    else:
        print(reverse[order])