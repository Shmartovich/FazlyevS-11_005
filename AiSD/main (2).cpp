#include <iostream>
using namespace std;

struct Node
{
    int item = 0;
    Node* next = 0;
    Node* prev=0;
};

struct LinkedListDouble
{
    Node* pHead = 0;
    Node* pTail = 0;



    int add(int item)
    {
        if (!pHead) {
            Node* node = new Node;
            node->item = item;
            pHead = node;
            pTail = node;
            return 0;
        }
        else if(pTail == pHead){
            Node* node = new Node;
            node->item = item;
            node->prev = pHead;
            pHead->next = node;
            pTail = node;
            return 0;
        }
        else {
            Node* node = new Node;
            node->item = item;
            pTail->next = node;
            node->prev = pTail;
            pTail = node;
            return 0;
        }


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
    int get(int id) {
        if (id==1){
            return pHead->item;
        }
        else if (id>1){
            int count = 1;
            Node* temp = pHead;
            while (count < id) {
                temp = temp->next;
                count++;
            }
            return temp->item;

        }
        else{
            throw 1;
        }

    }
    int insertAt(int item, int id) {
        Node* temp = pHead;
        if(size()==0 && id == 1){
            return 0; ////////////////////////////////////////
        }
        if (id<1){
            cout << "id must be greater than or equal to 1" << endl;
            return 0;
        }
        if (id == 1) {
            Node* node = new Node;
            node->item = item;
            node->next = pHead;
            pHead->prev = node;
            pHead = node;

            return 0;
        }

        int count = 1;
        while(count<id-1){
            temp=temp->next;
            count++;
        }
        if(!temp->next){
            Node* node = new Node;
            node->item = item;
            node->prev = pTail;
            pTail->next = node;
            pTail = node;
            return 0;
        }
        Node* node = new Node;
        node->item = item;
        node->prev = temp;
        node->next = temp->next;
        temp->next = node;
        temp->next->prev = node;
        return 0;
    }
    int removeAt(int id){
        if (id == 1) {
            pHead = pHead->next;
            return 0;
        }
        else if (id<1){
            cout << "id must be greater than or equal to 1" << endl;
            return 0;
        }
        int count = 0;
        Node* temp = pHead;

        while (count < id-1) {
            temp = temp->next;
            count++;
        }
        if(!temp->next){
            pTail = temp->prev;
            pTail->next = nullptr;
            temp->prev = nullptr;
            return 0;
        }
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        return 0;
    }
};


int main() {

    LinkedListDouble* list = new LinkedListDouble;
    list->add(2);
    list->add(3);
    list->add(4);
    list->add(5);
    cout <<"get item "<< list->get(4) << endl;

    list->insertAt(6,5);


    int size = list->size();
    cout << "size= "<< size << endl;

    list->removeAt(5);

    size = list->size();
    cout << "size= "<< size << endl;

    for (int i=0; i< size;i++){
        cout<< list->get(i+1)<< endl;
    }

}