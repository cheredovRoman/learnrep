import cv2
import numpy as np
import matplotlib.pyplot as plt
from tkinter import Tk, Scale, Label, HORIZONTAL

# Загрузка изображения
image = cv2.imread('image/myimage.jpg')

# Создание функции для обновления яркости
def update_brightness(value):
    # Преобразование изображения в оттенки серого
    gray_image = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)

    # Применение преобразования яркости
    bright_image = cv2.convertScaleAbs(gray_image, alpha=value/100, beta=0)

    # Вычисление гистограммы яркости
    hist = cv2.calcHist([bright_image], [0], None, [256], [0, 256])

    # Вывод изображения
    cv2.imshow('Image', bright_image)

    # Отображение гистограммы
    plt.plot(hist)
    plt.title('Brightness Histogram')
    plt.xlabel('Pixel Value')
    plt.ylabel('Frequency')
    plt.show()

# Создание графического интерфейса пользователя
root = Tk()
root.title('Brightness Adjustment')

# Создание ползунка для выбора яркости
brightness_scale = Scale(root, from_=0, to=200, orient=HORIZONTAL, command=update_brightness)
brightness_scale.set(100)
brightness_scale.pack()

# Создание метки для отображения текущей яркости
current_brightness_label = Label(root, text=f'Current Brightness: {brightness_scale.get()}')
current_brightness_label.pack()

# Обновление метки текущей яркости при изменении положения ползунка
def update_label(value):
    current_brightness_label.config(text=f'Current Brightness: {value}')

brightness_scale.config(command=update_brightness)
brightness_scale.config(command=update_label)

# Отображение графического интерфейса пользователя
root.mainloop()

# Ожидание нажатия клавиши для закрытия окна OpenCV
cv2.waitKey(0)
cv2.destroyAllWindows()
def update_brightness(value):
    # Преобразование изображения в оттенки серого
    gray_image = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)

    # Применение преобразования яркости
    bright_image = cv2.convertScaleAbs(gray_image, alpha=value/100, beta=0)

    # Вычисление гистограммы яркости
    hist = cv2.calcHist([bright_image], [0], None, [256], [0, 256])

    # Вывод изображения
    cv2.imshow('image/myimage.jpg', bright_image)

    # Отображение гистограммы
    plt.clf()  # Очистка предыдущего графика
    plt.plot(hist)
    plt.title('Brightness Histogram')
    plt.xlabel('Pixel Value')
    plt.ylabel('Frequency')
    plt.draw()  # Обновление графика
    def update_label(value):
        current_brightness_label.config(text=f'Current Brightness: {value}')

brightness_scale.config(command=update_label)