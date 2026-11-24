import sqlite3 as sql

conn = sql.connect("example.db")

cursor = conn.cursor()




conn.close()