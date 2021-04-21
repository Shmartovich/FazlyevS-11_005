#include <iostream>
using namespace std;

const int MAX_NAME = 256;
const int TABLE_SIZE = 10;

struct person {
    char name [MAX_NAME];
    person * next;
};

person * hash_table[TABLE_SIZE];

void init_hash_table(){
    for (int i=0;i< TABLE_SIZE;i++){
        hash_table[i] = nullptr;
    }
}

int hash_this(char* name){
    int length = strnlen(name,MAX_NAME); //определяет длину строки фиксированной длины
    int hash_value=0;
    for(int i=0; i<length;i++){
        hash_value+=name[i];
        hash_value = (hash_value * name[i]) % TABLE_SIZE;
    }
    return hash_value;
}

void print_table(){
    for(int i=0; i< TABLE_SIZE; i++){
        if(hash_table[i] == nullptr){
            cout<< i << " -- " << "\n";
        }
        else{
            cout<< i << " ";
            person *temp = hash_table[i];
            while(temp != nullptr){

                cout << temp->name <<  " -- ";
                temp= temp->next;
            }
            cout << "\n";
        }
    }
}


bool hash_table_insert(person *p){
    if(p == nullptr){
        return false;
    }
    int index = hash_this(p->name);

    p->next = hash_table[index];
    hash_table[index] = p;
    return true;
}

person * hash_table_remove(char * name){
    int index = hash_this(name);
    person * temp = hash_table[index];
    person *prev = nullptr;
    while(temp!=nullptr &&
        strncmp(hash_table[index]->name, name, TABLE_SIZE) != 0){
        prev = temp;
        temp = temp->next;
    }
    if(temp == nullptr){
        return nullptr;
    }
    if(prev == nullptr){
        //delete head
        hash_table[index] = temp->next;
    }
    else{
        prev->next = temp ->next;
    }
    return temp;
}

person *hash_table_search (char* name){
    int index = hash_this(name);
    person * temp = hash_table[index];
    while (temp!=nullptr &&
    strncmp(hash_table[index]->name, name, TABLE_SIZE) != 0){
        temp = temp->next;
    }
    return temp;
}


int main() {
    init_hash_table();
    person jacob;
    strcpy(jacob.name,"Jacob");

    person jane;
    strcpy(jane.name,"Jane");

    person kate;
    strcpy(kate.name,"Kate");

    person eve;
    strcpy(eve.name,"Eve");

    hash_table_insert(&jane);
    hash_table_insert(&kate);

    hash_table_insert(&jacob);
    hash_table_insert(&eve);

    hash_table_remove("Eve");

    print_table();

    person* temp = hash_table_search("Eve");
    person* temp2 = hash_table_search("Jacob");

    //нашли ли Eve и Jacob
    if(temp == nullptr){
        cout<< " eve not found" << "\n";
    }
    else{
        cout<< temp->name;
    }
    if(temp2 == nullptr){
        cout<< "not found";
    }
    else{
        cout<< temp2->name;
    }
    //
    return 0;
}
