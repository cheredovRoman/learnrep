import numpy as np
import matplotlib.pyplot as plt
from scipy.ndimage import zoom

# Создаем исходную фигуру (квадрат)
size = 10
square = np.ones((size, size))
import numpy as np
from scipy.interpolate import interp2d

def bicubic(image, scale_factor):
    # Определяем размеры исходного изображения
    height, width = image.shape

    # Создаем новые размеры для масштабированного изображения
    new_height = int(height * scale_factor)
    new_width = int(width * scale_factor)

    # Создаем функцию интерполяции бикубического сглаживания
    f = interp2d(np.arange(width), np.arange(height), image, kind='cubic')

    # Вычисляем

# Масштабируем фигуру с помощью сглаживания ближайшего соседа
nearest_neighbor_scaled_square = zoom(square, 2.0, order=0)

# Масштабируем фигуру с помощью бикубического сглаживания
bicubic_scaled_square = bicubic(square, 2.0)

# Отображаем исходную и масштабированную фигуры
plt.subplot(1, 3, 1)
plt.title("Исходная фигура")
plt.imshow(square, cmap="gray")

plt.subplot(1, 3, 2)
plt.title("Сглаживание ближайшего соседа")
plt.imshow(nearest_neighbor_scaled_square, cmap="gray")

plt.subplot(1, 3, 3)
plt.title("Бикубическое сглаживание")
plt.imshow(bicubic_scaled_square, cmap="gray")

plt.show()