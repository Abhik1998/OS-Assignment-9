#ifndef LINKLIST_LRU_HPP
#define LINKLIST_LRU_HPP

#include <iostream>
#include "LinkList.h"
class LRU : public LinkList{
private:
    const int MAX = 4;
    int max_len  = 0;
    Link* findPage(int key){
        Link *current = LinkList::head;
        while (current != nullptr && current->getValue() != key)
            current = current->getNext();
        return current;
    }
public:
    void insert(int key) override{
        if(MAX > 0) {
            Link *page = findPage(key);
            if (page != nullptr) {
                access(page->getValue());
                return;
            }

            if (max_len >= MAX) {
                deleteKey(LinkList::head->getValue());
                max_len--;
            }
            push_back(key);
            max_len++;
        }
    }

    bool access(int key){
        Link *current = findPage(key);
        if(current == nullptr)
            return false;
        else{
            int val = current->getValue();
            deleteKey(val);
            max_len--;
            insert(val);
            return true;
        }
    }
};

#endif //LINKLIST_LRU_HPP
