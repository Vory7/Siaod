#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string>
#include <iomanip>

struct Node {
    int val;
    Node* next;
    Node(int _val) :val(_val), next(nullptr) {}
};

struct list {
    Node* first;
    Node* last;
    list() :first(nullptr), last(nullptr) {}

    bool is_empty() {
        return first == nullptr;
    }

    void push_back(int _val) {
        Node* p = new Node(_val);

        if (is_empty()) {
            first = p;
            last = p;
            return;
        }

        last->next = p;
        last = p;
    }

    void print() {
        Node* p = first;
        if (is_empty()) return;
        while (p != nullptr) {
            std::cout << std::setw(3) << p->val << " ";
            p = p->next;
        }
        std::cout << std::endl;
    }

    Node* find(int _val) {
        Node* p = first;
        while (p && p->val != _val)p = p->next;
        return (p && p->val == _val) ? p : nullptr;
    }

    void remove_first() {
        if (is_empty()) return;
        Node* p = first;
        first = p->next;
        delete p;
    }

    void remove_last() {
        if (is_empty()) return;
        if (first == last) {
            remove_first();
            return;
        }
        Node* p = first;
        while (p->next != last) p = p->next;
        p->next = nullptr;
        delete last;
        last = p;
    }

    void remove(int _val) {
        if (is_empty()) return;

        if (first->val == _val) {
            remove_first();
            return;
        }
        else if (last->val == _val) {
            remove_last();
            return;
        }

        Node* slow = first;
        Node* fast = first->next;
        while (fast && fast->val != _val) {
            fast = fast->next;
            slow = slow->next;
        }

        if (!fast) {
            std::cout << "This element does not exist" << std::endl;
            return;
        }

        slow->next = fast->next;
        delete fast;
    }

    Node* operator[](const int index) {
        if (is_empty()) return nullptr;
        Node* p = first;
        for (int i = 0; i < index; ++i) {
            p = p->next;
            if (!p) return nullptr;
        }
        return p;
    }


};

void function(int size, int** matrix) {
    int m = 0;
    int k1 = 0, k2 = 0;
    int* S = new int[size];
    int h = 0;
    for (int i = 0; i < size; ++i) {
        S[i] = (rand() % size) + 1;
    }

    for (int i = 0; i < size; ++i) {
        int o = 0;
        for (int j = i - 1; j >= 0; --j) {
            if (S[i] == S[j]) {
                ++o;
                break;
            }
        }
        if (o != 0) continue;
        ++m;
    }

    for (int i = 0; i < m; ++i) {
        matrix[0][i] = i;
        matrix[1][i] = 0;
        matrix[2][i] = i;
        matrix[3][i] = 0;
    }

    for (int i = 0; i < size; ++i) {
        int o = 0;
        for (int j = i - 1; j >= 0; --j) {
            if (S[i] == S[j]) {
                ++o;
                break;
            }
        }
        if (o != 0) continue;
        h = S[i] % m;

    try1:

        if (matrix[1][h] > 0) {
            ++h;
            ++k1;
            goto try1;
        }
        else {
            matrix[1][h] = S[i];
        }

        int k = 1;
        h = S[i] % m;
    try2:
        if (matrix[3][h] > 0) {
            if (k >= m) break;
            h += k;
            k += 2;
            ++k2;
            goto try2;
        }
        else {
            matrix[3][h] = S[i];
        }



    }
    std::cout << std::endl << "|     " << std::setw(2) << m << "     |      " << std::setw(3) << size << "        |       " << std::setw(2) << k1 << "      |      " << std::setw(2) << k2 << "      |";
}

