#include <iostream>
#include <time.h>
#include <iomanip>

int numb = 1;

struct BranchTree {
    int Data;
    int NumVertex;
    BranchTree* LeftBranch;
    BranchTree* RightBranch;
};

BranchTree* AddVertex(int D, BranchTree*& p)
{
    if (p == NULL) {
        p = new BranchTree;
        p->Data = D;
        p->NumVertex = numb;
        ++numb;
        p->LeftBranch = NULL;
        p->RightBranch = NULL;
    }
    else if (D < p->Data) {
        AddVertex(D, p->LeftBranch);
    }
    else if (D > p->Data) {
        AddVertex(D, p->RightBranch);
    }
    else {
        return NULL;
    }
}

void Obhod(BranchTree*& aBranchTree) {
    if (aBranchTree == NULL) return;
    Obhod(aBranchTree->LeftBranch);
    std::cout << aBranchTree->NumVertex << ": " << aBranchTree->Data << " " << std::endl;
    Obhod(aBranchTree->RightBranch);
}

void DeleteVertex(BranchTree*& aBranchTree, int D) {
    BranchTree** p = &aBranchTree;
    BranchTree* q;
    BranchTree* S;
    BranchTree* r;
    while ((*p) != NULL) {
        if (D < (*p)->Data) {
            p = &((*p)->LeftBranch);
        }
        else if (D > ((*p)->Data)) {
            p = &((*p)->RightBranch);
        }
        else {
            break;
        }
    }

    if (*p != NULL) {
        q = *p;
        if (q->LeftBranch == NULL) {
            *p = q->RightBranch;
        }
        else if (q->RightBranch == NULL) {
            *p = q->LeftBranch;
        }
        else {
            r = q->LeftBranch;
            S = q;
            if (r->RightBranch == NULL) {
                r->RightBranch = q->RightBranch;
                *p = r;
            }
            else {
                while (r->RightBranch != NULL) {
                    S = r;
                    r = r->RightBranch;
                }
                S->RightBranch = r->LeftBranch;
                r->LeftBranch = q->LeftBranch;
                r->RightBranch = q->RightBranch;
                *p = r;
            }
        }

        free(q);
    }
}

int main()
{
    srand(time(NULL));
    int sizeTree = 30;
    int* arr = new int[sizeTree];
    for (int i = 0; i < sizeTree; i++)
    {
        arr[i] = (rand() % 100 + 1);
    }
    BranchTree* Root = 0;
    for (int i = 0; i < sizeTree; ++i) {
        AddVertex(arr[i], Root);
    }

    Obhod(Root);

    int x;

    for (int i = 0; i < 10; i++) {
        std::cin >> x;
        DeleteVertex(Root, x);
        Obhod(Root);
    }


}