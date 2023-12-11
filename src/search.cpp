#include<queue>
#include<cstdlib>
#include<iostream>
#include"search.h"

bool visited[graphSize] = {};
int statesEachMove[12];

void bfs(short* answer, int* numNodesVisited){
    std::queue<std::pair<Address, short>> q;
    Address solved;
    Address currentAddress;
    Address adjacentAddress;
    int currentId;
    int adjacentId;
    short lastMove;
    short state[16];
    *numNodesVisited = 0;
    solved = createNode(0, 0); // Create Solved State
    visited[0] = true;
    *answer = 0;
    q.push({solved, INT16_MIN});
    while (!q.empty()){
        currentAddress = q.front().first;
        lastMove = q.front().second;
        q.pop();
        currentId = currentAddress->id;
        intIntoScramble(currentId, state);
        for (short i=0; i<8; i++){
            if (i/2 == lastMove/2){
                continue;
            }
            adjacentId = doMove(state, i);
            if (visited[adjacentId]){
                continue;
            }
            visited[adjacentId] = true;
            adjacentAddress = createNode(adjacentId, currentAddress->distance + 1);
            q.push({adjacentAddress, i});
        }
        // std::cout << "Done traversing state with id: "<< currentAddress->id << " with number of moves "<< currentAddress->distance << "\n";
        statesEachMove[currentAddress->distance]++;
        *answer = std::max(*answer, currentAddress->distance);
        free(currentAddress);
        *numNodesVisited+=1;
    }
    for(int i=0; i<12; i++){
        std::cout << " Number of nodes with distance " << i << " is " << statesEachMove[i] << "\n";
    }
}