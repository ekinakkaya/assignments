#include <iostream>
#include <queue>
#include <ctime>

#include "./include/d_node.h"
#include "./include/d_nodel.h"

using namespace std;



template <typename T>
void insertAfter(node<T> *curr, const T &item) {
    node<T> *newnode = new node<T>(), *nextnode;

    if (curr->next != NULL) nextnode = curr->next;
    else                    nextnode = NULL;

    newnode->nodeValue = item;

    curr->next = newnode;
    if (nextnode != NULL)
        newnode->next = nextnode;
}



template <typename T>
node<T> *findInLL(node<T> *curr, const T item) {
    node<T> *mover = curr;

    do {
        cout << ".";
        if (mover->nodeValue == item)
            return mover;
        mover = mover->next;
    } while (mover->next != NULL);

    return mover;
}



template <typename T>
void eraseAll(node<T> *&front, const T &target) {
    node<T>* curr = front, * prev = NULL, * deletedNode;
    while (curr != NULL) {
        if (curr->nodeValue == target) {
            deletedNode = curr;
            if (prev == NULL) {
                front = front->next;
                curr = front;
            }
            else {
                prev->next = curr->next;
                curr = prev->next;
            }
            delete deletedNode;
        }
        else {
            prev = curr;
            curr = curr->next;
        }
    }    
}



template <typename T>
node<T> *copy(node<T> *front) {
    node<T> *newnode = new node<T> (front->nodeValue), *head = front, *next;
    node<T> *savehead = newnode;

    do {
        head = head->next;
        next = new node<T> (head->nodeValue);

        newnode->next = next;
        newnode = newnode->next;
    } while (head->next != NULL);


    return savehead;
}




int main() {
    srand(time(0));


    int deger_adet, tempint;

    node<int> *head = new node<int>(), *mover;
    mover = head;

    queue<int> q, tempqueue;

    int dugum_deger;



    cout << "Adet giriniz: ";
    cin >> deger_adet;

    for (int i = 0; i < deger_adet; i++) {
        tempint = rand() % 150 + 1;

        q.push(tempint);
    }

    cout << "Rastgele değerlerden oluşturulan kuyruk: ";
    tempqueue = q;
    while (!tempqueue.empty()) {
        cout << tempqueue.front() << " ";
        tempqueue.pop();
    }
    cout << "\n";


    while (!q.empty()) {
        mover->nodeValue = q.front();

        if (q.size() > 1) {
            mover->next = new node<int>();
            mover = mover->next;
        }

        q.pop();
    }

    cout << "Kuyruktan oluşturulan linked list: "; writeLinkedList(head, " ");
    cout << "\n";




    mover = head;
    cout << "Düğüm değeri giriniz: ";
    cin >> dugum_deger;

    cout << "Klavyeden bir sayı giriniz: ";
    cin >> tempint;

    /* find node
     * add node after
     */

    /*
    do {
        if (mover->nodeValue == dugum_deger) {
            insertAfter(mover, tempint);
            flag_added_to_ll = true;
        }
        mover = mover->next;
    } while (mover->next != NULL);

    if (!flag_added_to_ll) {
        insertAfter(mover, tempint);
    }
    */

    insertAfter(findInLL(head, dugum_deger), tempint);

    

    
    cout << "Linked list yeniden yazdırılıyor: "; writeLinkedList(head, " ");
    cout << "\n";



    cout << "Silinecek değer: ";
    cin >> tempint;

    eraseAll(head, tempint);

    cout << "Linked list yeniden yazdırılıyor: "; writeLinkedList(head, " ");
    cout << "\n";


    node<int> *n = copy(head);
    
    cout << "Kopya linked list yazdırılıyor: "; writeLinkedList(n, " ");
    cout << "\n";
    


    return 0;
}



