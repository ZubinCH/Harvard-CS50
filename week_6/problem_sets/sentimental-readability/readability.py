


def coleman_liau_index(text) -> float:
    letters = sentences = spaces = 0
    for char in text:
        if char == "." or char == "?" or char == "!":
            sentences += 1
        elif char.isalpha():
            letters += 1
        elif char == " ":
            spaces += 1

    words = spaces + 1

    L = letters / words * 100
    S = sentences / words * 100

    return round(0.0588 * L - 0.296 * S - 15.8)

def main():
    text = input("Text: ")

    index = coleman_liau_index(text)

    if index < 1:
        print("Before Grade 1")
    elif index >= 16:
        print("Grade 16+")
    else:
        print(f"Grade {index}")

main()

