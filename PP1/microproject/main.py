# Create a program to manage the inventory of a bookstore, track sales, and update stock.
import tkinter as tk
from tkinter import messagebox
import sqlite3

# Initialize the database
conn = sqlite3.connect('bookstore.db')
c = conn.cursor()

# Create tables if they don't exist
c.execute('''CREATE TABLE IF NOT EXISTS inventory 
             (id INTEGER PRIMARY KEY AUTOINCREMENT, 
              title TEXT, 
              author TEXT, 
              price REAL, 
              stock INTEGER)''')

c.execute('''CREATE TABLE IF NOT EXISTS sales 
             (id INTEGER PRIMARY KEY AUTOINCREMENT, 
              title TEXT, 
              quantity INTEGER, 
              total REAL)''')

conn.commit()

# Functions to add, sell, and view stock
def add_book():
    title = entry_title.get()
    author = entry_author.get()
    price = entry_price.get()
    stock = entry_stock.get()
    
    if title and author and price and stock:
        c.execute("INSERT INTO inventory (title, author, price, stock) VALUES (?, ?, ?, ?)", 
                  (title, author, float(price), int(stock)))
        conn.commit()
        messagebox.showinfo("Success", "Book added to inventory")
    else:
        messagebox.showwarning("Input Error", "Please fill all fields")

def sell_book():
    title = entry_title.get()
    quantity = entry_quantity.get()

    if title and quantity:
        c.execute("SELECT stock, price FROM inventory WHERE title=?", (title,))
        result = c.fetchone()
        if result:
            stock, price = result
            if int(quantity) <= stock:
                total = float(quantity) * price
                new_stock = stock - int(quantity)
                
                c.execute("UPDATE inventory SET stock=? WHERE title=?", (new_stock, title))
                c.execute("INSERT INTO sales (title, quantity, total) VALUES (?, ?, ?)", 
                          (title, int(quantity), total))
                conn.commit()
                messagebox.showinfo("Success", f"Sold {quantity} of {title}. Total: ${total}")
            else:
                messagebox.showwarning("Stock Error", "Not enough stock")
        else:
            messagebox.showwarning("Error", "Book not found")
    else:
        messagebox.showwarning("Input Error", "Please fill all fields")

def view_stock():
    c.execute("SELECT * FROM inventory")
    books = c.fetchall()
    stock_list.delete(0, tk.END)
    for book in books:
        stock_list.insert(tk.END, f"Title: {book[1]}, Stock: {book[4]}")

# Set up the main application window
root = tk.Tk()
root.title("Bookstore Inventory Manager")

# Add book section
tk.Label(root, text="Add Book").grid(row=0, column=0, columnspan=2)
tk.Label(root, text="Title:").grid(row=1, column=0)
entry_title = tk.Entry(root)
entry_title.grid(row=1, column=1)

tk.Label(root, text="Author:").grid(row=2, column=0)
entry_author = tk.Entry(root)
entry_author.grid(row=2, column=1)

tk.Label(root, text="Price:").grid(row=3, column=0)
entry_price = tk.Entry(root)
entry_price.grid(row=3, column=1)

tk.Label(root, text="Stock:").grid(row=4, column=0)
entry_stock = tk.Entry(root)
entry_stock.grid(row=4, column=1)

tk.Button(root, text="Add Book", command=add_book).grid(row=5, column=0, columnspan=2)

# Sell book section
tk.Label(root, text="Sell Book").grid(row=6, column=0, columnspan=2)
tk.Label(root, text="Title:").grid(row=7, column=0)
entry_title_sell = tk.Entry(root)
entry_title_sell.grid(row=7, column=1)

tk.Label(root, text="Quantity:").grid(row=8, column=0)
entry_quantity = tk.Entry(root)
entry_quantity.grid(row=8, column=1)

tk.Button(root, text="Sell Book", command=sell_book).grid(row=9, column=0, columnspan=2)

# View stock section
tk.Button(root, text="View Stock", command=view_stock).grid(row=10, column=0, columnspan=2)
stock_list = tk.Listbox(root, width=50)
stock_list.grid(row=11, column=0, columnspan=2)

# Start the app
root.mainloop()

# Close database connection when app closes
conn.close()
