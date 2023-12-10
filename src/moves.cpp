#include "moves.h"

/*
#include<iostream>
using namespace std;
*/

void intIntoScramble(int num, short *arr){
    int i=0;
    int j=60;
    int k;
    int p;
    short six[6] = {0,1,2,3,4,5};
    bool used[6];
    while (i<4){
        arr[i] = num % 3;
        num = num / 3;
        i++;
    }
    k=0;
    while (i < 9){
        arr[i] = num & 1;
        if (num & 1){
            k++;
        }
        num = num >> 1;
        i++;
    }
    if(k & 1){
        arr[9] = 1;
    } else {
        arr[9] = 0;
    }
    i++;
    for (int i=0; i<6; i++){
        used[i] = false;
    }
    while(i < 14){
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
    for (int i=0; i<6; i++){
        used[i] = false;
    }
    bool switched = false;
    bool twoCycleValid = true;
    bool fourExist = false;
    i = 10;
    while (i < 16){
        j = 0;
        if (!used[i-10]){
            p = i-10;
            while (!used[p]){
                used[p] = true;
                p = arr[p+10];
                j++;
            }
        }
        if (j==2){
            twoCycleValid = !twoCycleValid;
        } else if (j == 4){
            fourExist = true;
        } if (j == 5){
            switched = true;
            break;
        } 
        i++;
    }
    if (!twoCycleValid && !fourExist){
        switched = true;
    }
    short temp;
    if (switched){
        temp = arr[15];
        arr[15] = arr[14];
        arr[14] = temp;
    }
    return;
}

int scrambleIntoInt(short* arr){
    int num;
    int permutation = 0;
    int i = 10;
    int p;
    int j;
    int k = 60;
    short six[6] = {0,1,2,3,4,5};
    bool used[6];
    for (int i=0; i<6; i++){
        used[i] = false;
    }
    while (i < 14){
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
    i = 8;
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
    num *= 32;
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
    short arr[16];
    for(int i=647839; i<933120; i++){
        intIntoScramble(i, arr);
        std::cout << i << " " << scrambleIntoInt(arr) << " ";
        for (int j=0; j<16; j++){
            std::cout << arr[j];
        }
        std::cout << "\n";
    }
    return 0;
}
*/