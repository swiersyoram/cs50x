# TODO
height = -1
while height < 1 or height > 8:
    height = input('Height: ')
    if height.isdigit():
        height = int(height)
    else:
        height = -1

for x in range(height):
    string = ''
    for y in range(height):
        if y > height-x-2:
            string += '#'
        else:
            string += ' '
    print(string)