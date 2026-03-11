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
