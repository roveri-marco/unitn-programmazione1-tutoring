#include <cstdlib>
#include <iostream>
#include <utility>

using namespace std;

int main(int argc, char *argv[]) {
    if (argc <= 2) {
        cout << "Numero di argomenti errato" << endl;
        return 1;
    }

    int N = atoi(argv[1]);
    float *arr = new float[N];
    for (int i = 0; i < N; i++) {
        arr[i] = atof(argv[i + 2]);
    }

    // ordering
    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++) {
            if (arr[i] > arr[j]) {
                swap(arr[i], arr[j]);
            }
        }
    }

    for (int i = 0; i < N; i++) {
        cout << arr[i] << ' ';
    }
    cout << endl;

    delete[] arr;

    return 0;
}
