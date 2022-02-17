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

        Node(T data = T(), Node* pNext = nullptr) {
            this->data = data;
            this->pNext = pNext;
        }
    };
    int Size;
    Node<T>* head;
};

template<typename T>
List<T>::List() {
    Size = 0;
    head = nullptr;
}

template<typename T>
List<T>::~List() {
}

template<typename T>
void List<T>::pop_front()
{
    Node<T>* temp = head;
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
T& List<T>::operator[](const int index)
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



void FillInc(List<int> lst, int n) {
    for (int i = 0; i < n; ++i) {
        lst.push_back(i);
    }
}

void FillDec(List<int> lst, int n) {
    for (int i = 0; i < n; ++i) {
        lst.push_back(n - i);
    }
}

void FillRand(List<int> lst, int n) {
    srand(time(NULL));
    for (int i = 0; i < n; ++i) {
        lst.push_back(rand() % n + 1);
    }
}

void MergeSort(List<int> lsta, List<int> lstb, int n) {
    List<int> lstc;
    int i = 0, j = 0, c = 0, CM = 0;
    int q = lsta.GetSize(), r = lstb.GetSize();
    while (q != 0 && r != 0) {
        ++CM;
        if (lsta[n - q] <= lstb[n - r]) {
            lstc[c] = lsta[n - q];
            ++CM;
            --q;
            ++c;
        }
        else {
            lstc[c] = lstb[n - r];
            ++CM;
            --r;
            ++c;
        }
    }
    while (q > 0) {
        lstc[c] = lsta[n - q];
        ++CM;
        --q;
        ++c;
    }
    while (r > 0) {
        ++CM;
        lstc[c] = lstb[n - r];
        --r;
        ++c;
    }
    cout << CM;
    lstc.clear();
}

int main()
{
    List<int> lsta, lstb;

    setlocale(LC_ALL, "Russian");

    int M, C, n;
    float Ct, Mt;
    cout << "n      M+C(t)    Dec(M+C)    Inc(M+C)    Rand(M+C)" << endl;
    for (int i = 1; i <= 5; i++) {
        n = 100 * i;

        Ct = 2 * n - 1;
        Mt = 2 * n;


        if (n == 100) {
            cout << n << "    " << Mt + Ct << "      "; FillDec(lsta, n); FillDec(lstb, n); MergeSort(lsta, lstb, n);
            cout << "        "; FillInc(lsta, n); FillInc(lstb, n); MergeSort(lsta, lstb, n);
            cout << "         "; FillRand(lsta, n); FillRand(lstb, n); MergeSort(lsta, lstb, n);
            cout << endl;
            lsta.clear(); lstb.clear();
        }

        if (n == 200) {
            cout << n << "    " << Mt + Ct << "     "; FillDec(lsta, n); FillDec(lstb, n); MergeSort(lsta, lstb, n);
            cout << "       "; FillInc(lsta, n); FillInc(lstb, n); MergeSort(lsta, lstb, n);
            cout << "         "; FillRand(lsta, n); FillRand(lstb, n); MergeSort(lsta, lstb, n);
            cout << endl;
            lsta.clear(); lstb.clear();
        }

        if (n == 300) {
            cout << n << "    " << Mt + Ct << "     "; FillDec(lsta, n); FillDec(lstb, n); MergeSort(lsta, lstb, n);
            cout << "       "; FillInc(lsta, n); FillInc(lstb, n); MergeSort(lsta, lstb, n);
            cout << "         "; FillRand(lsta, n); FillRand(lstb, n); MergeSort(lsta, lstb, n);
            cout << endl;
            lsta.clear(); lstb.clear();
        }

        if (n == 400) {
            cout << n << "    " << Mt + Ct << "     "; FillDec(lsta, n); FillDec(lstb, n); MergeSort(lsta, lstb, n);
            cout << "      "; FillInc(lsta, n); FillInc(lstb, n); MergeSort(lsta, lstb, n);
            cout << "        "; FillRand(lsta, n); FillRand(lstb, n); MergeSort(lsta, lstb, n);
            cout << endl;
            lsta.clear(); lstb.clear();
        }

        if (n == 500) {
            cout << n << "    " << Mt + Ct << "    "; FillDec(lsta, n); FillDec(lstb, n); MergeSort(lsta, lstb, n);
            cout << "      "; FillInc(lsta, n); FillInc(lstb, n); MergeSort(lsta, lstb, n);
            cout << "        "; FillRand(lsta, n); FillRand(lstb, n); MergeSort(lsta, lstb, n);
            cout << endl;
            lsta.clear(); lstb.clear();
        }
    }
}