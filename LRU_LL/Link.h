#ifndef LINKLIST_LINK_H
#define LINKLIST_LINK_H

#include <iosfwd>

class Link{
private:
    int value;
    Link* next = nullptr;
public:
    Link();

    explicit Link(int key);

    int getValue() const;

    void setValue(int value);

    Link *getNext() const;

    void setNext(Link *next);

    friend void operator<<(std::ostream& os, const Link &link);
};

#endif //LINKLIST_LINK_H
