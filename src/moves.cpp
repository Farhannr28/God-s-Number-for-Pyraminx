#include "moves.h"

/*
#include<iostream>
using namespace std;
*/

void intIntoScramble(int num, short *arr){
    int i=0;
    int j=120;
    int k;
    int p;
    while (i<4){
        arr[i] = num % 3;
        num = num / 3;
        i++;
    }
    while (i < 10){
        arr[i] = num & 1;
        num = num >> 1;
        i++;
    }
    short six[6] = {0,1,2,3,4,5};
    bool used[6];
    for (int i=0; i<6; i++){
        used[i] = false;
    }
    while(i < 15){
        k = num/j;
        p = 0;
        while (k > -1){
            if (!used[p]){
                k--;
            }
            p++;
        }
        p--;
        arr[i] = six[p];
        used[p] = true;
        num %= j;
        j /= (15-i);
        i++;
    }
    while(i < 16){
        p = 0;
        while (used[p]){
            p++;
        }
        arr[i] = six[p];
        used[p] = true;
        i++;
    }
    return;
}

int scrambleIntoInt(short* arr){
    int num;
    int permutation = 0;
    int i = 10;
    int p;
    int j;
    int k = 120;
    short six[6] = {0,1,2,3,4,5};
    bool used[6];
    for (int i=0; i<6; i++){
        used[i] = false;
    }
    while (i < 15){
        j = 0;
        p = 0;
        while(six[p] != arr[i]){
            if (!used[p]){
                j++;
            }
            p++;
        }
        used[p] = true;
        permutation += (k * j);
        k /= (15-i);
        i++;
    }
    int orientation = 0;
    i = 9;
    while(i > 3){
        orientation = orientation << 1;
        orientation += arr[i];
        i--;
    }
    int center = 0;
    while(i > -1){
        center *= 3;
        center += arr[i];
        i--;
    }
    num = permutation;
    num *= 64;
    num += orientation;
    num *= 81;
    num += center;
    return num;
}

// moveList = {U, U', R, R', B, B', L, L'}

int doMove(short *state, short moveNum){
    short result[16];
    short temp[6];
    int i = 0;
    while(i < 4){
        result[i] = state[i];
        i++;
    }
    i=moveNum/2;
    if (moveNum & 1){
        result[i] = (state[i]+2)%3;
    } else {
        result[i] = (state[i]+1)%3;
    }
    i = 4;
    while(i < 10){
        temp[i-4] = (state[i] + orientationUpdate[moveNum][i-4]) % 2;
        i++;
    }
    /*
    for (int j=0; j<6; j++){
        std::cout << temp[j];
    }
    cout << " ";
    */
    int p = 0;
    while(i < 16){
        if (permutationTransition[moveNum][i-10] != p){
            result[i] = state[permutationTransition[moveNum][i-10]+10];
            result[i-6] = temp[permutationTransition[moveNum][i-10]];
        } else {
            result[i] = state[i];
            result[i-6] = temp[i-10];
        }
        p++;
        i++;
    }
    /*
    for (int j=0; j<16; j++){
        std::cout << state[j];
    }
    cout << " ";
    for (int j=0; j<16; j++){
        std::cout << result[j];
    }
    cout << " ";
    */
    return scrambleIntoInt(result);
}

/*
int main(){
    int n;
    int temp;
    std::cin >> n;
    short arr[16];
    intIntoScramble(n, arr);
    std::cout << scrambleIntoInt(arr) << "\n";
    for(short i=0; i<8; i++){
        temp = doMove(arr, i);
        std::cout << temp << " ";
        intIntoScramble(temp, arr);
        for (int j=0; j<16; j++){
            std::cout << arr[j];
        }
        std::cout << "\n";
    }
    return 0;
}
*/