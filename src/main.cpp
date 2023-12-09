#include<bits/stdc++.h>
#include"moves.h"

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    short godsNumber = 0;
    time_t start, end;
    time(&start);
    Node* pyraminx[treeSize+1];
    initiatePyraminx(pyraminx, 0);

    cout << "The God's Number for Pyraminx is " << godsNumber << "\n";
    cout << "time taken by the program is " << double(end - start) << "\n";
    time(&end);
    return 0;
}