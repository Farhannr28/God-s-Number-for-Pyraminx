#include<bits/stdc++.h>
#include"search.h"

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    short godsNumber;
    int nodesVisited;
    std::cout << "__________                              .__                  ________           .__/\\       _______               ___.                  \n";
    std::cout << "\\______   \\___.__.____________    _____ |__| ____ ___  ___  /  _____/  ____   __| _)/_____  \\      \\  __ __  _____\\_ |__   ___________  \n";
    std::cout << " |     ___<   |  |\\_  __ \\__  \\  /     \\|  |/    \\  \\/  / /   \\  ___ /  _ \\ / __ |/  ___/  /   |   \\|  |  \\/     \\| __ \\_/ __ \\_  __ \\ \n";
    std::cout << " |    |    \\___  | |  | \\/ __ \\|  Y Y  \\  |   |  \\>    <  \\    \\_\\  (  <_> ) /_/ |\\___ \\  /    |    \\  |  /  Y Y  \\ \\_\\ \\  ___/|  | \\/ \n";
    std::cout << " |____|    / ____| |__|  (____  /__|_|  /__|___|  /__/\\_ \\  \\______  /\\____/\\____ /____  > \\____|__  /____/|__|_|  /___  /\\___  >__|    \n";
    std::cout << "           \\/                 \\/      \\/        \\/      \\/         \\/            \\/    \\/          \\/            \\/    \\/     \\/         \n";
    std::cout << "---------------------------------------------------------------------------------------------------------------------------------------\n";
    cout << "Welcome to the Pyraminx God's Number finder"<< "\n";
    cout << "This Project was created by Farhan Nafis Rayhan as an implementation for his paper"<< "\n";
    cout << "The program utilizes algorithms such as Breadth First Search & Hashing"<< "\n";
    cout << "Please wait while the program looking for the answer..."<< "\n";
    auto start = std::chrono::high_resolution_clock::now();
    bfs(&godsNumber, &nodesVisited);
    auto end = std::chrono::high_resolution_clock::now();
    cout << "All, Nodes had been visited, the exact number of Nodes visited is " << nodesVisited << "\n";
    cout << "The God's Number for Pyraminx, if we include the tips, is " << godsNumber + 4 << "\n";
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    cout << "time taken by the program is " << (double) duration.count()/1000 << " seconds." << "\n";
    return 0;
}