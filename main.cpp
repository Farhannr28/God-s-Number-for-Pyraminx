#include<bits/stdc++.h>
using namespace std;

/*  
    360 -> 9 bits
    2 ^ 6 -> 6 bits
    4 ^ 8 = 2 ^ 16 -> 16 bits
    total = 31 bits
*/

void intIntoScramble(int num, short *arr){
    int i=0;
    int j=120;
    int k;
    int p;
    while (i<8){
        arr[i] = num % 3;
        num = num / 3;
        i++;
    }
    while (i < 14){
        arr[i] = num & 1;
        num = num >> 1;
        i++;
    }
    short six[6] = {0,1,2,3,4,5};
    bool used[6];
    for (int i=0; i<6; i++){
        used[i] = false;
    }
    while(i < 19){
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
        j /= (19-i);
        i++;
    }
    while(i < 20){
        p = 0;
        while (used[p]){
            p++;
        }
        arr[i] = six[p];
        used[p] = true;
        i++;
    }
    /*
    for (int i=0; i<6; i++){
        used[i] = false;
    }
    bool switched = false;
    bool twoCycleValid = true;
    i = 14;
    while (i < 20){
        j = 0;
        if (!used[i-14]){
            p = i;
            while (!used[p-14]){
                used[p-14] = true;
                p = arr[p+14];
                j++;
            }
        }
        if (j == 4 || j == 5){
            switched = true;
            break;
        } else if (j==2){
            twoCycleValid = !twoCycleValid;
        } else {
            i++;
        }
    }
    if (!twoCycleValid){
        switched = true;
    }
    short temp;
    if (switched){
        temp = arr[18];
        arr[18] = arr[19];
        arr[19] = temp;
    }
    */
    return;
}

void scrambleIntoInt(short* arr, int* num){
    int permutation = 0;
    int i = 14;
    int p;
    int j;
    int k = 120;
    short six[6] = {0,1,2,3,4,5};
    bool used[6];
    for (int i=0; i<6; i++){
        used[i] = false;
    }
    while (i < 19){
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
        k /= (19-i);
        i++;
    }
    int orientation = 0;
    i = 13;
    while(i > 7){
        orientation = orientation << 1;
        orientation += arr[i];
        i--;
    }
    int centerTip = 0;
    while(i > -1){
        centerTip *= 3;
        centerTip += arr[i];
        i--;
    }
    // cout << permutation << " " << orientation << " " << centerTip << "\n";
    *num = permutation;
    *num *= 64;
    *num += orientation;
    *num *= 6561;
    *num += centerTip;
    return;
}

//302330879

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    time_t start, end;
    int n;
    int res;
    short a[20];
    time(&start);
    for (int i=0; i<720; i++){
        for (int j=0; j<419904; j++){
            intIntoScramble(i * 419904 + j, a);
            scrambleIntoInt(a, &res);
            /*
            for (int i=0; i<20; i++){
                cout << a[i];
            }
            cout << "\n";
            */
        }
        cout << i << "\n";
    }
    time(&end);
    /*
    for (int i=0; i<20; i++){
        cout << a[i] << " ";
    }
    cout << "\n";
    cout << res << "\n";
    */
    cout << "time taken by the program is " << double(end - start) << "\n";
    return 0;
}