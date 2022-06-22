#pragma once
#include "DynamicArray1.h"
#include "LinkedList1.h"

template <class T> class Sequence
{
public:
    virtual ~Sequence() = 0;

    virtual T Get(int index) = 0;
    virtual T GetFirst() = 0;
    virtual T GetLast() = 0;
    virtual int GetLength() = 0;

    virtual Sequence<T>* GetSubsequence(int startIndex, int endIndex) const = 0;
    virtual Sequence<T>* Concat(Sequence<T>* list) = 0;

    virtual void Append(T item) = 0;
    virtual void Prepend(T item) = 0;
    virtual void InsertAt(int index, T item) = 0;
    virtual void DeleteLast() = 0;

    virtual void Print() = 0;
    virtual void Print_line() = 0;
    virtual void Print(int index) = 0;
};

template <class T> Sequence<T>::~Sequence() {}

template <class T> class ArraySequence : public Sequence<T>
{
private:
    DynamicArray<T>* array_s = nullptr;
public:
    ArraySequence()
    {
        array_s = new DynamicArray<T>;
    }
    ArraySequence(T* items, int count)
    {
        array_s = new DynamicArray<T>(items, count);
    }
    ArraySequence(const DynamicArray<T>& dynamicarr)
    {
        array_s = new DynamicArray<T>(dynamicarr);
    }
    ArraySequence(Sequence<T>* another)
    {
        ArraySequence<T>* ArraySeq = dynamic_cast<ArraySequence<T>*>(another);
        array_s = new DynamicArray<T>(*(ArraySeq->array_s));
    }
    ~ArraySequence() override
    {
        delete array_s;
    }


    T GetFirst() override
    {
        if (array_s == nullptr || array_s->GetSize() == 0)
        {
            throw std::out_of_range("IndexOutOfRange");
        }
        return array_s->Get(0);
    }
    T GetLast() override
    {
        return array_s->Get(array_s->GetSize() - 1);
    }
    T Get(int index) override
    {
        if (index >= array_s->GetSize() || index < 0)
        {
            throw std::out_of_range("IndexOutOfRange");
        }
        return array_s->Get(index);
    }


    ArraySequence<T>* GetSubsequence(int startIndex, int endIndex) const override
    {
        if (startIndex >= array_s->GetSize() || endIndex >= array_s->GetSize() || startIndex < 0 || endIndex < 0)
        {
            throw std::out_of_range("IndexOutOfRange");
        }
        ArraySequence<T>* subsequence = new ArraySequence<T>;
        subsequence->array_s = array_s->GetSublist(startIndex, endIndex);
        return subsequence;
    }
    int GetLength() override
    {
        return array_s->GetSize();
    }

    void Append(T item) override 
    {
        array_s->Set(array_s->GetSize(), item);
    }

    void Prepend(T item) override
    {

        array_s->Set(0, item);

    }
    void InsertAt(int index, T item) override
    {
        if (index > array_s->GetSize() || index < 0)
        {
            throw std::out_of_range("IndexOutOfRange");
        }
        array_s->Set(index, item);
    }
    ArraySequence<T>* Concat(Sequence<T>* sequence) override
    {
        ArraySequence<T>* ArraySeq = static_cast<ArraySequence<T>*>(sequence);
        ArraySequence<T>* result = new ArraySequence<T>;
        result->array_s = array_s->Concat(ArraySeq->array_s);
        return result;
    }

    void Print() override
    {
        array_s->Print();
    }
    void Print_line() override
    {
        array_s->Print_line();
    }
    void Print(int index) override
    {
        array_s->Print(index);
    }

    void DeleteLast() override
    {
        array_s->DeleteLast();
    }

    bool operator==(const ArraySequence<T>& arr_sequence) {
        return (*array_s == *arr_sequence.array_s);
    }

};

template <class T> class ListSequence : public Sequence<T>
{
private:
    LinkedList<T>* list_s = nullptr;

public:

    ListSequence()
    {
        list_s = new LinkedList<T>;
    }
    ListSequence(T* items, int count)
    {
        list_s = new LinkedList<T>(items, count);
    }
    ListSequence(const LinkedList<T>& list)
    {
        list_s = new LinkedList<T>(list);
    }
    ListSequence(Sequence<T>* another)
    {
        ListSequence<T>* ListSeq = static_cast<ListSequence<T>*>(another);
        list_s = new LinkedList<T>(*(another->list_s));
    }
    ListSequence(const ListSequence<T>& another)
    {
        list_s = new LinkedList<T>(*(another->list_s));
    }


    T GetFirst() override
    {
        if (!list_s)
        {
            throw std::out_of_range("IndexOutOfRange");
        }

        list_s->GetFirst();
    }
    T GetLast() override
    {
        if (!list_s)
        {
            throw std::out_of_range("IndexOutOfRange");
        }

        list_s->GetLast();
    }
    T Get(int index) override
    {
        if (index >= list_s->GetLength() || index < 0)
        {
            throw std::out_of_range("IndexOutOfRange");
        }
        list_s->GetIndex(index);
    }


    ListSequence<T>* GetSubsequence(int startIndex, int endIndex) const override
    {
        if (startIndex >= list_s->GetLength() || startIndex < 0 || endIndex >= list_s->GetLength() || endIndex < 0)
        {
            throw std::out_of_range("IndexOutOfRange");
        }
        ListSequence<T>* subsequence = new ListSequence<T>;
        subsequence->list_s = list_s->GetSubList(startIndex, endIndex);
        return subsequence;
    }
    int GetLength() override
    {
        return list_s->GetLength();
    }
    void Append(T item) override
    {
        list_s->Append(item);
    }
    void Prepend(T item) override
    {
        list_s->Prepend(item);
    }
    void InsertAt(int index, T item) override
    {
        list_s->InsertAt(index, item);
    }
    ListSequence<T>* Concat(Sequence<T>* sequence) override
    {
        ListSequence<T>* ListSeq = static_cast<ListSequence<T>*>(sequence);
        ListSequence<T>* result = new ListSequence<T>;
        result->list_s = list_s->Concat(ListSeq->list_s);
        return result;
    }
    void Print() override
    {
        list_s->Print();
    }
    void Print_line() override
    {
        list_s->Print_line();
    }
    void Print(int index) override
    {
        list_s->Print(index);
    }
    void DeleteLast() override
    {
        list_s->DeleteLast();
    }
    bool operator==(const ListSequence<T>& list_sequence) {
        return (*list_s == *list_sequence.list_s);
    }
};


