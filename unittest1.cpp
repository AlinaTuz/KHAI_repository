/*
@file unittest1.cpp
@author Туз А.В., гр. 515в
@data 07.07.2021
@brief Навчальна практика

Порівняння алгоритмов сортування
*/

#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Sor/sor.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestSor
{		
	TEST_CLASS(UnitTestSor)
	{
	public:
		TEST_METHOD(TestMethodError)
		{
			int a[10] = { 3, 4, 8, 9, 5, 6, 10, 2, 1, 7 };
			for (int i = 0; i < 10; i++) {
				Assert::AreEqual((i + 1), a[i]);
			}
		}
		TEST_METHOD(TestMethodBubble)
		{
			int a[10] = { 3, 4, 8, 9, 5, 6, 10, 2, 1, 7 };
			bubble(a, 10);
			for (int i = 0; i < 10; i++) {
				Assert::AreEqual((i + 1), a[i]);
			}
		}
		TEST_METHOD(TestMethodInsertion)
		{
			int a[10] = { 3, 4, 8, 9, 5, 6, 10, 2, 1, 7 };
			insertion(a, 10);
			for (int i = 0; i < 10; i++) {
				Assert::AreEqual((i + 1), a[i]);
			}
		}
		TEST_METHOD(TestMethodSelection)
		{
			int a[10] = { 3, 4, 8, 9, 5, 6, 10, 2, 1, 7 };
			selection(a, 10);
			for (int i = 0; i < 10; i++) {
				Assert::AreEqual((i + 1), a[i]);
			}
		}
	};
}
