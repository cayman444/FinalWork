#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// Функция для ввода исходных массивов и записи их в файл
void inputArray(int *arr, int length, FILE *file) {
    srand(time(NULL));
    for (int i1 = 0; i1 < length; i1++) {
        arr[i1] = rand() % 100;
        fprintf(file, "%d ", arr[i1]); // Запись в файл
    }
    fprintf(file, "\n");
}

// Функция для вывода исходных массивов
void printArray(int *arr, int length) {
    for (int i1 = 0; i1 < length; i1++) {
        printf("M[%d] = %d\n", i1, arr[i1]);
    }
}

// Функция для вычисления среднего геометрического
double geometricMean(int *arr, int length) {
    double numProduct = 1.0;
    for (int i1 = 0; i1 < length; i1++) {
        numProduct *= arr[i1];
    }
    return pow(numProduct, 1.0 / length);
}

// Функция для ввода исходных массивов 2D и записи их в файл
void inputArray2(int *arr, int rows, int cols, FILE *file) {
    srand(time(NULL));
    for (int i1 = 0; i1 < rows; i1++) {
        for (int j1 = 0; j1 < cols; j1++) {
            *(arr + i1 * cols + j1) = (rand() % 100 + 1) * (rand() % 2 == 0 ? 1 : -1);
            fprintf(file, "%4d ", *(arr + i1 * cols + j1)); // Запись в файл
        }
        fprintf(file, "\n");
    }
}

// Функция для вывода исходных массивов 2D
void printArray2(int *arr, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%4d", *(arr + i * cols + j));
        }
        printf("\n");
    }
}

// Функция для подсчета изменений знака в массиве
int countSignChanges(int *arr, int rows, int cols) {
    int signChanges = 0;
    int lastEl = *arr;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int currentEl = *(arr + i * cols + j);
            if (currentEl > 0 && lastEl < 0) {
                signChanges++;
            } else if (currentEl < 0 && lastEl > 0) {
                signChanges++;
            }
            lastEl = currentEl;
        }
    }

    return signChanges;
}

int main(void) {
    // Открытие файла для записи исходных данных и результатов
    FILE *file = fopen("output.txt", "w");
    if (file == NULL) {
        printf("Ошибка открытия файла!\n");
        return 1;
    }

    // a) 1 вариант
    int M[10];
    int length = sizeof(M) / sizeof(M[0]);

    // а) Ввод исходных массивов и запись в файл
    fprintf(file, "Исходный массив 1:\n");
    inputArray(M, length, file);

    // б) Вывод исходных массивов
    printf("Исходный массив 1:\n");
    printArray(M, length);

    // в) Обработка массивов в соответствии с заданием
    double average = geometricMean(M, length);

    // г) Вывод результатов с соответствующими комментариями и запись в файл
    printf("Среднее геометрическое: %.6f\n", average);
    fprintf(file, "Среднее геометрическое: %.6f\n", average);

    // б) 2 вариант
    const int rows = 3;
    const int cols = 3;

    int M2[rows][cols];

    // а) Ввод исходных массивов и запись в файл
    fprintf(file, "Исходный массив 2:\n");
    inputArray2(&M2[0][0], rows, cols, file);

    // б) Вывод исходных массивов
    printf("Исходный массив 2:\n");
    printArray2(&M2[0][0], rows, cols);

    // в) Обработка массивов в соответствии с заданием
    int signChanges = countSignChanges(&M2[0][0], rows, cols);

    // г) Вывод результатов с соответствующими комментариями и запись в файл
    printf("Изменений знака в массиве: %d\n", signChanges);
    fprintf(file, "Изменений знака в массиве: %d\n", signChanges);

    // Закрытие файла
    fclose(file);

    // Вывод содержимого файла на экран
    printf("\nСодержимое файла output.txt:\n");
    FILE *readFile = fopen("output.txt", "r");
    if (readFile == NULL) {
        printf("Ошибка открытия файла для чтения!\n");
        return 1;
    }

    char ch;
    while ((ch = fgetc(readFile)) != EOF) {
        putchar(ch);
    }

    fclose(readFile);

    return 0;
}