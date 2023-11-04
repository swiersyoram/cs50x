import csv
import sys


def main():
    # TODO: Check for command-line usage
    if len(sys.argv) != 3:
        sys.exit("Usage: python dna.py CSV SEQUENCE")



    # TODO: Read database file into a variable
    file = sys.argv[1]
    file = open(file)
    data = csv.DictReader(file)

    data_base = []
    subsequences = []
    for row in data:
        data_base.append(row)
        subsequences = [k for k,v in row.items()]
        subsequences.pop(0)
    # print(data_base)

    # TODO: Read DNA sequence file into a variable
    file = sys.argv[2]
    file = open(file)
    sequence = file.read()

    # TODO: Find longest match of each STR in DNA sequence
    # print(subsequences)
    result = []
    for s in subsequences:
        result.append([s,longest_match(sequence, s)])

    # print(result)

    # TODO: Check database for matching profiles
    # print(data_base)
    # print(result[0])
    match_name='No match'
    for record in data_base:
        match = 1
        for r in result:
            if(int(record[r[0]]) != r[1]):
                match = 0
        if(match):
            match_name = record['name']

    print(match_name)
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

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()
