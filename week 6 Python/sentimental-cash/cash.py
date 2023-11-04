# TODO
from decimal import Decimal


def is_float(string):
    try:
        float(string)
        return True
    except ValueError:
        return False


change = -1

while change <= 0:
    change = input("Change owed: ")
    if is_float(change):
        change = float(change)
    else:
        change = -1

coins = 0

while change >= 0.25:
    change = round(change - 0.25, 2)
    coins += 1
while change >= 0.10:
    change = round(change - 0.10,2)
    coins += 1
while change >= 0.05:
    change = round(change - 0.05,2)
    coins += 1
while change >= 0.01:
    change = round(change - 0.01,2)
    coins += 1

print(coins)