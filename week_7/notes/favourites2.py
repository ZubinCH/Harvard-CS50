from cs50 import SQL


db = SQL("sqlite:///favs.db")

rows = db.execute("SELECT language, COUNT(*) AS n FROM favourites GROUP BY language ORDER BY n DESC")

for row in rows:
    print(row["language"], row["n"])

favourite = input("Favourite: ")

rows2 = db.execute(f"SELECT COUNT(*) AS n FROM favourites WHERE problem = '{favourite}' ")

row2 = rows2[0]
print(row2)