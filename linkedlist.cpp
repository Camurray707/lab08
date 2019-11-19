//CHRISTOPHER MURRAY Lab08 CS215
#include <cstddef> // needed for NULL on newer compilers
#include "linkedlist.hpp"

LinkedList::LinkedList() {
    first = nullptr;
    last = first;
    size = 0;
}

LinkedList::~LinkedList() {
    while (this->first != nullptr) {
        this->DeleteFirst();
    }
}


LinkedList::LinkedList(const LinkedList& other) {
    this->size = other.size;
    this->first = nullptr;
    this->last = this->first;

    Node* temp = other.first;
    Node* newList = new Node [this->size];


    if(other.size == 0) {}
    else if (other.size == 1) {
        newList->value = other.first->value;
    }
    else {
        for (int i = 0; i < this->size; i++) {
            newList->value = other.first->value;

            newList = newList->next;
            temp = temp->next;
        }

    }
}

LinkedList& LinkedList::operator=(const LinkedList& other) {
    if (this == &other) {return *this;}
    else {
        for (int i = 0; i < this->size; i++) {
            this->DeleteFirst();
        }

        Node* temp = other.first;

        if(other.size == 0) {return *this;}
        else if (other.size == 1) {
            this->first->value = other.first->value;
        }
        else {
            for (int i = 0; i < other.size; i++) {
                this->InsertLast(temp->value);
                temp = temp->next;
            }
        }
    }
    return *this;
}

bool LinkedList::operator==(const LinkedList& other) const {
    if(this->size != other.size) {return false;}
    else {
        Node* temp1 = this->first;
        Node* temp2 = other.first;
        for (int i = 0; i < this->size; i++) {
            if (this->first->value != other.first->value) {return false;}
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
    }
    return true;
}

ostream& operator<< (ostream& out, const LinkedList& LL) {

    if (LL.size == 0) {return out;}
    else {
        Node* curr = LL.first;

        for (int i = 0; i < LL.size; i++) {
            out << curr->value << " ";
            curr = curr->next;
        }
    }
    return out;
}

bool LinkedList::InsertFirst(int v) {

    Node* atBeg = new Node;
    atBeg->value = v;

    if(atBeg == nullptr) {return false;}
    else if(this->size == 0) {
        this->first = atBeg;
        this->last = atBeg;
        this->first->next = nullptr;
        this->size++;
    }
    else {
        atBeg->next = this->first;
        this->first = atBeg;
        this->size++;
    }
    return true;
}

bool LinkedList::InsertLast(int v) {

    Node* atEnd = new Node;
    atEnd->value = v;
    atEnd->next = nullptr;

    if (atEnd == nullptr) {return false;}
    else if (this->size == 0) {
        this->first = atEnd;
        this->last = atEnd;
        this->size++;
    }
    else {
        this->last->next = atEnd;
        this->last = atEnd;
        this->size++;
    }

    return true;
}

bool LinkedList::DeleteFirst() {

    if (this->size == 0) {return false;}
    else if (this->size == 1) {
        delete this->first;
        this->first = nullptr;
        this->last = nullptr;
        this->size--;
        return true;
    }
    else {
        Node *temp = this->first;
        this->first = this->first->next;
        delete temp;
        this->size--;
        return true;

    }
}

bool LinkedList::DeleteLast() {

    if (this->size == 0) {return false;}
    else if (this->size == 1) {
        delete this->first;
        this->first = nullptr;
        this->last = nullptr;
        this->size--;
        return true;
    }
    else {
        Node* temp = this->first;

        for (int i = 0; i < this->size - 2; ++i) {
            temp = temp->next;
        }

        delete this->last;
        this->last = temp;
        this->last->next = nullptr;
        this->size--;
        return true;

    }
}


