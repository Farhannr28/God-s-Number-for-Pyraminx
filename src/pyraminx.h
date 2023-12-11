#ifndef PYRAMINX_H
#define PYRAMINX_H

const int graphSize = 933120;

typedef struct node* Address;
typedef struct node{
    int id;
    short distance;
}Node;

Address createNode(int newId, short newDistance);

#endif