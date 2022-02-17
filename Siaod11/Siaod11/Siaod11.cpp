#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string>

using namespace std;

template<typename T>
class List {
public:
    List();
    ~List();

    void pop_front();
    void push_back(T data); 
    void clear();
    int GetSize() { return Size; }
    T& operator[](const int index);

private:


    template<typename T>
    class Node {
    public:
        Node* pNext;
        T data;

        Node(T data=T(), Node* pNext = nullptr) {
            this->data = data;
            this->pNext = pNext;
        }
    };
    int Size;
    Node<T> *head;
};

template<typename T>
List<T>::List() {
    Size = 0;
    head = nullptr;
}

template<typename T>
List<T>::~List() {
    cout << endl <<"Очистка..." << endl;
    clear();
}

template<typename T>
void List<T>::pop_front()
{
    Node<T> *temp = head;
    head = head->pNext;
    delete temp;
    Size--;


}

template<typename T>
void List<T>::push_back(T data)
{
    if (head == nullptr) {
        head = new Node<T>(data);
    }
    else {
        Node<int>* current = this->head;
        while (current->pNext != nullptr) {
            current = current->pNext;
        }
        current->pNext = new Node<T>(data);

    }
    Size++;
}

template<typename T>
void List<T>::clear()
{
    while (Size) {
        pop_front();
    }

}

template<typename T>
T & List<T>::operator[](const int index)
{
    int counter = 0;
    Node<T>* current = this->head;
    while (current != nullptr) {
        if (counter == index) {
            return current->data;
        }
        current = current->pNext;
        counter++;
    }
}



void FillInc(int n) {
    List<int> lst;
    for (int i = 0; i < n; ++i) {
        lst.push_back(i);
        cout << lst[i] << " ";
    }

    int num = 1;
    for (int i = 0; i < n - 1; i++) {
        if (lst[i] > lst[i + 1]) num++;
    }
    cout << endl << "Num = " << num;

    int sum = 0;
    for (int i = 0; i < n; i++) sum += lst[i];
    cout << endl << "Sum = " <<sum;
}

void FillDec(int n) {
    List<int> lst;
    for (int i = 0; i < n; ++i) {
        lst.push_back(n - i);
        cout << lst[i] << " ";
    }

    int num = 1;
    for (int i = 0; i < n - 1; i++) {
        if (lst[i] > lst[i + 1]) num++;
    }
    cout << endl << "Num = " << num;

    int sum = 0;
    for (int i = 0; i < n; i++) sum += lst[i];
    cout << endl << "Sum = " << sum;
}

void FillRand(int n) {
    List<int> lst;
    srand(time(NULL));
    for (int i = 0; i < n; ++i) {
        lst.push_back(rand() % n + 1);
        cout << lst[i] << " ";
    }

    int num = 1;
    for (int i = 0; i < n - 1; i++) {
        if (lst[i] > lst[i + 1]) num++;
    }
    cout << endl << "Num = " << num;

    int sum = 0;
    for (int i = 0; i < n; i++) sum += lst[i];
    cout << endl << "Sum = " << sum;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    int n;
    cout << "Введите количество чисел: " << endl;
    cin >> n;

    FillInc(n);

    FillDec(n);

    FillRand(n);
}