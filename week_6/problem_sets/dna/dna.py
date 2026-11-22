import csv
import sys


def main():

    # TODO: Check for command-line usage
    if len(sys.argv) != 3:
        print("Usage: python3 dna.py [database.csv] [sequence.txt]")
        return

    # TODO: Read database file into a variable
    database_rows = []

    with open(sys.argv[1], "r", encoding="utf-8-sig") as database:
        database_dict = csv.DictReader(database)
        database_subsequences = database_dict.fieldnames[1:]
        for row in database_dict:
            database_rows.append(row)

    # TODO: Read DNA sequence file into a variable
    with open(sys.argv[2], "r") as sequence_file:
        sequence = sequence_file.read().strip()

    # TODO: Find longest match of each STR in DNA sequence
    subsequence_counts = []
    for subsequence in database_subsequences:
        subsequence_counts.append(longest_match(sequence, subsequence))

    # TODO: Check database for matching profiles
    person_found = False
    for person in database_rows:
        i = 0
        is_person = True

        while (is_person and i < len(database_subsequences)):
            if int(person[database_subsequences[i]]) != subsequence_counts[i]:
                is_person = False
                break
            i += 1

        if i == len(database_subsequences) and is_person:
            print(person["name"])
            person_found = True


    if not person_found:
        print("No match")
        


    return


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1
            
            # If there is no match in the substring
            else:
                break
        
        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in sequence, return longest run found
    return longest_run


main()
