#include "Header.h" 
#include "HanoiTowers.h"

int main()
{
	/*
	double* arr = new double[5];
	for (int i = 0; i < 5; i++)
	{
		arr[i] = 1.1;
		//std::cout << arr[i] << std::endl;
	}

	DynamicArray<double>* Arr = new DynamicArray<double>(arr, 5);
	std::cout << "DynamicArray :" << std::endl;
	Arr->Print_line();
	Arr->Print();
	Arr->Set(2, 2.0);
	Arr->DeleteLast();
	Arr->Print_line();
	double arr1[2] = { 6.0, 7.0 };
	DynamicArray<double>* pArr = new DynamicArray<double>(arr1, 2);
	DynamicArray<double>* cArr = Arr->Concat(pArr);
	cArr->Print_line();

	Sequence<double>* As = new ArraySequence<double>(*Arr);
	std::cout << "ArraySequence 1 :" << std::endl;
	As->Print_line();
	As->Prepend(14.88);
	As->Print_line();
	*/
	/*
	Student arr[4] = { Student("Alexey", "Viktorovich", "Ryzhov", 514, 21, 4.4), Student("Alexey", "Viktorovich", "Ryzhov", 514, 21, 4.5), Student("Alexey", "Viktorovich", "Ryzhov", 514, 21, 4.5), Student("Alexey", "Viktorovich", "Ryzhov", 514, 21, 4.5) };
	LinkedList<Student>* list = new LinkedList<Student>(arr, 4);
	std::cout << "LinkedList :" << std::endl;
	list->Print_line();
	list->DeleteLast();
	list->Print_line();
	LinkedList<Student>* slist = list->GetSubList(1, 2);
	slist->Print_line();*/
	/*
	LinkedList<int>* list = new LinkedList<int>(arr, 5);
	std::cout << "LinkedList :" << std::endl;
	int arr1_1[3] = { 6, 7, 8 };
	list->Print_line();
	LinkedList<int>* list1 = new LinkedList<int>(arr1_1, 3);
	LinkedList<int>* clist = list->Concat(list1);
	clist->Print_line();


	Sequence<int>* Ls = new ListSequence<int>(*list);
	std::cout << "ListSequence :" << std::endl;
	Ls->Print_line();
	Ls->DeleteLast();
	Ls->Print_line();

	DynamicArray<double>* Arr = new DynamicArray<double>(arr, 5);
	std::cout << "DynamicArray :" << std::endl;
	Arr->Print_line();
	Arr->Print();
	Arr->DeleteLast();
	Arr->Print_line();
	double arr1[2] = {6.0, 7.0};
	DynamicArray<double>* pArr = new DynamicArray<double>(arr1, 2);
	DynamicArray<double>* cArr = Arr->Concat(pArr);
	cArr->Print_line();
	//DynamicArray<int>* sArr = Arr->GetSublist(2, 3);
	//sArr->Print_line();

	Sequence<double>* As = new ArraySequence<double>(*Arr);
	std::cout << "ArraySequence 1 :" << std::endl;
	As->Print_line();

	Sequence<double>* copy = new ArraySequence<double>(As);
	std::cout << "ArraySequence 2 :" << std::endl;
	copy->Print_line();

	Stack<double>* St = new Stack<double>(arr, 5);
	std::cout << "Stack :" << std::endl;
	St->Print_line();
	St->Pop();
	St->Print_line();
	St->Push(1);
	St->Print_line();
	std::cout << St->Size() << std::endl;
	Stack<double>* SSt = St->GetSubstack(1, 3);
	SSt->Print_line();
	*/

	int i;
	std::cout << "Entre nomber of rings :";
	std::cin >> i;
	std::cout << "\n";
	HanoiTowers(i);
	


	return 0;
}