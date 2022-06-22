#pragma once
#include "Stack.h"

void HanoiPrint(Stack<int>& st1, Stack<int>& st2, Stack<int>& st3)
{
	std::cout << "-------------------------------------------------" << std::endl;
	st1.Print_line();
	std::cout << std::endl;
	st2.Print_line();
	std::cout << std::endl;
	st3.Print_line();
	std::cout << "-------------------------------------------------" << std::endl;
}

void DiskMove(Stack<int>& from, Stack<int>& to)
{
	int el = from.Top();
	to.Push(el);
	from.Pop();
}

void Hanoi(int size, Stack<int>& st1, Stack<int>& st2, Stack<int>& st3)
{
	if (size == 1)
	{
		HanoiPrint(st1, st2, st3);
		DiskMove(st1, st2);		
	}
	else
	{
		Hanoi(size - 1, st1, st3, st2);
		HanoiPrint(st1, st2, st3);
		DiskMove(st1, st2);
		Hanoi(size - 1, st3, st2, st1);
	}


}

int* create(int size)
{
	int* arr = new int[size];
	for (int i = 0; i < size; i++)
	{
		arr[i] = i;
	}
	return arr;
}

void HanoiTowers(int size)
{
	int* arr = new int[size + 1];
	for (int i = 0; i <= size; i++)
	{
		arr[i] = i;
	}
	int zero_arr[1] = {0};
	std::cout << "Stack data : \n 1. Dynamic Array\n 2. Linked List" << std::endl;
	int k;
	std::cin >> k;
	Stack<int>* A = new Stack<int>(arr, size + 1, k);
	Stack<int>* B = new Stack<int>(zero_arr, 1, k);
	Stack<int>* C = new Stack<int>(zero_arr, 1, k);
	if (size <= 0)
	{
		throw std::out_of_range("IndexOutOfRange");
	}
	Hanoi(size, *A, *B, *C);
	HanoiPrint(*A, *B, *C);
}

