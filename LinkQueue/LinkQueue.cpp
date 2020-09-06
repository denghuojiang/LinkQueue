#include <iostream>

using namespace std;
typedef int ElemType;
struct Node
{
    ElemType data;
    struct Node* next;
};
class LinkQueue
{
public:
	LinkQueue();
	~LinkQueue();
    bool IsEmpty();
    int EnQueue(ElemType e);
    ElemType DeQueue();
    int DestroyQueue();
private:
    Node* front;
    Node* rear;
    int Length;
};

LinkQueue::LinkQueue()
{
    this->Length = 0;
    this->front = new Node;
    this->front->data = NULL;
    this->front->next = NULL;
    this->rear = this->front;
}

LinkQueue::~LinkQueue()
{
    this->DestroyQueue();
}
bool LinkQueue::IsEmpty()
{
    if (this->front == this->rear)return true;
    return false;
}
int LinkQueue::EnQueue(ElemType e)
{
    Node* pnew = new Node;
    pnew->data = e;
    pnew->next = NULL;
    this->rear->next = pnew;
    this->rear = pnew;
    this->Length++;
    return 0;
}
ElemType LinkQueue::DeQueue()
{
    if (IsEmpty())return -1;
    Node* pdel = this->front->next;
    ElemType e = pdel->data;
    this->front->next = pdel->next;
    if (pdel == this->rear)this->rear = this->front;
    free(pdel);
    this->Length--;
    return e;
}
int LinkQueue::DestroyQueue()
{
    while (!IsEmpty()) {
        this->DeQueue();
    }
    return 0;
}
int main()
{
    std::cout << "Hello World!\n";
    LinkQueue q;
    q.EnQueue(1);
    q.EnQueue(2);
    q.EnQueue(3);
    cout << q.DeQueue() << endl;
    cout<<q.DeQueue() << endl;
    return 0;
}
