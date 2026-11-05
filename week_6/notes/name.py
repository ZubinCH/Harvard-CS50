import os

_ = os.subprocess('clear')
print("Code: ")

while (True):
    n = input("Input: ")
    if n.isnumeric():
        print("Integer")
    else:
        print("Not integer")


