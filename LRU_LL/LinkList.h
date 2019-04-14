#ifndef LINKLIST_LINKLIST_H
#define LINKLIST_LINKLIST_H

#include <vector>
#include "Link.h"

class LinkList{

protected:
    Link* head = nullptr;

    Link* tail = nullptr;

    std::vector<void* >linksAddresses;
public:

    virtual ~LinkList();

    void insert(int key);

    void push_back(int key);

    void push_front(int key);

    bool deleteKey(int key);

    bool findKey(int key);

    void insert_sorted(int key);

    friend void operator<<(std::ostream& os, const LinkList &linkList);

    void getLinksAddresses();

    void printReverse() const;

    void do_reverse();

    Link* delete_at_pos(int n);
};

#endif //LINKLIST_LINKLIST_H


