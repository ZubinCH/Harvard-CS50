


def valid(card_number) -> bool:
    if not card_number.isdigit():
        return False

    total = 0
    double = False

    for i in card_number[::-1]:
        number = int(i)

        if double:
            number *= 2
            if number >= 10:
                number -= 9
        total += number
        double = not double
    return True if total % 10 == 0 else False

def card_type(card_number) -> str:
    first_number = int(card_number[0])
    second_number = int(card_number[1])
    number_length = len(card_number)

    match first_number:
        case 3:
            if number_length != 15 or (second_number != 4 and second_number != 7):
                return "INVALID"
            return "AMEX"
        case 4:
            if number_length == 16 or number_length == 13:
                return "VISA"
            return "INVALID"
        case 5:
            if (1 <= second_number <= 5) and number_length == 16:
                return "MASTERCARD"
            return "INVALID"
        case _:
            return "INVALID"

        
def main():
    number = input("Number: ")

    if valid(number):
        print(card_type(number))
    else:
        print("INVALID")


main()




    
            