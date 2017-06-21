from ftplib import FTP

class FTPCon:
    def __init__(self, server, usr, passwd):
        self.ftp = FTP(server)
        self.ftp.set_debuglevel(2)
        self.ftp.login(usr,passwd)
        self.list = []

    def getFiles(self):
        self.list = self.ftp.nlst()
        return self.list

    def uploadFile(self):
        upFile = open(self.filename,'rb')
        self.pathList = self.filename.split('/')
        self.conn.ftp.storbinary('STOR ' + self.pathList[-1], upFile)     
        upFile.close() 

    def downloadFile(self):
        self.conn.ftp.cwd('/home/dziko/FTP')
        dwlFile = open(self.dlfilename, 'wb')
        self.conn.ftp.retrbinary('RETR ' + self.dlfilename, dwlFile.write)
        dwlFile.close()
    
