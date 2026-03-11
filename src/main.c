#include <stdio.h>
#include <stdlib.h>

// Функция 1: вычисление суммы цифр числа
int sumOfDigits(int num) {
		int sum = 0;
		num = abs(num);

		while (num > 0) {
				sum += num % 10;
				num /= 10;
		}

		return sum;
}

void findNumbersWithMaxDigitSum(int arr[], int n) {
		if (n <= 0) {
				printf("Массив пуст или имеет некорректный размер\n");
				return;
		}

		int maxSum = 0;
		for (int i = 0; i < n; i++) {
				int currentSum = sumOfDigits(arr[i]);
				if (currentSum > maxSum) {
						maxSum = currentSum;
				}
		}
	
		printf("Числа с максимальной суммой цифр (%d):\n", maxSum);
		int count = 0;
		for (int i = 0; i < n; i++) {
				if (sumOfDigits(arr[i]) == maxSum) {
						printf("%d ", arr[i]);
						count++;
				}
		}

		if (count == 0) {
				printf("Не найдено чисел с суммой цифр %d", maxSum);
		}
		printf("\n");
}

void demonstrateProgram() {
		int arr[] = {123, 45, 678, 91, 234, 567, 89, 111};
		int n = sizeof(arr) / sizeof(arr[0]);

		printf("Исходный массив:\n");
		for (int i = 0; i < n; i++) {
				printf("%d ", arr[i]);
		}
		printf("\n\n");

		printf("Суммы цифр для каждого числа:\n");
		for (int i = 0; i < n; i++) {
				printf("%d -> %d\n", arr[i], sumOfDigits(arr[i]));
		}
		printf("\n");

		findNumbersWithMaxDigitSum(arr, n);
}

void inputArray(int **arr, int *n) {
		printf("Введите размер массива: ");
		scanf("%d", n);

		if (*n <= 0) {
				printf("Некорректный размер массива\n");
				*arr = NULL;
				return;
		}

		*arr = (int*)malloc(*n * sizeof(int));
		if (*arr == NULL) {
				printf("Ошибка выделения памяти\n");
				*n = 0;
				return;
		}

		printf("Введите %d натуральных чисел:\n", *n);
		for (int i = 0; i < *n; i++) {
				printf("arr[%d] = ", i);
				scanf("%d", &(*arr)[i]);
				while ((*arr)[i] <= 0) {
						printf("Ошибка! Введите положительное число: ");
						scanf("%d", &(*arr)[i]);
				}
		}
}

int main() {
		int choice;
		int *arr = NULL;
		int n = 0;

		printf("Программа для поиска чисел с максимальной суммой цифр\n");
		printf("====================================================\n\n");

		printf("Выберите режим работы:\n");
		printf("1. Демонстрация на тестовом массиве\n");
		printf("2. Ввод данных с клавиатуры\n");
		printf("Ваш выбор: ");
		scanf("%d", &choice);

		if (choice == 1) {
				demonstrateProgram();
		} else if (choice == 2) {
				inputArray(&arr, &n);

				if (arr != NULL && n > 0) {
						printf("\nВведенный массив:\n");
						for (int i = 0; i < n; i++) {
								printf("%d ", arr[i]);
						}
						printf("\n\n");

						findNumbersWithMaxDigitSum(arr, n);
						free(arr);
				}
		} else {
				printf("Неверный выбор\n");
		}

		return 0;
}
	
