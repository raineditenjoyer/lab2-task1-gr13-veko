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
	
