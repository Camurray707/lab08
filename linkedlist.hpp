//CHRISTOPHER MURRAY Lab08 CS215
#include <iostream>
using namespace std;

struct Node {
    int value;
    Node* next;
};

class LinkedList {

    public:
        //Constructor: sets first and last to nullptr, size  to 0;
        LinkedList();

        //Copy Constructor: takes another LinkedList as its parameter
        LinkedList(const LinkedList& other);

        //Destructor
        ~LinkedList();

        //Inserts an integer to the first node of a linked list, return true if successful
        bool InsertFirst(int v);

        //Inserts an integer to the last node of a linked list, return true if successful
        bool InsertLast(int v);

        //Deletes first node and returns true if successful
        bool DeleteFirst();

        //Deletes last node and returns true if successful
        bool DeleteLast();

        //returns size of LinkedList
        int Size() const { return size; }

        //assignment operator, takes other LinkedList that isn't the same as this
        LinkedList& operator=(const LinkedList& other);

        //Equality operator that compares this and others nodes and returns true if they are all the same
        bool operator==(const LinkedList& other) const;

        //Output operator that takes an out stream and a LinkedList
        friend ostream& operator<< (ostream& out, const LinkedList& LL);

    private:
        Node* first;
        Node* last;
        int size;
};
