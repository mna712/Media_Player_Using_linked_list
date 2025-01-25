#pragma once
#ifndef DLL_H
#define DLL_H

#include <iostream>
using namespace std;
template <typename T>
struct Node
{
    T data;
    Node* prev;
    Node* next;
    Node(T value) : data(value), prev(nullptr), next(nullptr) {}
};

template <typename T>
class DLL
{

public:
    Node<T>* head;
    int size;

public:
    DLL() : head(nullptr), size(0) {}

    Node<T>* getHead() const {
        return head;
    }
    int get_size()const
    {
        return size;
    }

    void insertion_at_beg(T value)
    {
        Node<T>* newnode = new Node<T>(value);
        newnode->next = head;
        if (head != nullptr)
        {
            head->prev = newnode;
        }
        head = newnode;
        size++;
    }


    void insert_at_end(T value)
    {
        Node<T>* newnode = new Node<T>(value);
        if (head == nullptr)
        {
            head = newnode;
        }
        else
        {
            Node<T>* temp = head;
            while (temp->next != nullptr)
            {
                temp = temp->next;
            }
            temp->next = newnode;
            newnode->prev = temp;
        }
        size++;
    }
    T getAt(int position) const {
        if (position < 0 || position >= size) throw out_of_range("Position out of range");

        Node<T>* current = head;
        for (int i = 0; i < position; i++) {
            current = current->next;
        }
        return current->data;
    }
    // Insertion at a specific position
    void insert_at_pos(T value, int pos)
    {
        if (pos == 1)
        {
            insertion_at_beg(value);
        }
        else
        {
            Node<T>* newnode = new Node<T>(value);
            Node<T>* temp = head;
            for (int i = 1; i < pos - 1 && temp != nullptr; i++)
            {
                temp = temp->next;
            }
            if (temp == nullptr)
            {
                cout << "Out of range\n";
            }
            else
            {
                newnode->next = temp->next;
                if (temp->next != nullptr)
                {
                    temp->next->prev = newnode;
                }
                temp->next = newnode;
                newnode->prev = temp;
            }
        }
        size++;
    }

    // Delete at beginning
    void delete_at_beg()
    {
        if (head == nullptr)
        {
            cout << "List is empty\n";
            return;
        }
        Node<T>* temp = head;
        head = head->next;
        if (head != nullptr)
        {
            head->prev = nullptr;
        }
        delete temp;
        size--;
    }

    // Delete at end
    void delete_at_end()
    {
        if (head == nullptr)
        {
            cout << "List is empty\n";
            return;
        }
        if (head->next == nullptr) // Only one element
        {
            delete head;
            head = nullptr;
            size--;
            return;
        }
        Node<T>* temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->prev->next = nullptr;
        delete temp;
        size--;
    }

    // Delete at specific position
    void delete_at_pos(int pos)
    {
        if (pos < 1)
        {
            cout << "The position is invalid\n";
            return;
        }
        if (head == nullptr)
        {
            cout << "List is empty\n";
            return;
        }
        if (pos == 1)
        {
            delete_at_beg();
            return;
        }
        Node<T>* temp = head;
        for (int i = 1; i < pos && temp != nullptr; i++)
        {
            temp = temp->next;
        }
        if (temp == nullptr)
        {
            cout << "Out of range\n";
        }
        else
        {
            temp->prev->next = temp->next;
            if (temp->next != nullptr)
            {
                temp->next->prev = temp->prev;
            }
            delete temp;
            size--;
        }
    }



    // Traverse in reverse (display)
    void reverse_traverse() const
    {
        if (head == nullptr) return;
        Node<T>* current = head;
        while (current->next != nullptr)
        {
            current = current->next;
        }
        while (current)
        {
            cout << current->data << " ";
            current = current->prev;
        }
        cout << endl;
    }

    // Search
    bool search(T value) const
    {
        Node<T>* current = head;
        while (current)
        {
            if (current->data == value)
            {
                return true;
            }
            current = current->next;
        }
        return false;
    }

    // Clear the list
    void clear() {
        Node<T>* current = head;
        while (current) {
            Node<T>* temp = current;
            current = current->next;
            delete temp;
        }
        head = nullptr;
        size = 0;
    }

    DLL<T>& operator=(const DLL<T>& other) {
        if (this != &other) {
            clear();

            Node<T>* current = other.head;
            while (current) {
                insert_at_end(current->data);
                current = current->next;
            }
        }
        return *this;
    }

    ~DLL()
    {
        clear();
    }
};

#endif
