#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <vector>
using namespace std;

void Merge(int* l_start, int* l_finish, int* r_start, int* r_finish, vector<int> final_array) {
    while(l_start <= l_finish && r_start <= r_finish) {
        if (*l_start < *r_start) {
            final_array.push_back(*l_start);
            l_start++;
        }
        else {
            final_array.push_back(*r_start);
            r_start++;
        }
    }

    while(l_start <= l_finish && *r_start == 0) {
        final_array.push_back(*l_start);
        l_start++;
        for(int i=0; i<final_array.size(); i++)
            cout << final_array[i];
        cout << endl;
    }
    while(r_start <= r_finish && *l_start == 0) {
        final_array.push_back(*r_start);
        r_start++;
    }
}

void MergeSort(int array[], int* start, int* finish) {
    if((finish - start + 1) <= 1) {
        return;
    }
    else if((finish - start + 1) == 2) {
        if(*finish < *start) {
            int temp = *start;
            *start = *finish;
            *finish = temp;
        }
        return;
    }
    else {
        int* middle;

        if((finish - start) % 2 == 0){
            middle = array[finish - start]/2 + start;
        }
        else {
            middle = array[finish - start]/2 + start + 1;
        }
        
        MergeSort(array, start, middle); // left array
        MergeSort(array, middle + 1, finish); // right array

        vector<int> final_array;
        Merge(start, middle, middle + 1, finish, final_array);

        int* p_array = array;
        for(int i=0; i<(finish - start + 1); i++) {
            *p_array = final_array[i];
            p_array++;
        }
    }
}

main() {
    int length;
    cin >> length;
    int arr[length];

    for(int i=0; i<length; i++) {
        cin >> arr[i];
    }

    MergeSort(arr, &arr[0], &arr[length - 1]);

    for(int i=0; i<length; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}