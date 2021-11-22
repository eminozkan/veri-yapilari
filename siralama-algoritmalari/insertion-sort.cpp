#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;


void insertion_sort(int arr[], int size) {
    for (int i = 1; i < size; i++) {
        int value = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > value) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = value;
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

        insertion_sort(arr,arr_size);


        auto stop = high_resolution_clock::now();


        auto duration = duration_cast<microseconds>(stop - start);

        cout << "Time taken by function: " << duration.count() << " microseconds" << endl;



        return 0;
    }
