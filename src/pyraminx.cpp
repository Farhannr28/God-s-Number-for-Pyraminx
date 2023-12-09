#include"pyraminx.h"
#include <cstdlib>
#include <iostream>

Address createNode(int newId){
    Address p = (Address) malloc(sizeof(Node));
    if (p != NULL){
        p->id = newId;
        p->visited = false;
    } else {
        std::cout << "Memory allocation failed" << "\n";
    }
    return p;
}

void initiatePyraminx(Node** p, int batch){
    Address a;
    for(int i=0; i<treeSize; i++){
        a = createNode(i*81 + batch);
        p[i] = a;
    }
    a = createNode(0);
    p[treeSize] = a;
    std::cout << "All states are created" << "\n";
}