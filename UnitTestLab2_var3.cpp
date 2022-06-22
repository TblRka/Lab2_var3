#include "pch.h"
#include "CppUnitTest.h"
#include "..\Lab2_1\Stack.h"
#include "..\Lab2_1\Student.h"
#include "..\Lab2_1\Teacher.h"
#include "..\Lab2_1\Complex.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestLab2var3
{
	TEST_CLASS(UnitTestLab2var3)
	{
	public:

		TEST_METHOD(DynamicArràyTest)
		{
			int test_arr_i[5] = { 1, 2, 3, 4, 5 };
			double test_arr_d[3] = {1.1, 2.2, 3.3};
			Teacher test_arr_t[2] = { Teacher("Vitaly", "Leonidovich", "Kaminin", "math", 40), Teacher("Dmitriy", "Sergeevich", "Telyakovskii", "math", 35) };
			Student test_arr_s[2] = { Student("Alexey", "Viktorovich", "Ryzhov", 514, 21, 4.4), Student("Alexey", "P", "Varlamov", 514, 8, 3.8) };
			Complex test_arr_c[3] = { Complex(1.1, 2.2), Complex(2.1, 1.4), Complex(3.1, 5.2) };
			int test_arr2[4] = { 1, 2, 3, 4 };
			int test_arr3[5] = { 1, 2, 3, 4, 1 };
			int test_arr4[2] = { 6, 8 };
			int test_concat[7] = { 1, 2, 3, 4, 1, 6, 8 };
			int test_sublist[3] = { 2, 3, 4 };

			DynamicArray<int> d_arr_i(test_arr_i, 5);
			DynamicArray<double> d_arr_d(test_arr_d, 3);
			DynamicArray<Teacher> d_arr_t(test_arr_t, 2);
			DynamicArray<Student> d_arr_s(test_arr_s, 2);
			DynamicArray<Complex> d_arr_c(test_arr_c, 3);

			DynamicArray<int> d_arr_2(test_arr2, 4);
			DynamicArray<int> d_arr_3(test_arr3, 5);
			DynamicArray<int> d_arr_4(test_arr4, 2);
			DynamicArray<int> d_arr_concat(test_concat, 7);
			DynamicArray<int> d_arr_sublist(test_sublist, 3);

			Assert::IsTrue(d_arr_t.GetSize() == 2, L"GetSize method");
			Assert::IsTrue(d_arr_s.GetSize() == 2, L"GetSize method");
			Assert::IsTrue(d_arr_c.GetSize() == 3, L"GetSize method");
			Assert::IsTrue(d_arr_d.GetSize() == 3, L"GetSize method");
			Assert::IsTrue(d_arr_i.GetSize() == 5, L"GetSize method");

			Assert::IsTrue(d_arr_i.Get(1) == 2, L"Getter method");
			d_arr_i.DeleteLast();
			Assert::IsTrue(d_arr_i == d_arr_2, L"Delete method");
			d_arr_i.Set(4, 1);
			Assert::IsTrue(d_arr_i == d_arr_3, L"Setter method");
			Assert::IsTrue(*(d_arr_i.Concat(&d_arr_4)) == d_arr_concat, L"Concat method");
			Assert::IsTrue(*(d_arr_i.GetSublist(1, 3)) == d_arr_sublist, L"GetSublist method");
			d_arr_i.Resize(20);
			Assert::IsTrue(d_arr_i.GetSize() == 20, L"Resize method");
		}
		TEST_METHOD(LinkedListTest)
		{
			int test_arr_i[5] = { 1, 2, 3, 4, 5 };
			double test_arr_d[3] = { 1.1, 2.2, 3.3 };
			Teacher test_arr_t[2] = { Teacher("Vitaly", "Leonidovich", "Kaminin", "math", 40), Teacher("Dmitriy", "Sergeevich", "Telyakovskii", "math", 35) };
			Student test_arr_s[2] = { Student("Alexey", "Viktorovich", "Ryzhov", 514, 21, 4.4), Student("Alexey", "P", "Varlamov", 514, 8, 3.8) };
			Complex test_arr_c[3] = { Complex(1.1, 2.2), Complex(2.1, 1.4), Complex(3.1, 5.2) };
			int test_arr2[4] = { 1, 2, 3, 4 };
			int test_arr3[5] = { 1, 2, 3, 4, 1 };
			int test_arr4[2] = { 6, 8 };
			int test_arr5[3] = { 1, 6, 8 };
			int test_arr6[4] = { 1, 6, 9, 8};
			int test_concat[9] = { 1, 2, 3, 4, 1, 1, 6, 9, 8 };
			int test_sublist[3] = { 2, 3, 4 };

			LinkedList<int> linkedlist_i(test_arr_i, 5);
			LinkedList<double> linkedlist_d(test_arr_d, 3);
			LinkedList<Teacher> linkedlist_t(test_arr_t, 2);
			LinkedList<Student> linkedlist_s(test_arr_s, 2);
			LinkedList<Complex> linkedlist_c(test_arr_c, 3);

			LinkedList<int> linkedlist_2(test_arr2, 4);
			LinkedList<int> linkedlist_3(test_arr3, 5);
			LinkedList<int> linkedlist_4(test_arr4, 2);
			LinkedList<int> linkedlist_5(test_arr5, 3);
			LinkedList<int> linkedlist_6(test_arr6, 4);
			LinkedList<int> linkedlist_concat(test_concat, 9);
			LinkedList<int> linkedlist_sublist(test_sublist, 3);

			Assert::IsTrue(linkedlist_t.GetLength() == 2, L"GetSize method");
			Assert::IsTrue(linkedlist_s.GetLength() == 2, L"GetSize method");
			Assert::IsTrue(linkedlist_c.GetLength() == 3, L"GetSize method");
			Assert::IsTrue(linkedlist_d.GetLength() == 3, L"GetSize method");
			Assert::IsTrue(linkedlist_i.GetLength() == 5, L"GetSize method");

			Assert::IsTrue(linkedlist_i.GetFirst() == 1, L"Getter method");
			Assert::IsTrue(linkedlist_i.GetLast() == 5, L"Getter method");
			Assert::IsTrue(linkedlist_i.GetIndex(1) == 2, L"Getter method");
			linkedlist_i.DeleteLast();
			Assert::IsTrue(linkedlist_i == linkedlist_2, L"Delete method");
			linkedlist_i.Append(1);
			Assert::IsTrue(linkedlist_i == linkedlist_3, L"Setter method");
			linkedlist_4.Prepend(1);
			Assert::IsTrue(linkedlist_4 == linkedlist_5, L"Prepend method");
			linkedlist_4.InsertAt(2, 9);
			Assert::IsTrue(linkedlist_4 == linkedlist_6, L"InsertAt method");
			Assert::IsTrue(*(linkedlist_i.Concat(&linkedlist_4)) == linkedlist_concat, L"Concat method");
			Assert::IsTrue(*(linkedlist_i.GetSubList(1, 3)) == linkedlist_sublist, L"GetSublist method");
		}
		
		TEST_METHOD(ArraySequenceTest)
		{
			int test_arr_i[5] = { 1, 2, 3, 4, 5 };
			double test_arr_d[3] = { 1.1, 2.2, 3.3 };
			Teacher test_arr_t[2] = { Teacher("Vitaly", "Leonidovich", "Kaminin", "math", 40), Teacher("Dmitriy", "Sergeevich", "Telyakovskii", "math", 35) };
			Student test_arr_s[2] = { Student("Alexey", "Viktorovich", "Ryzhov", 514, 21, 4.4), Student("Alexey", "P", "Varlamov", 514, 8, 3.8) };
			Complex test_arr_c[3] = { Complex(1.1, 2.2), Complex(2.1, 1.4), Complex(3.1, 5.2) };
			int test_arr2[4] = { 1, 2, 3, 4 };
			int test_arr3[5] = { 1, 2, 3, 4, 1 };
			int test_arr4[2] = { 6, 8 };
			int test_arr5[3] = { 1, 6, 8 };
			int test_arr6[4] = { 1, 6, 9, 8 };
			int test_concat[9] = { 1, 2, 3, 4, 1, 1, 6, 9, 8 };
			int test_sublist[3] = { 2, 3, 4 };

			ArraySequence<int> array_s_i(test_arr_i, 5);
			ArraySequence<double> array_s_d(test_arr_d, 3);
			ArraySequence<Teacher> array_s_t(test_arr_t, 2);
			ArraySequence<Student> array_s_s(test_arr_s, 2);
			ArraySequence<Complex> array_s_c(test_arr_c, 3);

			ArraySequence<int> array_s_2(test_arr2, 4);
			ArraySequence<int> array_s_3(test_arr3, 5);
			ArraySequence<int> array_s_4(test_arr4, 2);
			ArraySequence<int> array_s_5(test_arr5, 3);
			ArraySequence<int> array_s_6(test_arr6, 4);
			ArraySequence<int> array_s_concat(test_concat, 9);
			ArraySequence<int> array_s_sublist(test_sublist, 3);

			Assert::IsTrue(array_s_t.GetLength() == 2, L"GetSize method");
			Assert::IsTrue(array_s_s.GetLength() == 2, L"GetSize method");
			Assert::IsTrue(array_s_c.GetLength() == 3, L"GetSize method");
			Assert::IsTrue(array_s_d.GetLength() == 3, L"GetSize method");
			Assert::IsTrue(array_s_i.GetLength() == 5, L"GetSize method");


			Assert::IsTrue(array_s_i.GetFirst() == 1, L"Getter method");
			Assert::IsTrue(array_s_i.GetLast() == 5, L"Getter method");
			Assert::IsTrue(array_s_i.Get(1) == 2, L"Getter method");
			array_s_i.DeleteLast();
			Assert::IsTrue(array_s_i == array_s_2, L"Delete method");
			array_s_i.Append(1);
			Assert::IsTrue(array_s_i == array_s_3, L"Setter method");
			array_s_4.Prepend(1);
			Assert::IsTrue(array_s_4 == array_s_5, L"Prepend method");
			array_s_4.InsertAt(2, 9);
			Assert::IsTrue(array_s_4 == array_s_6, L"InsertAt method");
			Assert::IsTrue(*(array_s_i.Concat(&array_s_4)) == array_s_concat, L"Concat method");
			Assert::IsTrue(*(array_s_i.GetSubsequence(1, 3)) == array_s_sublist, L"GetSublist method");
		}

		TEST_METHOD(ListSequenceTest)
		{
			int test_arr_i[5] = { 1, 2, 3, 4, 5 };
			double test_arr_d[3] = { 1.1, 2.2, 3.3 };
			Teacher test_arr_t[2] = { Teacher("Vitaly", "Leonidovich", "Kaminin", "math", 40), Teacher("Dmitriy", "Sergeevich", "Telyakovskii", "math", 35) };
			Student test_arr_s[2] = { Student("Alexey", "Viktorovich", "Ryzhov", 514, 21, 4.4), Student("Alexey", "P", "Varlamov", 514, 8, 3.8) };
			Complex test_arr_c[3] = { Complex(1.1, 2.2), Complex(2.1, 1.4), Complex(3.1, 5.2) };
			int test_arr2[4] = { 1, 2, 3, 4 };
			int test_arr3[5] = { 1, 2, 3, 4, 1 };
			int test_arr4[2] = { 6, 8 };
			int test_arr5[3] = { 1, 6, 8 };
			int test_arr6[4] = { 1, 6, 9, 8 };
			int test_concat[9] = { 1, 2, 3, 4, 1, 1, 6, 9, 8 };
			int test_sublist[3] = { 2, 3, 4 };

			ListSequence<int> list_s_i(test_arr_i, 5);
			ListSequence<double> list_s_d(test_arr_d, 3);
			ListSequence<Teacher> list_s_t(test_arr_t, 2);
			ListSequence<Student> list_s_s(test_arr_s, 2);
			ListSequence<Complex> list_s_c(test_arr_c, 3);

			ListSequence<int> list_s_2(test_arr2, 4);
			ListSequence<int> list_s_3(test_arr3, 5);
			ListSequence<int> list_s_4(test_arr4, 2);
			ListSequence<int> list_s_5(test_arr5, 3);
			ListSequence<int> list_s_6(test_arr6, 4);
			ListSequence<int> list_s_concat(test_concat, 9);
			ListSequence<int> list_s_sublist(test_sublist, 3);

			Assert::IsTrue(list_s_t.GetLength() == 2, L"GetSize method");
			Assert::IsTrue(list_s_s.GetLength() == 2, L"GetSize method");
			Assert::IsTrue(list_s_c.GetLength() == 3, L"GetSize method");
			Assert::IsTrue(list_s_d.GetLength() == 3, L"GetSize method");
			Assert::IsTrue(list_s_i.GetLength() == 5, L"GetSize method");


			Assert::IsTrue(list_s_i.GetFirst() == 1, L"Getter method");
			Assert::IsTrue(list_s_i.GetLast() == 5, L"Getter method");
			Assert::IsTrue(list_s_i.Get(1) == 2, L"Getter method");
			list_s_i.DeleteLast();
			Assert::IsTrue(list_s_i == list_s_2, L"Delete method");
			list_s_i.Append(1);
			Assert::IsTrue(list_s_i == list_s_3, L"Setter method");
			list_s_4.Prepend(1);
			Assert::IsTrue(list_s_4 == list_s_5, L"Prepend method");
			list_s_4.InsertAt(2, 9);
			Assert::IsTrue(list_s_4 == list_s_6, L"InsertAt method");
			Assert::IsTrue(*(list_s_i.Concat(&list_s_4)) == list_s_concat, L"Concat method");
			Assert::IsTrue(*(list_s_i.GetSubsequence(1, 3)) == list_s_sublist, L"GetSublist method");
		}

		TEST_METHOD(StackTest)
		{
			int test_arr_i[5] = { 1, 2, 3, 4, 5 };
			double test_arr_d[3] = { 1.1, 2.2, 3.3 };
			Teacher test_arr_t[2] = { Teacher("Vitaly", "Leonidovich", "Kaminin", "math", 40), Teacher("Dmitriy", "Sergeevich", "Telyakovskii", "math", 35) };
			Student test_arr_s[2] = { Student("Alexey", "Viktorovich", "Ryzhov", 514, 21, 4.4), Student("Alexey", "P", "Varlamov", 514, 8, 3.8) };
			Complex test_arr_c[3] = { Complex(1.1, 2.2), Complex(2.1, 1.4), Complex(3.1, 5.2) };
			int test_arr2[4] = { 1, 2, 3, 4 };
			int test_arr3[5] = { 1, 2, 3, 4, 1 };
			int test_arr4[2] = { 6, 8 };
			int test_arr5[3] = { 1, 6, 8 };
			int test_arr6[4] = { 1, 6, 9, 8 };
			int test_concat[9] = { 1, 2, 3, 4, 1, 1, 6, 9, 8 };
			int test_sublist[3] = { 2, 3, 4 };

			Stack<int> stack_1_i(test_arr_i, 5, 1);
			Stack<double> stack_1_d(test_arr_d, 3, 1);
			Stack<Teacher> stack_1_t(test_arr_t, 2, 1);
			Stack<Student> stack_1_s(test_arr_s, 2, 1);
			Stack<Complex> stack_1_c(test_arr_c, 3, 1);



			Assert::IsTrue(stack_1_t.Size() == 2, L"GetSize method");
			Assert::IsTrue(stack_1_s.Size() == 2, L"GetSize method");
			Assert::IsTrue(stack_1_c.Size() == 3, L"GetSize method");
			Assert::IsTrue(stack_1_d.Size() == 3, L"GetSize method");
			Assert::IsTrue(stack_1_i.Size() == 5, L"GetSize method");

	
			Stack<int> stack_2_i(test_arr_i, 5, 2);
			Stack<double> stack_2_d(test_arr_d, 3, 2);
			Stack<Teacher> stack_2_t(test_arr_t, 2, 2);
			Stack<Student> stack_2_s(test_arr_s, 2, 2);
			Stack<Complex> stack_2_c(test_arr_c, 3, 2);

			Assert::IsTrue(stack_2_t.Size() == 2, L"GetSize method");
			Assert::IsTrue(stack_2_s.Size() == 2, L"GetSize method");
			Assert::IsTrue(stack_2_c.Size() == 3, L"GetSize method");
			Assert::IsTrue(stack_2_d.Size() == 3, L"GetSize method");
			Assert::IsTrue(stack_2_i.Size() == 5, L"GetSize method");

			stack_1_i.Pop();
			Assert::IsTrue(stack_1_i.Top() == 4, L"Pop method");
			stack_2_i.Pop();
			Assert::IsTrue(stack_2_i.Top() == 4, L"Pop method");
			stack_1_i.Push(1);
			Assert::IsTrue(stack_1_i.Top() == 1, L"Push method");
			stack_2_i.Push(1);
			Assert::IsTrue(stack_2_i.Top() == 1, L"Push method");			
		}
	};
}
