#include <iostream>
#include <time.h>
#include <iomanip>

int numb = 1;
int tabs = 0;
int Rost;

struct BranchTree {
    int Data;
    int NumVertex;
    int Bal;
    BranchTree* LeftBranch;
    BranchTree* RightBranch;
};

void LLPov(BranchTree*& p) {
    BranchTree* q = p->LeftBranch;
    p->Bal = 0;
    q->Bal = 0;
    p->LeftBranch = q->RightBranch;
    q->RightBranch = p;
    p = q;
}

void RRPov(BranchTree*& p) {
    BranchTree* q = p->RightBranch;
    p->Bal = 0;
    q->Bal = 0;
    p->RightBranch = q->LeftBranch;
    q->LeftBranch = p;
    p = q;
}

void LRPov(BranchTree*& p) {
    BranchTree* q = p->LeftBranch;
    BranchTree* r = q->RightBranch;
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

void RLPov(BranchTree*& p) {
    BranchTree* q = p->RightBranch;
    BranchTree* r = q->LeftBranch;
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


BranchTree* AddVertex2(int D, BranchTree*& p)
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
        AddVertex2(D, p->LeftBranch);
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
                    LLPov(p);
                    Rost = 0;
                }
                else {
                    LRPov(p);
                    Rost = 0;
                }
            }
        }

    }
    else if (p->Data <= D) {
        AddVertex2(D, p->RightBranch);
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
                    RRPov(p);
                    Rost = 0;
                }
                else {
                    RLPov(p);
                    Rost = 0;
                }
            }
        }
    }
    else {
        return NULL;
    }
}



BranchTree* AddVertex1(int D, BranchTree*& p)
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
        AddVertex1(D, p->LeftBranch);
    }
    else if (D >= p->Data) {
        AddVertex1(D, p->RightBranch);
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

int TreeSize(BranchTree*& aBranchTree) {
    if (aBranchTree == NULL) return 0;
    int count = 0;
    count += TreeSize(aBranchTree->RightBranch);
    ++count;
    count += TreeSize(aBranchTree->LeftBranch);
    return count;
}

int ControlSum(BranchTree*& aBranchTree) {
    if (aBranchTree == NULL) return 0;
    int sum = 0;
    sum += ControlSum(aBranchTree->RightBranch);
    sum += aBranchTree->Data;
    sum += ControlSum(aBranchTree->LeftBranch);
    return sum;
}

int TreeHeight(BranchTree*& aBranchTree) {
    int h = 0;
    if (aBranchTree == NULL)
    {
        h = 0;
    }
    else
    {
        h = 1 + std::max(TreeHeight(aBranchTree->RightBranch), TreeHeight(aBranchTree->LeftBranch));
    }
    return h;
}

double SumLengths(BranchTree*& aBranchTree, int l) {
    int s;
    if (aBranchTree == NULL) {
        s = 0;
    }
    else {
        s = l + SumLengths(aBranchTree->LeftBranch, l + 1) + SumLengths(aBranchTree->RightBranch, l + 1);
    }
    return s;
}

int main()
{
    srand(time(NULL));
    int sizeTree = 100;
    int* arr = new int[sizeTree];
    for (int i = 0; i < sizeTree; i++)
    {
        //o = 0;
        arr[i] = (rand() % 100 + 1);
        /*for (int j = i - 1; j >= 0; --j) {
            if (arr[i] == arr[j]) {
                ++o;
                break;
            }
        }
        if (o != 0) --i;*/
    }

    BranchTree* Root1 = 0;
    for (int i = 0; i < sizeTree; ++i) {
        AddVertex1(arr[i], Root1);
    }

    numb = 0;
    BranchTree* Root2 = 0; 
    for (int i = 0; i < sizeTree; ++i) {
        AddVertex2(arr[i], Root2);
    }

    int Size1 = TreeSize(Root1);
    int Size2 = TreeSize(Root2);

    int Sum1 = ControlSum(Root1);
    int Sum2 = ControlSum(Root2);

    int Height1 = TreeHeight(Root1);
    int Height2 = TreeHeight(Root2);

    int l = 0;

    int SumLengths1 = SumLengths(Root1, l);
    int SumLengths2 = SumLengths(Root2, l);

    std::cout << "Bypassing the tree from left to right: " << std::endl;
    Obhod(Root2);
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "Tree size: " << Size2 << std::endl;
    std::cout << "Checksum: " << Sum2 << std::endl;
    std::cout << "Tree height: " << Height2 << std::endl;
    std::cout << "Sum of path lengths to each vertex: " << SumLengths2 << std::endl;
    std::cout << "Average height: " << SumLengths2 / Size2 << std::endl << std::endl;

    std::cout << "   n = 100    |     Size     |  ControlSum  |    Height    | AverageHeight" << std::endl;
    std::cout << "     SDP      |      " << Size1 << "     |     " << std::setw(5) << Sum1 << "    |      " << std::setw(3) << Height1 << "     |     " << std::setw(5) << float(SumLengths1) / float(Size1) << std::endl;
    std::cout << "     AVL      |      " << Size2 << "     |     " << std::setw(5) << Sum2 << "    |      " << std::setw(3) << Height2 << "     |     " << std::setw(5) << float(SumLengths2) / float(Size2) << std::endl;

    return 0;
}