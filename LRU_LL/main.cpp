#include "LinkList.h"
#include "LRU.hpp"
#include <iostream>
void testingLinkedLRU();
int main() {
    testingLinkedLRU();
    return 0;
}
void testingLinkedLRU(){
LRU lru;
std::cout<<lru;

lru.insert(1);
std::cout<<lru;

lru.insert(2);
std::cout<<lru;

lru.insert(3);
std::cout<<lru;

lru.insert(4);
std::cout<<lru;

lru.insert(5);
std::cout<<lru;

lru.insert(6);
std::cout<<lru;

lru.access(3);
std::cout<<lru;

lru.insert(-5);
std::cout<<lru;

lru.insert(5);
std::cout<<lru;

lru.insert(50);
std::cout<<lru;

lru.access(5);
std::cout<<lru;

lru.access(1);
std::cout<<lru;

lru.access(-5);
std::cout<<lru;

}
