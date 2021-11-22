#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;


void merge(int dizi[],const int l,const int m,int const r){
    const int left_array_size = m - l + 1;
    const int right_array_size = r - m;

    int L[left_array_size];
    int R[right_array_size];

    for(int i = 0; i < left_array_size;i++){
        L[i] = dizi[l+i];
    }
    for(int j = 0; j < right_array_size;j++){
        R[j] = dizi[m+j+1];
    }


    int i = 0;
    int j = 0;

    int k = l;


    while(i < left_array_size && j < right_array_size){
        if(L[i] <= R[j]){
            dizi[k] = L[i];
            i++;
        }else{
            dizi[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < left_array_size){
        dizi[k] = L[i];
        i++;
        k++;
    }

    while(j < right_array_size){
        dizi[k] = R[j];
        j++;
        k++;
    }

}

void mergeSort(int arr[], const int l, const int r){

    if(l >= r){
        return;
    }

    int m = l + (r - l) / 2;

    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);
    merge(arr, l, m, r);



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

        mergeSort(arr,0,arr_size-1);


        auto stop = high_resolution_clock::now();


        auto duration = duration_cast<microseconds>(stop - start);

        cout << "Time taken by function: " << duration.count() << " microseconds" << endl;



        return 0;
    }
