import csv


with open("favourites.csv", "r") as file:
    reader = csv.DictReader(file)

    counts = {}

    for row in reader:
        favourite = row["language"]

        if favourite not in counts:
            counts[favourite] = 0
        counts[favourite] += 1
        

        
for favourites in sorted(counts, key=counts.get, reverse = True):
    print(favourites, counts[favourites])
    