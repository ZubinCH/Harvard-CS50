

def main():
    height = -5
    while height <= 0 or height >= 9:
        height = input("Height: ")
        if height.isnumeric():
            height = int(height)
        else:
            height = -5


    for i in range(1, height + 1):
        print((height - i) * " ", end = "")
        print(i * "#", end = "")
        print("  ", end = "")
        print(i * "#")


main()
