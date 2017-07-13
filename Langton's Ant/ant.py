import pygame
import pygame.locals
import sys, random

WHITE = (255,255,255)
BLACK = (0,0,0)
GRAY = (30, 30, 30)
GREEN = (0, 255, 0)

class Singleton(object):
    _instance = None
    def __new__(class_, *args, **kwargs):
        if not isinstance(class_._instance, class_):
            class_._instance = object.__new__(class_, *args, **kwargs)
        return class_._instance

class Board(Singleton):
    _width = 1024
    _height = 768
    _grille = 2
    _boardWidth = int(_width / _grille)
    _boardHeight = int(_height / _grille)

    def __init__(self):
        self._map = pygame.display.set_mode((self._width, self._height))
    
    def net(self):
        for x in range(0, self._width, self._grille):
            pygame.draw.line(self._map, GRAY, (x, 0), (x, self._height))
        for y in range(0, self._height, self._grille):
            pygame.draw.line(self._map, GRAY, (0, y), (self._width, y))

class Game:
    def __init__(self):
        self._FPS = 1000
        self._board = Board()
        pygame.init()
        self._clock = pygame.time.Clock()
        self._antGame = Ant()

    def quit(self):
            pygame.quit()
            sys.exit()
                
    
    def startGame(self):
        self._board._map.fill(WHITE)
        self._board.net()
        while True:
            for event in pygame.event.get():
                if event.type == pygame.QUIT:
                    self.quit()

            self._antGame.move()
            pygame.display.update()
            self._clock.tick(self._FPS)
        
class Ant(Board):
    def __init__(self):
        self._b = Board()
        self._start_x = random.randint(5, Board._boardWidth - 6) 
        self._start_y = random.randint(5, Board._boardHeight - 6)
        self._ant = [{'x': self._start_x, 'y': self._start_y}]
        self._direction = 'up'
        self.col = WHITE

    def drawAnt(self, color):
        for cor in self._ant:
            x = cor['x'] * self._b._grille + 1
            y = cor['y'] * self._b._grille + 1
            ant_body = pygame.Rect(x, y, self._b._grille, self._b._grille)
            pygame.draw.rect(self._b._map, color, ant_body)

    def move(self):
        print(self.col)
        if self.col == WHITE:
            self.drawAnt(BLACK)
            if self._direction == 'up':
                self._ant[0]['x'] = self._ant[0]['x'] + 1
                self.col = self._b._map.get_at((((self._ant[0]['x']* self._b._grille)+(self._b._grille//2)), ((self._ant[0]['y']* self._b._grille)+(self._b._grille//2))))
                self._direction = 'left'
                self.drawAnt(GREEN)
            elif self._direction == 'left':
                self._ant[0]['y'] = self._ant[0]['y'] + 1
                self.col = self._b._map.get_at((((self._ant[0]['x']* self._b._grille)+(self._b._grille//2)), ((self._ant[0]['y']* self._b._grille)+(self._b._grille//2))))
                self._direction = 'down'
                self.drawAnt(GREEN)
            elif self._direction == 'down':
                self._ant[0]['x'] = self._ant[0]['x'] - 1
                self.col = self._b._map.get_at((((self._ant[0]['x']* self._b._grille)+(self._b._grille//2)), ((self._ant[0]['y']* self._b._grille)+(self._b._grille//2))))
                self._direction = 'right'
                self.drawAnt(GREEN)
            else:
                self._ant[0]['y'] = self._ant[0]['y'] - 1
                self.col = self._b._map.get_at((((self._ant[0]['x']* self._b._grille)+(self._b._grille//2)), ((self._ant[0]['y']* self._b._grille)+(self._b._grille//2))))
                self._direction = 'up'
                self.drawAnt(GREEN)

        elif self.col == BLACK:
            self.drawAnt(WHITE)
            if self._direction == 'up':
                self._ant[0]['x'] = self._ant[0]['x'] - 1
                self.col = self._b._map.get_at((((self._ant[0]['x']* self._b._grille)+(self._b._grille//2)), ((self._ant[0]['y']* self._b._grille)+(self._b._grille//2))))
                self._direction = 'right'
                self.drawAnt(GREEN)
            elif self._direction == 'left':
                self._ant[0]['y'] = self._ant[0]['y'] - 1
                self.col = self._b._map.get_at((((self._ant[0]['x']* self._b._grille)+(self._b._grille//2)), ((self._ant[0]['y']* self._b._grille)+(self._b._grille//2))))
                self._direction = 'up'
                self.drawAnt(GREEN)
            elif self._direction == 'down':
                self._ant[0]['x'] = self._ant[0]['x'] + 1
                self.col = self._b._map.get_at((((self._ant[0]['x']* self._b._grille)+(self._b._grille//2)), ((self._ant[0]['y']* self._b._grille)+(self._b._grille//2))))
                self._direction = 'left'
                self.drawAnt(GREEN)
            else:
                self._ant[0]['y'] = self._ant[0]['y'] + 1
                self.col = self._b._map.get_at((((self._ant[0]['x']* self._b._grille)+(self._b._grille//2)), ((self._ant[0]['y']* self._b._grille)+(self._b._grille//2))))
                self._direction = 'down'
                self.drawAnt(GREEN)
                

if __name__ == '__main__':
    g = Game()
    g.startGame()
