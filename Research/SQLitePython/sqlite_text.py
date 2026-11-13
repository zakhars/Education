import sqlite3

conn = sqlite3.connect('address_book.sqlite')

cursor = conn.cursor()

cursor.execute('select * from addressbook')

for row in cursor.fetchall():
   print(f'{row[2]}, {row[0]}, {row[1]}')

cursor.close()
conn.close()