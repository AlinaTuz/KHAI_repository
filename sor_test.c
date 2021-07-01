/*
@file sor_test.c
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
#define M 100000

unsigned long long int bubble(int a[], int n)
{
//	int count = 0;
	unsigned long long int compare = 0;
	for (int i = 0; i < n - 1; i++) {
		for (int pass = 0; pass < n - i - 1; pass++) {
			compare++;
			if (a[pass] > a[pass + 1]) {
				SWAP(int, a[pass], a[pass + 1]);
//					count++;
				}
			}
		}
//	return count;
	return compare;
}

unsigned long long int insertion(int a[], int n)
{
//	int count = 0;
	unsigned long long int compare = 0;
	int newElement, location;

	for (int i = 1; i < n; i++)
	{
		newElement = a[i];
		location = i - 1;
		compare++;
		while (location >= 0 && a[location] > newElement)
		{
			a[location + 1] = a[location];
			location = location - 1;
//			count++;
		}
		a[location + 1] = newElement;
	}
//	return count;
	return compare;
}

unsigned long long int selection(int a[], int n)
{
//	int count = 0;
	unsigned long long int compare = 0;
	for (int i = 0; i < n - 1; i++)
	{
		int min = i;
		for (int pass = i + 1; pass < n; pass++)
		{
			compare++;
			if (a[pass] < a[min]){
				min = pass;  
			}
		}
		if (min != i)
			SWAP(int, a[i], a[min]);
//		count++;
	}
//	return count;
	return compare;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	int A[M], B[M];
	clock_t start, stop;
//	int count;
	unsigned long long int compare;

	for (int N = 1000; N <= M; N += 1000) {
		printf("%d\t", N);
		srand((unsigned int)time(NULL));
		for (int i = 0; i < N; i++) {
			A[i] = rand();
			B[i] = A[i];
		}
		
		start = clock();
//		count = bubble(B, N);
		compare = bubble(B, N);
		stop = clock();
		double diff = (double)(stop - start) / CLOCKS_PER_SEC;
//		printf("%6.3f\t%d\t", diff, count);
		printf("%u\t", compare);

		for (int i = 0; i < N; i++) {
			B[i] = A[i];
		}

		start = clock();
//		count = insertion(B, N);
		compare = insertion(B, N);
		stop = clock();
		diff = (double)(stop - start) / CLOCKS_PER_SEC;
//		printf("%6.3f\t%d\t", diff, count);
		printf("%u\t", compare);
		for (int i = 0; i < N; i++) {
			B[i] = A[i];
		}

		start = clock();
//		count = selection(B, N);
		compare = selection(B, N);
		stop = clock();
		diff = (double)(stop - start) / CLOCKS_PER_SEC;
//		printf("%6.3f\t%d\n", diff, count);
		printf("%u\n", compare);
	}
    return 0;
}
