#include <iostream>
using namespace std;



struct Node{
    int item;
    Node* next = nullptr;
};

struct SortedList{
    int max = INT_MIN;
    int min = INT_MAX;


    Node* pHead = nullptr;
    Node* pTail = nullptr;


    int add(int addItem){
        if(!pHead){
            pHead = new Node;
            pHead->item = addItem;
            pTail = pHead;
            min = addItem;
            max = addItem;
            return 0;
        }

        Node* node = new Node;
        node->item = addItem;

        if (addItem>max){
            pTail->next = node;
            pTail = node;
            max = addItem;
            return 0;
        }
        else if (addItem < min){
            node->next = pHead;
            pHead = node;
            min = addItem;
            return 0;
        }

        Node* temp = pHead;

        while (temp->next){
            if(addItem == temp->item){
                return 0;
            }
            if(addItem<=temp->next->item){
                temp->next = node;
                node->next = temp->next;
                return 0;
            }
            temp= temp->next;
        }

    }


    int get(int id){
        if (id<1){
            throw 1;
        }
        Node* temp = pHead;
        int count =0;
        while(count<id-1){
            temp=temp->next;
            count++;
        }
        return temp->item;
    }
    int remove(int id){
        if (id<1){
            throw 1;
        }
        else if (id == 1){
            pHead = pHead->next;
            return 0;
        }

        Node* temp = pHead;
        int count =0;
        while(count<id-2){
            temp=temp->next;
            count++;
        }
        if (temp->next->item == max){
            pTail = temp;
        }
        temp->next = temp->next->next;
        temp->next->next = nullptr;
        return 0;
    }
};

int main() {
    SortedList* list = new SortedList;
    list->add(5);
    list->add(1);
    list->add(1);
    list->add(1);
    list->add(8);
    cout<<list->get(1) << endl;
    list -> remove(2);
    cout<<list->get(2)<< endl;

    return 0;
}
