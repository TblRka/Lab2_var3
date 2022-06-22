#pragma once
#include "Sequence.h"

template <class T> class Stack
{
private:
	Sequence<T>* seq = nullptr;
	int type = 0;
public: 
	void Choose();

	Stack();
	Stack(int ch);
	Stack(T* items, int size);
	Stack(T* items, int size, int type);
	Stack(const Stack<T>& another);
	~Stack();

	T Top();
	int Size();
	bool Empty();

	void Pop();
	void Push(T item);

	T Reduce(T(*f)(T, T), T value);
	Stack<T>* Where(bool (*f) (T));
	Stack<T>* Map(T(*f)(T));
	Stack<T>* Concat(Stack<T>* stack);
	Stack<T>* GetSubstack(int start_index, int end_index);

	void Print();
	void Print_line();
	void Print(int index);

};

template <class T> void Stack<T>::Choose() {
	std::cout << "Stack data :\n 1. Dynamic Array\n 2. Linked List" << std::endl;
	std::cout << "Enter: " ;
	std::cin >> type;
}

template <class T> Stack<T>::Stack() 
{
	Choose();
	switch (type)
	{
	case 1:
		seq = new ArraySequence<T>;
		break;
	case 2:
		seq = new ListSequence<T>;
		break;
	default:
		break;
	}
}
template <class T> Stack<T>::Stack(int type) : type(type)
{
	switch (type)
	{
	case 1:
		seq = new ArraySequence<T>;
		break;
	case 2:
		seq = new ListSequence<T>;
		break;
	default:
		break;
	}
}
template <class T> Stack<T>::Stack(T* items, int size)
{
	Choose();
	switch (type)
	{
	case 1:
		seq = new ArraySequence<T>(items, size);
		break;
	case 2:
		seq = new ListSequence<T>(items, size);
		break;
	default:
		break;
	}
}
template <class T> Stack<T>::Stack(T* items, int size, int type)
{
	switch (type)
	{
	case 1:
		seq = new ArraySequence<T>(items, size);
		break;
	case 2:
		seq = new ListSequence<T>(items, size);
		break;
	default:
		break;
	}
}
template <class T> Stack<T>::Stack(const Stack<T>& another)
{
	type = another.type;
	switch (type)
	{
	case 1:
		seq = new ArraySequence<T>(another.seq);
		break;
	case 2:
		seq = new ListSequence<T>(another.seq);
		break;
	default:
		break;
	}
}
template <class T> Stack<T>::~Stack()
{
	delete seq;
}

template <class T> int Stack<T>::Size()
{
	return seq->GetLength();
}
template <class T> void Stack<T>::Pop()
{
	seq->DeleteLast();
}
template <class T> T Stack<T>::Top()
{
	T el = seq->GetLast();
	return el;
}
template <class T> void Stack<T>::Push(T item)
{
	seq->Append(item);
}
template <class T> bool Stack<T>::Empty()
{
	return (seq->GetLength() == 0);
}
template <class T> Stack<T>* Stack<T>::Concat(Stack<T>* stack)
{
	Stack<T>* result = new Stack<T>(type);
	result->seq = seq->Concat(stack->seq);
	return result;
}
template <class T> Stack<T>* Stack<T>::GetSubstack(int startIndex, int endIndex)
{
	Stack<T>* SubStack = new Stack<T>(type);
	SubStack->seq = seq->GetSubsequence(startIndex, endIndex);
	return SubStack;
}

template <class T> Stack<T>* Stack<T>::Map(T(*f)(T))
{
	Stack<T>* mid = new Stack<T>(type);
	for (int i = seq->GetLength() - 1; i >= 0; i--)
	{
		mid->Push(f(seq->Get(i)));
	}

	Stack<T>* res = new Stack<T>(type);
	for (int i = seq->GetLength() - 1; i >= 0; i--)
	{
		res->Push(f(mid->seq->Get(i)));
	}

	return res;
}

template <class T> Stack<T>* Stack<T>::Where(bool(*f)(T))
{
	Stack<T>* mid = new Stack<T>(type);
	for (int i = Size() - 1; i >= 0; i--)
	{
		if (f(seq->Get(i)))
		{
			mid->Push(seq->Get(i));
		}
	}

	Stack<T>* res = new Stack<T>(type);
	for (int i = mid->Size() - 1; i >= 0; i--)
	{
		res->Push(f(mid->seq->Get(i)));
	}

	return res;
}

template <class T> T Stack<T>::Reduce(T(*f)(T, T), T c)
{
	T res = f(seq->GetLast(), c);
	for (int i = seq->GetLength() - 2; i >= 0; i--)
	{
		res = f(seq->Get(i), res);
	}
	return res;
}

template <class T> void Stack<T>::Print()
{
	seq->Print();
}
template <class T> void Stack<T>::Print_line()
{
	seq->Print_line();
}
template <class T> void Stack<T>::Print(int index)
{
	seq->Print(index);
}
