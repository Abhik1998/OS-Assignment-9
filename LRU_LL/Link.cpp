#include "Link.h"

#include <iostream>

Link::Link()  {
}

Link::Link(int key) {
    this->setValue(key);
}

int Link::getValue() const {
    return value;
}

void Link::setValue(int value) {
    Link::value = value;
}


Link *Link::getNext() const {
    return next;
}

void Link::setNext(Link *next) {
    Link::next = next;
}

void operator<<(std::ostream& os, const Link &link){
    os<<link.getValue()<<" ";
}
