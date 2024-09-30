import numpy as np
from PIL import Image


def nearest_neighbor(image, scale_factor):
    # Определяем новый размер изображения
    new_width = int(image.width * scale_factor)
    new_height = int(image.height * scale_factor)

    # Создаем новое изображение с новыми размерами
    new_image = Image.new("RGB", (new_width, new_height))

    # Выполняем масштабирование
    for x in range(new_width):
        for y in range(new_height):
            # Определяем координаты пикселей в исходном изображении
            src_x = int(x / scale_factor)
            src_y = int(y / scale_factor)

            # Получаем цвет пикселя из исходного изображения
            pixel_color = image.getpixel((src_x, src_y))

            # Устанавливаем цвет пикселя в новом изображении
            new_image.putpixel((x, y), pixel_color)

    return new_image


def bicubic(image, scale_factor):
    # Определяем новый размер изображения
    new_width = int(image.width * scale_factor)
    new_height = int(image.height * scale_factor)

    # Создаем новое изображение с новыми размерами
    new_image = Image.new("RGB", (new_width, new_height))

    # Преобразуем изображение в массив numpy
    image_array = np.array(image)

    # Выполняем масштабирование
    for x in range(new_width):
        for y in range(new_height):
            # Определяем координаты пикселей в исходном изображении
            src_x = int(x / scale_factor)
            src_y = int(y / scale_factor)

            # Вычисляем значения коэффициентов для бикубического сглаживания
            x_floor = src_x - 1
            y_floor = src_y - 1
            x_frac = x / scale_factor - src_x
            y_frac = y / scale_factor - src_y

            # Вычисляем значения коэффициентов для бикубического сглаживания
            coeffs = [
                bicubic_coeff(x_frac + 1),
                bicubic_coeff(x_frac),
                bicubic_coeff(1 - x_frac),
                bicubic_coeff(2 - x_frac)
            ]

            # Вычисляем цвет пикселя в новом изображении
            new_color = [0, 0, 0]
            for i in range(4):
                for j in range(4):
                    # Определяем координаты пикселей в исходном изображении
                    src_x = max(0, min(image.width - 1, x_floor + i))
                    src_y = max(0, min(image.height - 1, y_floor + j))

                    # Получаем цвет пикселя из исходного изображения
                    pixel_color = image_array[src_y, src_x]

                    # Вычисляем вес пикселя на основе коэффициентов
                    weight = coeffs[i] * coeffs[j]

                    # Добавляем взвешенный цвет пикселя к новому цвету
                    new_color += (weight * pixel_color).astype(int)

            # Устанавливаем цвет пикселя в новом изображении
            new_image.putpixel((x, y), tuple(new_color))

    return new_image

def bicubic_coeff(t):
    a = -0.5
    if abs(t) < 1:
        return (a + 2) * abs(t) ** 3 - (a + 3) * abs(t)
    elif abs(t) < 2:
        return a * abs(t) ** 3 - 5 * a * abs(t) ** 2 + 8 * a * abs(t) - 4 * a
    else:
        return 0

# Открываем изображение
image_path = "photo/photo.jpg"
image = Image.open(image_path)

# Выполняем сглаживание с помощью ближайшего соседа
nearest_image = nearest_neighbor(image, 1.5)

# Выполняем сглаживание с помощью бикубического сглаживания
bicubic_image = bicubic(image, 1.5)

# Сохраняем результаты
nearest_image.save("photo/photo_nearest_fixed.jpg")
bicubic_image.save("photo/photo_bicubic_fixed.jpg")

# Проверяем результаты
nearest_image.show()
bicubic_image.show()