import tkinter as tk
from tkinter import messagebox, filedialog
from ctypes import cdll, c_void_p, c_int, c_double, c_char_p

class BankApp:
    def __init__(self, master):
        self.master = master
        self.master.title("Bank Application")

        self.bank = lib.Bank_new()

        tk.Button(master, text="Load Clients", command=self.load_clients).pack()
        tk.Button(master, text="Add Client", command=self.add_client).pack()
        tk.Button(master, text="Deposit", command=self.deposit).pack()
        tk.Button(master, text="Withdraw", command=self.withdraw).pack()
        tk.Button(master, text="View Balance", command=self.view_balance).pack()

    def load_clients(self):
        filename = filedialog.askopenfilename()
        if filename:
            lib.Bank_loadClients(self.bank, filename.encode())
            messagebox.showinfo("Success", "Clients loaded successfully")

    def deposit(self):
        # ask for client ID and amount via simple dialogs
        pass

# Load the shared library
lib = cdll.LoadLibrary("../backend/libclient_management.so")  # or .dll for Windows

if __name__ == "__main__":
    root = tk.Tk()
    app = BankApp(root)
    root.mainloop()
