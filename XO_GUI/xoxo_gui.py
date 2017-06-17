import tkinter as tk
from tkinter import ttk
import string
import random
from threading import Thread


class Button:
    __count = 0

    def __init__(self, handler, txt):
        self.b = ttk.Button(handler, text = txt, command = self.action)
        self.fig = random.choice(string.ascii_letters)
    
    def action(self):
        print(Button.__count)
        if Button.__count % 2 == 0:
            self.b.config(text = 'X', state = 'disabled')
            self.fig = 'X'
            Button.__count += 1
        else:
            self.b.config(text = 'O', state = 'disabled')
            self.fig = 'O'
            Button.__count += 1

    def disable(self):
        self.b.config(state = 'disable')

    def colour(self):
        ttk.Style().configure('border.TButton', borderwidth= 3, font = ('Sans',
        12, 'bold'))
        self.b.configure(style = 'border.TButton')

class BoardGUI(Button):

    def __init__(self):
        self.win = tk.Tk()
        self.win.resizable(0,0)
        self.win.title("XOXOX GUI")
        self.c = -1
        self.buttons = []

        self.fram = ttk.LabelFrame(self.win, text = 'XOXOXO GUI', 
                padding = (6, 6, 12, 22))
        self.fram.grid(column = 0, row = 0)

        for i in range(9):
            self.buttons.append(Button(self.fram, '?'))
        
        self.lab = tk.Label(self.win, text = 'The winner is: ')
        self.lab.grid(column = 0, row = 1)

        self.res = tk.Label(self.win, text = ' ', anchor = 'w')
        self.res.grid(column = 0, row = 2)

        for i in range(1,4):
            self.c += 1
            for j in range(1,4):
                self.buttons[(j+ self.c*3) - 1].b.grid(column = j, row = i) 

    def winner(self, txt):
        self.res.config(text = txt)

    def checkWin(self):
        while Button._Button__count != 8:
            if self.buttons[0].fig == self.buttons[1].fig == self.buttons[2].fig:
                for i in [0,1,2]:
                    self.buttons[i].colour()
                self.winner(self.buttons[0].fig)
                break
            elif self.buttons[3].fig == self.buttons[4].fig == self.buttons[5].fig:
                for i in [3,4,5]:
                    self.buttons[i].colour()
                self.winner(self.buttons[3].fig)
                break
            elif self.buttons[6].fig == self.buttons[7].fig == self.buttons[8].fig:
                for i in [6,7,8]:
                    self.buttons[i].colour()
                self.winner(self.buttons[6].fig)
                break
            elif self.buttons[0].fig == self.buttons[3].fig == self.buttons[6].fig:
                for i in [0,3,6]:
                    self.buttons[i].colour()
                self.winner(self.buttons[0].fig)
                break
            elif self.buttons[1].fig == self.buttons[4].fig == self.buttons[7].fig:
                for i in [1,4,7]:
                    self.buttons[i].colour()
                self.winner(self.buttons[1].fig)
                break
            elif self.buttons[2].fig == self.buttons[5].fig == self.buttons[8].fig:
                for i in [2,5,8]:
                    self.buttons[i].colour()
                self.winner(self.buttons[2].fig)
                break
            elif self.buttons[0].fig == self.buttons[4].fig == self.buttons[8].fig:
                for i in [0,4,8]:
                    self.buttons[i].colour()
                self.winner(self.buttons[0].fig)
                break
            elif self.buttons[2].fig == self.buttons[4].fig == self.buttons[6].fig:
                for i in [2,4,6]:
                    self.buttons[i].colour()
                self.winner(self.buttons[2].fig)
                break
        for i in self.buttons:
            i.disable()



if __name__ == '__main__':
    G = BoardGUI()
    runT = Thread(target = G.checkWin)
    runT.setDaemon(True)
    runT.start()
    G.win.mainloop()
