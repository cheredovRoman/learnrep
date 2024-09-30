import pygame

# Инициализация Pygame
pygame.init()

# Размеры окна
screen_width = 800
screen_height = 600

# Создание окна
screen = pygame.display.set_mode((screen_width, screen_height))
pygame.display.set_caption("Кубовый прыжок")

# Цвета
black = (0, 0, 0)
white = (255, 255, 255)

# Позиция и скорость куба
cube_x = 50
cube_y = screen_height - 70
cube_speed_y = 0

# Флаг, указывающий на прыжок
is_jumping = False


def jump():
    global is_jumping, cube_speed_y

    # Проверка, возможен ли прыжок
    if not is_jumping:
        is_jumping = True
        cube_speed_y = -10  # Задаем начальную скорость прыжка


def draw_cube(x, y):
    pygame.draw.rect(screen, black, (x, y, 50, 50))


# Основной цикл программы
running = True
while running:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False

        elif event.type == pygame.KEYDOWN:
            if event.key == pygame.K_SPACE:
                jump()

    # Обработка прыжка
    if is_jumping:
        cube_y += cube_speed_y  # Изменяем позицию куба по вертикали
        cube_speed_y += 1  # Изменяем скорость прыжка

        # Проверка, достиг ли куб земли
        if cube_y >= screen_height - 50:
            cube_y = screen_height - 50
            cube_speed_y = 0
            is_jumping = False

    # Заполнение фона белым цветом
    screen.fill(white)

    # Отрисовка куба
    draw_cube(cube_x, cube_y)

    # Обновление экрана
    pygame.display.flip()

# Завершение работы Pygame
pygame.quit()
