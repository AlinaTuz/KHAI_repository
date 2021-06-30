/*
@file Sor.cpp
@author Туз А.В., гр. 515в
@data 26.06.2021
@brief Навчальна практика

Порівняння алгоритмов сортування
*/

#include "stdafx.h"
#include <locale.h>
#include <stdlib.h> 
#include <time.h>
#define SWAP(h,a,b) {h hold; hold = a; a = b; b = hold;}
#define N 10

void bubble(int a[], int n)
{
	for (int i = 0; i < n - 1; i++) {
		for (int pass = 0; pass < n - i - 1; pass++) {
				if (a[pass] > a[pass + 1])
					SWAP(int, a[pass], a[pass + 1]);
		}
	}
}

void insertion(int a[], int n)
{
	int newElement, location;

	for (int i = 1; i < n; i++)
	{
		newElement = a[i];
		location = i - 1;
		while (location >= 0 && a[location] > newElement)
		{
			a[location + 1] = a[location];
			location--;
		}
		a[location + 1] = newElement;
	}
}

void selection(int a[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int min = i;
		for (int pass = i + 1; pass < n; pass++)
		{
			if (a[pass] < a[min])
				min = pass;
		}
		if (min != i)
			SWAP(int, a[i], a[min]);
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	int A[N], B[N];
	srand((unsigned int)time(NULL));
	for (int i = 0; i < N; i++) {
		A[i] = rand();
		B[i] = A[i];
	}
	for (int i = 0; i < N; i++)
		printf("%d ", A[i]);
	printf("\n\n");

	printf("Данные расположены в порядке возрастания\n");
	printf("Пузырьковая сортировка\n");

	bubble(B, N);
	for (int i = 0; i < N; i++)
		printf("%d ", B[i]);
	printf("\n\n");

	for (int i = 0; i < N; i++) {
		B[i] = A[i];
	}
	printf("Сортировка вставками\n");		
	insertion(B, N);
	for (int i = 0; i < N; i++)
		printf("%d ", B[i]);
	printf("\n\n");

	for (int i = 0; i < N; i++) {
		B[i] = A[i];
	}
	printf("Сортировка выбором\n");
	selection(B, N);
	for (int i = 0; i < N; i++)
		printf("%d ", B[i]);
	printf("\n");

	return 0;
}