int main()
{
    srand(time(NULL));
    int size = 20;
    int* S = new int[size];
    list S0;
    list S1;
    list S2;
    list S3;
    list S4;
    for (int i = 0; i < size; ++i) {
        S[i] = rand() % size;
    }
    std::cout << size << std::endl;
    int h = 0;
    int m = 5;
    int i = 0;
    int x;
    for (int i = 0; i < size; ++i) {
        int o = 0;
        for (int j = i - 1; j >= 0; --j) {
            if (S[i] == S[j]) {
                ++o;
                break;
            }
        }
        if (o != 0) continue;
        h = S[i] % m;
        if (h == 0) {
            S0.push_back(S[i]);
        }
        if (h == 1) {
            S1.push_back(S[i]);
        }
        if (h == 2) {
            S2.push_back(S[i]);
        }
        if (h == 3) {
            S3.push_back(S[i]);
        }
        if (h == 4) {
            S4.push_back(S[i]);
        }
    }
    std::cout << "S: ";
    for (int i = 0; i < size; ++i) {
        std::cout << S[i] << " ";
    }
    std::cout << std::endl << std::endl;
    std::cout << "0: "; S0.print();
    std::cout << "1: "; S1.print();
    std::cout << "2: "; S2.print();
    std::cout << "3: "; S3.print();
    std::cout << "4: "; S4.print();

    std::cout << "Vvedite iskomoe chislo: ";
    std::cin >> x;

    h = x % m;

    if (h == 0) {
        if (S0.find(x)) {
            std::cout << "Chislo v spiske 0";
        }
    }
    if (h == 1) {
        if (S1.find(x)) {
            std::cout << "Chislo v spiske 1";
        }
    }
    if (h == 2) {
        if (S2.find(x)) {
            std::cout << "Chislo v spiske 2";
        }
    }
    if (h == 3) {
        if (S3.find(x)) {
            std::cout << "Chislo v spiske 3";
        }
    }
    if (h == 4) {
        if (S4.find(x)) {
            std::cout << "Chislo v spiske 4";
        }
    }

    int k1 = 0, k2 = 0;

    for (int i = 0; i < size; ++i) {
        S[i] = (rand() % size) + 1;
    }

    for (int i = 0; i < size; ++i) {
        int o = 0;
        for (int j = i - 1; j >= 0; --j) {
            if (S[i] == S[j]) {
                ++o;
                break;
            }
        }
        if (o != 0) continue;
        ++m;
    }

    int** matrix = new int* [4];
    for (int i = 0; i < 4; ++i) {
        matrix[i] = new int[m];
    }

    for (int i = 0; i < m; ++i) {
        matrix[0][i] = i;
        matrix[1][i] = 0;
        matrix[2][i] = i;
        matrix[3][i] = 0;
    }

    for (int i = 0; i < size; ++i) {
        int o = 0;
        for (int j = i - 1; j >= 0; --j) {
            if (S[i] == S[j]) {
                ++o;
                break;
            }
        }
        if (o != 0) continue;
        h = S[i] % m;

    try1:

        if (matrix[1][h] > 0) {
            ++h;
            ++k1;
            goto try1;
        }
        else {
            matrix[1][h] = S[i];
        }

        int k = 1;
        h = S[i] % m;
    try2:
        if (matrix[3][h] > 0) {
            if (k >= m) break;
            h += k;
            k += 2;
            ++k2;
            goto try2;
        }
        else {
            matrix[3][h] = S[i];
        }
    }
    
    std::cout << std::endl << std::endl;
    for (int i = 0; i < size; ++i) {
        std::cout << std::setw(3) << S[i] << " ";
    }
    std::cout << std::endl << std::endl << "Nomer:  ";
    for (int i = 0; i < m; ++i) {
        std::cout << std::setw(3) << matrix[0][i] << " ";
    }
    std::cout << std::endl << "Simvol: ";
    for (int i = 0; i < m; ++i) {
        std::cout << std::setw(3) << matrix[1][i] << " ";
    }

    std::cout << std::endl << std::endl << "Nomer:  ";
    for (int i = 0; i < m; ++i) {
        std::cout << std::setw(3) << matrix[2][i] << " ";
    }
    std::cout << std::endl << "Simvol: ";
    for (int i = 0; i < m; ++i) {
        std::cout << std::setw(3) << matrix[3][i] << " ";
    }
    std::cout << std::endl;
    std::cout << std::endl << "|            |                 |        Kol-vo kolliziy       |";
    std::cout << std::endl << "|Razmer tabl | Kol-vo simvolov |    Lyneynie   | Kvadrtichniye|";
    for (int i = 1; i <= 4; ++i)
    {
        size = i * 10;
        function(size, matrix);
    }


    return 0;
}