import tkinter as tk
from tkinter import ttk
from labelEntry import *
from tkinter import messagebox as mBox
from ftplib import FTP
from tkinter import filedialog
from FTPconn import *
import ftplib
import os

class mainWin:
    def _msgBox(self, num, text):
        if num == 1:
            mBox.showinfo('Python Message Info Box', text)
        elif num == 2:
            mBox.showwarning('Python Message Warning Box', text)
        else:
            mBox.showerror('Python Message Error Box', text)

    def getConnected(self):
        server = self.server.entryVar.get()
        usr = self.user.entryVar.get()
        passwd = self.password.entryVar.get()
        if self.server.entryVar.get() == '' or self.user.entryVar.get() == '' or self.password.entryVar.get() == '':
            self._msgBox(1, 'Fill all entry fields')
            return 1
        try:
            self.connection = FTPCon(server, usr, passwd)
        except ftplib.all_errors as e:
            errorcode_string = str(e).split(None, 1)[0]
            self._msgBox(2, e)
            return 2
        self._msgBox(1, "Connection successfull!")
        self.C = FileWin(self.connection)

    def __init__(self):
        self.win = tk.Tk()
        self.win.title("FTP Client v.1.0")
        
        self.server = LabelAndEntryWidget(self.win, 'Server: ', 0, 0, 20)
        self.user = LabelAndEntryWidget(self.win, 'Username: ', 0, 1, 20)
        self.password = LabelAndEntryWidget(self.win, 'Password: ', 0, 2, 20)
        self.password.entry['show'] = '*'

        self.connect = tk.Button(self.win, text = 'Connect', command = self.getConnected)
        self.connect.grid(column = 0, row = 3)
        self.connection= ''

class FileWin(mainWin):
    def listFiles(self, windowHandler, ftpObject):
        self.listBox = tk.Listbox(windowHandler, height = 20)
        self.listBox.grid(column = 0, row = 0, sticky = (tk.N, tk.W, tk.E, tk.S))
        self.scrollBar = ttk.Scrollbar(windowHandler, orient = tk.VERTICAL,
                command = ftpObject.getFiles)
        self.scrollBar.grid(column = 1, row = 0, sticky = (tk.N, tk.S))
        self.listBox['yscrollcommand'] = self.scrollBar.set    
        ttk.Sizegrip().grid(column = 1, row = 1, sticky = (tk.S, tk.E))
        windowHandler.grid_columnconfigure(0, weight = 1)
        windowHandler.grid_rowconfigure(0, weight = 1)
        for filename in ftpObject.getFiles():
            print(filename)
            self.listBox.insert(tk.END, filename)     

    def upload(self):
        self.filename = filedialog.askopenfilename()
        print(self.filename)
        FTPCon.uploadFile(self)
        FileWin.listFiles(self, self.fwin, self.conn)

    def download(self):
        self.dlfilename = self.listBox.get(self.listBox.curselection())
        print(self.dlfilename)
        FTPCon.downloadFile(self)
        FileWin.listFiles(self, self.fwin, self.conn)


    def __init__(self, connection):
        self.conn = connection
        self.fwin = tk.Tk()
        self.fwin.title('File window')
        self.upload = tk.Button(self.fwin, text = 'Upload', command =
                self.upload)
        self.upload.grid(column = 0, row = 2)
        self.download = tk.Button(self.fwin, text = 'Download', command =
                self.download)
        self.download.grid(column = 0, row = 3)
        FileWin.listFiles(self, self.fwin, connection)

if __name__ == '__main__':
    C = mainWin()
    C.win.mainloop()

