#ifndef PYRAMINX_H
#define PYRAMINX_H

const int treeSize = 46080;

typedef struct node* Address;
typedef struct node{
    int outDegree[8];
    int id;
    bool visited;
}Node;

Address createNode(int newId);

void initiatePyraminx(Node** p, int batch);

#endif