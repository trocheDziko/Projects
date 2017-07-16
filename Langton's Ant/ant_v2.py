import pygame
import pygame.locals
import sys, random

WHITE = (255,255,255)
BLACK = (0,0,0)
GRAY = (30, 30, 30)
RED = (255, 0, 0)
BLUE = (0, 0, 255)
GREEN = (0, 255, 0)

class Singleton(object):
    _instance = None
    def __new__(class_, *args, **kwargs):
        if not isinstance(class_._instance, class_):
            class_._instance = object.__new__(class_, *args, **kwargs)
        return class_._instance

class Board(Singleton):
    a = [[0 for x in range(300)] for i in range(150)]
    _width = 1024
    _height = 768
    _grille = 6
    _boardWidth = int(_width / _grille)
    _boardHeight = int(_height / _grille)

    def __init__(self):
        self._map = pygame.display.set_mode(((len(Board.a[0])*self._grille),
            len(Board.a)*self._grille))
    
    def net(self):
        x, y = 0, 0
        #for x in range(0, self._width, self._grille):
        #    pygame.draw.line(self._map, GRAY, (x, 0), (x, self._height))
        #for y in range(0, self._height, self._grille):
        #    pygame.draw.line(self._map, GRAY, (0, y), (self._width, y))
        for i in enumerate(Board.a):
            if i[0] > 0:
                y += self._grille
                x = 0
            for j in i[1]:
                r = pygame.Rect(x, y, self._grille, self._grille)
                pygame.draw.rect(self._map, (0,0,0), r)
                rinside = pygame.Rect(x + 1, y + 1, self._grille - 2,
                        self._grille - 2)
                pygame.draw.rect(self._map, (255,255,255), rinside)
                x += self._grille
        
class Game:
    def __init__(self):
        self._FPS = 100
        self._board = Board()
        pygame.init()
        self._clock = pygame.time.Clock()
        self._antGame1 = Ant()
        self._antGame2 = Ant()
        self._antGame3 = Ant()
        print(self._antGame1, self._antGame2, self._antGame3, end ='\n')

    def quit(self):
            pygame.quit()
            sys.exit()
                
    
    def startGame(self):
        #self._board._map.fill(WHITE)
        self._board.net()
        while True:
            for event in pygame.event.get():
                if event.type == pygame.QUIT:
                    self.quit()

            self._antGame1.move(BLACK)
            self._antGame2.move(RED)
            self._antGame3.move(BLUE)
            pygame.display.update()
            self._clock.tick(self._FPS)
        
class Ant():
    def __init__(self):
        self._b = Board()
        self._start_x = random.randint(len(Board.a[0])//2, len(Board.a[0])) 
        self._start_y = random.randint(len(Board.a)//2, len(Board.a))
        print(self._start_x, self._start_y)
        self._ant = [{'x': self._start_x, 'y': self._start_y}]
        print(self._ant)
        self._direction = 'up'
        self.col = self._b.a[self._ant[0]['y']][self._ant[0]['x']]
        
    def drawAnt(self, color):
        for cor in self._ant:
            _x = cor['x'] * self._b._grille + 1
            _y = cor['y'] * self._b._grille + 1
            print(_x,_y)
            ant_body = pygame.Rect(_x, _y, self._b._grille, self._b._grille)
            pygame.draw.rect(self._b._map, color, ant_body)

    def move(self, color):
        print(self.col)
        if self.col == 0:
            self.drawAnt(color)
            self._b.a[self._ant[0]['y']][self._ant[0]['x']] = 1
            if self._direction == 'up':
                self._ant[0]['x'] = self._ant[0]['x'] + 1
                self.col = self._b.a[self._ant[0]['y']][self._ant[0]['x']]
                self._direction = 'left'
                self.drawAnt(GREEN)
            elif self._direction == 'left':
                self._ant[0]['y'] = self._ant[0]['y'] + 1
                self.col = self._b.a[self._ant[0]['y']][self._ant[0]['x']]
                self._direction = 'down'
                self.drawAnt(GREEN)
            elif self._direction == 'down':
                self._ant[0]['x'] = self._ant[0]['x'] - 1
                self.col = self._b.a[self._ant[0]['y']][self._ant[0]['x']]
                self._direction = 'right'
                self.drawAnt(GREEN)
            else:
                self._ant[0]['y'] = self._ant[0]['y'] - 1
                self.col = self._b.a[self._ant[0]['y']][self._ant[0]['x']]
                self._direction = 'up'
                self.drawAnt(GREEN)

        elif self.col == 1:
            self.drawAnt(WHITE)
            self._b.a[self._ant[0]['y']][self._ant[0]['x']] = 0
            if self._direction == 'up':
                self._ant[0]['x'] = self._ant[0]['x'] - 1
                self.col = self._b.a[self._ant[0]['y']][self._ant[0]['x']]
                self._direction = 'right'
                self.drawAnt(GREEN)
            elif self._direction == 'left':
                self._ant[0]['y'] = self._ant[0]['y'] - 1
                self.col = self._b.a[self._ant[0]['y']][self._ant[0]['x']]
                self._direction = 'up'
                self.drawAnt(GREEN)
            elif self._direction == 'down':
                self._ant[0]['x'] = self._ant[0]['x'] + 1
                self.col = self._b.a[self._ant[0]['y']][self._ant[0]['x']]
                self._direction = 'left'
                self.drawAnt(GREEN)
            else:
                self._ant[0]['y'] = self._ant[0]['y'] + 1
                self.col = self._b.a[self._ant[0]['y']][self._ant[0]['x']]
                self._direction = 'down'
                self.drawAnt(GREEN)
                

if __name__ == '__main__':
    g = Game()
    g.startGame()
