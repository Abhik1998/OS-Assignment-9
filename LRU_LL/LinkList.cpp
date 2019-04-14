#include <iostream>
#include "LinkList.h"

void LinkList::insert(int key) {
    push_back(key);
}

void LinkList::push_front(int key) {

    Link *newNode = new Link(key);
    if (head == nullptr) {
        head = newNode;
        tail = newNode;
    } else {
        newNode->setNext(head);
        head = newNode;
    }
    //std::cout << "Inserted " << key <<" address :  "<<&newNode << " at front\n";

}

void LinkList::push_back(int key) {
    Link *newNode = new Link(key);
    if (tail == nullptr) {
        head = newNode;
        tail = newNode;
    } else {
        tail->setNext(newNode);
        tail = newNode;
    }
    //std::cout << "Inserted " << key << " at back\n";

}

bool LinkList::deleteKey(int key) {
    Link *curr = head;
    Link *prev = head;

    if (head != nullptr && head->getValue() == key) {
        Link *temp = head;
        head = head->getNext();
        if(head == nullptr)
           tail = nullptr;
        delete temp;
        std::cout << "Deleted " << key << "\n";
        return true;
    }

    while (curr != nullptr && curr->getValue() != key) {
        prev = curr;
        curr = curr->getNext();
    }

    if (curr == nullptr) {
        std::cout << "To delete Key " << key << " doesn't exist\n";
        return false;
    } else {
        prev->setNext(curr->getNext());
        delete curr;
        std::cout << "Deleted " << key << "\n";
        return true;
    }
}

bool LinkList::findKey(int key) {
    Link *current = head;
    while (current != nullptr && current->getValue() != key)
        current = current->getNext();
    return current != nullptr;
}

LinkList::~LinkList() {
    Link *next;
    Link *curr = head;
    while (curr != nullptr) {
        next = curr->getNext();
        delete curr;
        curr = next;
    }
    //std::cout<<"Memory freed\n";
}

void operator<<(std::ostream &os, const LinkList &linkList) {
    Link *curr = linkList.head;
    os << "List is : ";
    while (curr != nullptr) {
        os << *curr;
        curr = curr->getNext();
    }
    os << '\n';
}

void LinkList::insert_sorted(int key) {
    //TODO
}

void LinkList::getLinksAddresses() {
    while (head != nullptr){
        linksAddresses.push_back(&head);
        std::cout<<&head<<" "<<head->getValue()<<"\n";
        head = head->getNext();
    }
}

void reverse(Link* head){
    if(head!= nullptr){
        reverse(head->getNext());
        std::cout<<head->getValue()<<" ";
    }
}

void LinkList::printReverse() const {
    reverse(head);
    std::cout<<"\n";
}

void LinkList::do_reverse() {

    Link* prev = nullptr;
    Link* curr = head;
    Link* next = curr->getNext();
    while (curr){

    }

}

Link* LinkList::delete_at_pos(int n)
{
    if(n <=0)
        return head;
    int count  = 1;
    Link* curr = head, *prev = nullptr;;
    while(curr!=nullptr){
        if(count == n)
            break;
        prev = curr;
        curr = curr->getNext();
        count++;
    }
    if(curr!=nullptr){
        Link* temp = curr;
        if(curr == head){
            head = head->getNext();
        }else{
            prev->setNext(curr->getNext());
            }
        delete temp;
    }
    return head;
}
