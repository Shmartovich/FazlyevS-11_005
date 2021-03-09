#include <iostream>
using namespace std;

struct Node
{
    int item = 0;
    Node* next = 0;
    Node* prev=0;
};

struct Queue
{
    Node* pHead = nullptr;
    Node* pTail = nullptr;



    int enqueue(int item)
    {
        if(!pHead) {
            pHead = new Node;
            pHead->item = item;
            pTail = pHead;
            return 0;
        }

        Node* temp = pTail;

        Node* node = new Node;
        node->item = item;
        node->prev= temp;
        temp->next = node;
        pTail = node;
        return 0;


    }
    int dequeue() {
        if (pHead) {
            Node *temp = pHead;
            pHead = pHead->next;
            return temp->item;
        }
        return -1;
    }


    int size() {
        int size = 0;
        if (!pHead) {
            return size;
        }
        else {
            Node* temp = pHead;
            while (temp->next) {
                temp = temp->next;
                size++;
            }
            return size+1;
        }
    }
};

int main(){
    Queue* queue = new Queue;
    queue->enqueue(1);
    queue->enqueue(2);
    queue->enqueue(3);

    cout << queue->dequeue();
    cout << queue->dequeue();
    cout << queue->dequeue();
    cout << queue->dequeue();

    return 0;
}