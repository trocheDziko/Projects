import tkinter as tk
from tkinter import ttk

class LabelAndEntryWidget:
    """Class to making label and entry widget using tkinter.
    Use:
        VarName = LabelAndEntryWidget(window handler, label text, row of ttk,
        column of ttk, width of Entry widget)
    Return:
        instance.entryVar -> text value in entry field.
    """
    def __init__(self, window, labelText, col, row, entryWidth):
        self.label = ttk.Label(window, text = labelText)
        self.label.grid(column = col, row = row, padx = 10, pady = 10)
        
        self.entryVar = tk.StringVar()
        self.entry = ttk.Entry(window, width = entryWidth, textvariable=self.entryVar)
        self.entry.grid(column=col+1, row=row, sticky = tk.W, padx = 10, pady = 10)

if __name__ == '__main__':
    win = tk.Tk()
    C = LabelAndEntryWidget(win, 'Test: ', 0, 20)
    win.mainloop()
