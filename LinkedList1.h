#pragma once
#include <iostream>

template <class T> class LinkedList
{
private:
    int size = 0;
    struct Item
    {
        T data;
        struct Item* next = nullptr;

    };

    struct Item* head = nullptr;
    struct Item* tail = nullptr;

public:
    LinkedList();
    LinkedList(T* items, int count);
    LinkedList(const LinkedList<T>& list);
    ~LinkedList();

    T GetFirst();
    T GetLast();
    T GetIndex(int index);
    int GetLength();
    LinkedList<T>* GetSubList(int startIndex, int endIndex);

    void Append(T item);
    void Prepend(T item);
    void InsertAt(int index, T item);
    void DeleteLast();
    LinkedList<T>* Concat(LinkedList<T>* list);

    void Print();
    void Print_line();
    void Print(int index);

    bool operator==(const LinkedList<T>& a);
    bool operator!=(const LinkedList<T>& a);
};

template <class T> LinkedList<T>::LinkedList() {}
template <class T> LinkedList<T>::LinkedList(T* items, int count) : size(count)
{
    for (int i = 0; i < size; i++)
    {
        struct Item* ptr = new struct Item;
        ptr->data = items[i];
        if (head == nullptr)
        {
            head = ptr;
            tail = ptr;
        }
        else
        {
            tail->next = ptr;
            tail = ptr;
        }
    }
}
template <class T> LinkedList<T>::LinkedList(const LinkedList<T>& linkedlist) : size(linkedlist.size)
{
    struct Item* list_item = linkedlist.head;
    for (int i = 0; i < size; i++)
    {
        struct Item* ptr = new struct Item;
        ptr->data = list_item->data;
        if (head == nullptr)
        {
            head = ptr;
            tail = ptr;
        }
        else
        {
            tail->next = ptr;
            tail = ptr;
        }
        list_item = list_item->next;
    }
}
template <class T> LinkedList<T>::~LinkedList()
{
    struct Item* ptr_prev = head;
    struct Item* ptr = nullptr;
    for (int i = 0; i < size; i++)
    {
        ptr = ptr_prev->next;
        delete ptr_prev;
        ptr_prev = ptr;
    }
}


template <class T> T LinkedList<T>::GetFirst()
{
    if (!head)
    {
        throw std::out_of_range("IndexOutOfRange");
    }
    return head->data;
}
template <class T> T LinkedList<T>::GetLast()
{
    if (!tail)
    {
        throw std::out_of_range("IndexOutOfRange");
    }
    return tail->data;
}
template <class T> T LinkedList<T>::GetIndex(int index)
{
    if (size == 0 || index < 0 || index >= size)
    {
        throw std::out_of_range("IndexOutOfRange");
    }

    struct Item* ptr = head;
    for (int i = 0; i < index; i++)
    {
        ptr = ptr->next;
    }

    return ptr->data;
}
template <class T> int LinkedList<T>::GetLength()
{
    return size;
}
template <class T> LinkedList<T>* LinkedList<T>::GetSubList(int startIndex, int endIndex)
{
    LinkedList<T>* SubList = new LinkedList<T>();
    SubList->size = endIndex - startIndex + 1;
    struct Item* ptr = head;
    struct Item* ptr_prev = nullptr;
    for (int i = 0; i < size; i++)
    {
        if (startIndex < 0 || endIndex < 0 || endIndex >= size)
        {
            throw std::out_of_range("IndexOutOfRange");
        }

        if (i == startIndex)
        {
            struct Item* SubItem = new struct Item;
            SubItem->data = ptr->data;
            SubList->head = SubItem;
            ptr_prev = SubItem;
        }
        if (i > startIndex && i <= endIndex)
        {
            struct Item* SubItem = new struct Item;
            SubItem->data = ptr->data;
            ptr_prev->next = SubItem;
            ptr_prev = SubItem;
        }
        ptr = ptr->next;
    }
    return SubList;


}

template <class T> void LinkedList<T>::Append(T item)
{
    if (!head || !tail) {
        ++size;
        struct Item* end = new struct Item;
        end->data = item;
        head = end;
        tail = end;
        return;
    }
    ++size;
    struct Item* end = new struct Item;
    end->data = item;
    tail->next = end;
    tail = end;
}

template <class T> void LinkedList<T>::Prepend(T item)
{
    ++size;
    struct Item* start = new struct Item;
    start->data = item;
    start->next = head;
    head = start;
}

template <class T> LinkedList<T>* LinkedList<T>::Concat(LinkedList<T>* linkedlist)
{
    LinkedList<T>* result = new LinkedList<T>(*this);
    result->size = this->size + linkedlist->size;
    struct Item* ptr = linkedlist->head;
    while (ptr) 
    {
        struct Item* new_node = new struct Item;
        new_node->data = ptr->data;
        if (!result->head) 
        {
            result->head = ptr;
            result->tail = ptr;
        }
        else 
        {
            result->tail->next = ptr;
            result->tail = ptr;
        }
        ptr = ptr->next;
    }
    return result;
}
template <class T> void LinkedList<T>::InsertAt(int index, T item)
{
    if (index >= size || index < 0)
    {
        throw std::out_of_range("IndexOutOfRange");
    }

    ++size;
    struct Item* insert = new struct Item;
    insert->data = item;
    struct Item* ptr = head;
    for (int i = 0; i < index; i++)
    {
        if (i == index - 1)
        {
            insert->next = ptr->next;
            ptr->next = insert;
        }
        ptr = ptr->next;
    }
}
template <class T> void LinkedList<T>::Print()
{
    struct Item* ptr = head;
    for (int i = 0; i < size; i++)
    {
        std::cout << ptr->data << std::endl;
        ptr = ptr->next;
    }
}

template <class T> void LinkedList<T>::Print_line()
{
    struct Item* ptr = head;
    for (int i = 0; i < size - 1; i++)
    {
        std::cout << "[" << ptr->data << "] ";
        ptr = ptr->next;
    }
    std::cout << "[" << ptr->data << "]" << std::endl;
}

template <class T> void LinkedList<T>::Print(int index)
{
    struct Item* ptr = head;
    for (int i = 0; i < size; i++)
    {
        if (i == index)
        {
            std::cout << ptr->data << std::endl;
        }
        ptr = ptr->next;
    }
}
template <class T> void LinkedList<T>::DeleteLast() 
{
    struct Item* ptr = head;
    if (ptr == tail) 
    {
        delete ptr;
        head = nullptr;
        tail = nullptr;
        size = 0;
        return;
    }
    while (ptr->next != tail) 
    {
        ptr = ptr->next;
    }
    delete tail;
    tail = ptr;
    ptr->next = nullptr;
    size--;
}

template <class T> bool LinkedList<T>::operator==(const LinkedList<T>& a) 
{
    if (size != a.size) 
    {
        return false;
    }
    else 
    {
        struct Item* ptr = head;
        struct Item* ptr_a = a.head;
        while (ptr) 
        {
            if (!ptr_a) return false;
            if (ptr->data != ptr_a->data) return false;
            ptr = ptr->next;
            ptr_a = ptr_a->next;
        }
        if (ptr_a)	return false;
    }
    return true;
}
template <class T> bool LinkedList<T>::operator!=(const LinkedList<T>& a) {
    return !(a == *this);
}
