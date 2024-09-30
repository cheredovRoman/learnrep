import math
import pygame as pg
from object_3d import *
from projection import *
from camera import *


class SoftwareRender:
    def __init__(self): #инициализация окна
        pg.init()
        self.RES = self.WIDTH, self.HEIGHT = 1280, 720
        self.H_WIDTH, self.H_HEIGHT = self.WIDTH // 2, self.HEIGHT // 2
        self.FPS = 60
        self.screen = pg.display.set_mode(self.RES)
        self.clock = pg.time.Clock()
        self.create_objects()

    def create_objects(self):
        self.camera = Camera(self,[0.5,1,-4])
        self.projection = Projection(self)
        self.object = Object3D(self)
        self.object.translate([0.2, 0.4, 0.2])
        self.object.rotate_y(math.pi / 6)

    def draw(self): #заливка экрана
        self.screen.fill(pg.Color('darkcyan'))
        self.object.draw()
    def run(self): #запуск экрана
        while True:
            self.draw()
            self.camera.control()
            [exit() for i in pg.event.get() if i.type == pg.QUIT]
            pg.display.set_caption(str(self.clock.get_fps()))
            pg.display.flip()
            self.clock.tick(self.FPS)
if __name__ == '__main__':
    app = SoftwareRender()
    app.run()