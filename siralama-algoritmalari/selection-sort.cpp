#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

void swap(int array[], int i, int j) {
    int tmp = array[i];
    array[i] = array[j];
    array[j] = tmp;
}


void selection_sort(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = i; j < size; j++) {
            bool is_j_LowerThan_i = arr[j] < arr[i];
            if (is_j_LowerThan_i) {
                swap(arr, i, j);
            }
        }
    }
}


    int main() {
        const int arr_size = 100;
        int value = 100000;
        int arr[arr_size];

        for(int i = 0;i < arr_size;i++){
            arr[i] = value;
            value--;
        }




        auto start = high_resolution_clock::now();

        selection_sort(arr,arr_size);


        auto stop = high_resolution_clock::now();


        auto duration = duration_cast<microseconds>(stop - start);

        cout << "Time taken by function: " << duration.count() << " microseconds" << endl;



        return 0;
    }
