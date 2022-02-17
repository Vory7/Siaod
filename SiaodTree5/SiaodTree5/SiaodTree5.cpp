#include <iostream>
#include <time.h>
#include <iomanip>

int numb = 1;
int tabs = 0;
int Rost;
int Umen;

struct BranchTree {
    int Data;
    int NumVertex;
    int Bal;
    BranchTree* LeftBranch;
    BranchTree* RightBranch;
};

BranchTree* q;
BranchTree* r;

void LL(BranchTree*& p) {
    q = p->LeftBranch;
    if (q->Bal == 0) {
        q->Bal = 1;
        p->Bal = -1;
        Umen = 0;
    }
    else {
        q->Bal = 0;
        p->Bal = 0;
    }
    p->LeftBranch = q->RightBranch;
    q->RightBranch = p;
    p = q;
}

void RR(BranchTree*& p) {
    q = p->RightBranch;
    if (q->Bal == 0) {
        q->Bal = -1;
        p->Bal = 1;
        Umen = 0;
    }
    else {
        p->Bal = 0;
        q->Bal = 0;
    }
    p->RightBranch = q->LeftBranch;
    q->LeftBranch = p;
    p = q;
}

void LR(BranchTree*& p) {
    q = p->LeftBranch;
    r = q->RightBranch;
    if (r->Bal < 0) {
        p->Bal = 1;
    }
    else {
        p->Bal = 0;
    }

    if (r->Bal > 0) {
        q->Bal = -1;
    }
    else {
        q->Bal = 0;
    }

    r->Bal = 0;
    q->RightBranch = r->LeftBranch;
    p->LeftBranch = r->RightBranch;
    r->LeftBranch = q;
    r->RightBranch = p;
    p = r;
}

void RL(BranchTree*& p) {
    q = p->RightBranch;
    r = q->LeftBranch;
    if (r->Bal > 0) {
        p->Bal = -1;
    }
    else {
        p->Bal = 0;
    }

    if (r->Bal < 0) {
        q->Bal = 1;
    }
    else {
        q->Bal = 0;
    }

    r->Bal = 0;
    q->LeftBranch = r->RightBranch;
    p->RightBranch = r->LeftBranch;
    r->RightBranch = q;
    r->LeftBranch = p;
    p = r;
}

void BL(BranchTree*& p) {
    if (p->Bal == -1) {
        p->Bal = 0;
    }
    else if (p->Bal == 0) {
        p->Bal = 1;
        Umen = 0;
    }
    else if (p->Bal == 1) {
        if (p->RightBranch->Bal >= 0) {
            RR(p);
        }
        else {
            RL(p);
        }
    }
}

void BR(BranchTree*& p) {
    if (p->Bal == 1) {
        p->Bal = 0;
    }
    else if (p->Bal == 0) {
        p->Bal = -1;
        Umen = 0;
    }
    else if (p->Bal == -1) {
        if (p->LeftBranch->Bal <= 0) {
            LL(p);
        }
        else {
            LR(p);
        }
    }
}

BranchTree* AddVertex(int D, BranchTree*& p)
{
    if (p == NULL) {
        p = new BranchTree;
        p->Data = D;
        p->NumVertex = numb;
        ++numb;
        p->LeftBranch = NULL;
        p->RightBranch = NULL;
        p->Bal = 0;
        Rost = 1;
    }
    else if (p->Data > D) {
        AddVertex(D, p->LeftBranch);
        if (Rost == 1) {
            if (p->Bal > 0) {
                p->Bal = 0;
                Rost = 0;
            }
            else if (p->Bal == 0) {
                p->Bal = -1;
                Rost = 1;
            }
            else {
                if (p->LeftBranch->Bal < 0) {
                    LL(p);
                    Rost = 0;
                }
                else {
                    LR(p);
                    Rost = 0;
                }
            }
        }

    }
    else if (p->Data <= D) {
        AddVertex(D, p->RightBranch);
        if (Rost == 1) {
            if (p->Bal < 0) {
                p->Bal = 0;
                Rost = 0;
            }
            else if (p->Bal == 0) {
                p->Bal = 1;
                Rost = 1;
            }
            else {
                if (p->RightBranch->Bal > 0) {
                    RR(p);
                    Rost = 0;
                }
                else {
                    RL(p);
                    Rost = 0;
                }
            }
        }
    }
    else {
        return NULL;
    }
}

int BalS(BranchTree*& p) {
    int L = ;

}

void Obhod(BranchTree*& aBranchTree) {
    if (aBranchTree == NULL) return;
    Obhod(aBranchTree->LeftBranch);
    std::cout << aBranchTree->NumVertex << ": " << aBranchTree->Data << " " << std::endl;
    Obhod(aBranchTree->RightBranch);
}

void Del(BranchTree*& r) {
    if (r->RightBranch != NULL) {
        Del(r->RightBranch);
        if (Umen == 1) BR(r);
    }
    else {
        q->Data = r->Data;
        q = r;
        r = r->LeftBranch;
        Umen = 1;
    }
}

void Delete(BranchTree*& p, int x) {
    if (p == NULL) {

    }
    else if (x < p->Data) {
        Delete(p->LeftBranch, x);
        if (Umen == 1) {
            BL(p);
        }
    }
    else if (x > p->Data) {
        Delete(p->RightBranch, x);
        if (Umen == 1) {
            BR(p);
        }
    }
    else {
        q = p;
        if (q->LeftBranch == NULL) {
            p = q->RightBranch;
            Umen = 1;
        }
        else if (q->RightBranch == NULL) {
            p = q->LeftBranch;
            Umen = 1;
        }
        else {
            Del(q->LeftBranch);
            if (Umen == 1) {
                BL(p);
            }
        }
    }
}



int main()
{
    srand(time(NULL));
    int sizeTree = 20, x;
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

    for (int i = 0; i < 10; ++i) {
        std::cin >> x;
        Delete(Root, x);
    }

    return 0;
}