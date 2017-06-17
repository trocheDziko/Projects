class Board:
    def __init__(self):
        self.figs = ['X','O']
        self.board = {'1':'1','2':'2','3':'3',
                '4':'4','5':'5','6':'6',
                '7':'7','8':'8','9':'9'}
    
    def move(self, figure, pos):
        self.board[pos] = figure

    def draw(self):
        counter = 0
        for i in sorted(self.board.keys()):
            if counter%3 == 0: 
                print()
            print('|' + str(self.board[i]) + '|', end = '')
            counter += 1
        print('\n')

    def checkWinner(self):
        if self.board['1'] == self.board['2'] == self.board['3']:
            print('The winner is ' + self.board['1'])
            return 0
        elif self.board['4'] == self.board['5'] == self.board['6']:
            print('The winner is ' + self.board['4'])
            return 0
        elif self.board['7'] == self.board['8'] == self.board['9']:
            print('The winner is ' + self.board['7'])
            return 0
        elif self.board['1'] == self.board['4'] == self.board['7']:
            print('The winner is ' + self.board['1'])
            return 0
        elif self.board['2'] == self.board['5'] == self.board['8']:
            print('The winner is ' + self.board['2'])
            return 0
        elif self.board['3'] == self.board['6'] == self.board['9']:
            print('The winner is ' + self.board['3'])
            return 0
        elif self.board['1'] == self.board['5'] == self.board['9']:
            print('The winner is ' + self.board['1'])
            return 0
        elif self.board['3'] == self.board['5'] == self.board['7']:
            print('The winner is ' + self.board['3'])
            return 0

class Game:
    def __init__(self):
        self.gameBoard = Board()
        self.end = False
        self.gameBoard.draw()
        self.count = 0

    def start(self):
        while self.end != True: 
            print('Input figure (X or O) and filed, where you want to place it')
            fig = input('Figure: ')
            if not fig in self.gameBoard.figs:
                print('Use only X or O')
                continue
            fld = input('Field: ')
            if not int(fld) in list(range(1,10)):
                print('Use only numbers from 1 to 9. See first board.')
                continue
            self.gameBoard.move(fig, fld)
            self.gameBoard.draw()
            if self.gameBoard.checkWinner() == 0: break;
            self.count += 1
            if self.count == 8: self.end = True

if __name__ == '__main__':
    g = Game()
    g.start()


