#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;


int getMax(int arr[],int size){
    int max = arr[0];
    for(int i = 1;i < size;i++){
        if(arr[i] > max){
            max = arr[i];
        }
    }

    return max;
}

int getMin(int arr[],int size){
    int min = arr[0];
    for(int i = 1; i < size;i++){
        if(arr[i] < min){
            min = arr[i];
        }
    }

    return min;
}

void counting_sort(int arr[],const int size){
    int max = getMax(arr,size);
    int min = getMin(arr,size);

    const int range = max - min + 1;

    int count[range];
    int output[size];

    for(int i = 0; i < range;i++){
        count[i] = 0;
    }

    for(int i = 0;i < size;i++){
        count[arr[i] - min]++;
    }

    for(int i = 1;i < range;i++){
        count[i] += count[i-1];
    }

    for(int i = size - 1;i >= 0;i--){
        output[count[arr[i]-min] - 1] = arr[i];
        count[arr[i] - min]--;
    }

    for(int i = 0; i < size;i++){
        arr[i] = output[i];
    }
}


    int main() {
        const int arr_size = 100000;
        int value = 100000;
        int arr[arr_size];

        for(int i = 0;i < arr_size;i++){
            arr[i] = value;
            value--;
        }




        auto start = high_resolution_clock::now();

        counting_sort(arr,arr_size );


        auto stop = high_resolution_clock::now();


        auto duration = duration_cast<microseconds>(stop - start);

        cout << "Time taken by function: " << duration.count() << " microseconds" << endl;



        return 0;
    }
