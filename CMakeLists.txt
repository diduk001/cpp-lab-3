project (CPP-LAB-3
        LANGUAGES C CXX) # Используем язык C
cmake_minimum_required(VERSION 2.8.12) # Минимальная допустимая версия CMake
add_executable (lab3_c main.c) # Бинарный файл, скомпилированный из языка C находитя в build/lab3_c
add_compile_options(-Wall -Wextra -Wpedantic) # Опции компиляции для предупреждений
add_compile_options(-O3) # Опции компиляции для оптимизаций
add_compile_options(-mavx2) # Опции компиляции для оптимизаций
add_compile_options(-s) # Удаляем лишнюю информацию из программы
set_property(TARGET lab3_c PROPERTY C_STANDARD 99) # Используем стандарт C99
set(EXECUTABLE_OUTPUT_PATH ..) # Путь скомпилированной программы