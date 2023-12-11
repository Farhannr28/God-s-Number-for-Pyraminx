#include"pyraminx.h"
#include <cstdlib>
#include <iostream>

Address createNode(int newId, short newDistance){
    Address p = (Address) malloc(sizeof(Node));
    if (p != NULL){
        p->id = newId;
        p->distance = newDistance;
    } else {
        std::cout << "Memory allocation failed for state with id " << newId << "\n";
    }
    return p;
}