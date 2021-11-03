#include <iostream>
#include <ctime>
#include <vector>

#include "Dosyalar/include/include/d_sort.h"
#include "Dosyalar/include/include/d_timer.h"

#define ARRSIZ 10000

using namespace std;


template <typename T>
void exchangeSort(vector<T> &v) {
    int i, j, temp;
    int n = v.size();

    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (v[i] > v[j]) {
                temp = v[i];
                v[i] = v[j];
                v[j] = temp;
            }
        }
    }
}


template <typename T>
void bubbleSort(vector<T> &v) {
    int i, j, temp, pass = 0;
    int n = v.size();

    for (i = 0; i < n; i++) {
        for (j = i; j < n; j++) {
            if (v[i] > v[j]) {
                temp = v[i];
                v[i] = v[j];
                v[j] = temp;
            }
        }
    }
}



int main() {

    /* assign random integers to an array of 10000 ints */
    srand(time(NULL));

    int arr[ARRSIZ];
    for (int i = 0; i < ARRSIZ; i++)
        arr[i] = rand() % 50000 + 1;


    /* create vector */
    vector<int> unsortedvec(arr, arr + ARRSIZ);
    vector<int> vec(arr, arr + ARRSIZ);

    cout << vec[0] << " " << vec[1] << " " << vec[2] << "\n";



    /* test sorting algorithms */

    // debug string
    //cout << vec[0] << " " << vec[1] << " " << vec[2] << "\n";
    
    timer t;

    /* start the timer, copy the unsorted vector to vec, call sort, stop timer and print sorting time */
    vec = unsortedvec;
    t.start();
    selectionSort<int>(vec);
    t.stop();
    cout << "selection sort: " << t.time() << "\n";

    
    vec = unsortedvec;
    t.start();
    exchangeSort<int>(vec);
    t.stop();
    cout << "exchange sort : " << t.time() << "\n";

    
    vec = unsortedvec;
    t.start();
    quicksort<int>(vec, 0, vec.size());
    t.stop();
    cout << "quick sort    : " << t.time() << "\n";


    vec = unsortedvec;
    t.start();
    mergeSort<int>(vec, 0, vec.size());
    t.stop();
    cout << "merge sort    : " << t.time() << "\n";


    vec = unsortedvec;
    t.start();
    bubbleSort<int>(vec);
    t.stop();
    cout << "bubble sort   : " << t.time() << "\n";


    return 0;
}
