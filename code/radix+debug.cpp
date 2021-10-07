#include <cstdio>
#include <string>
using std::string;
#include <iostream>
using namespace std; 

size_t getMax(string arr[], int n){
    size_t max = arr[0].size();
    for (int i = 1; i < n; i++){
        if (arr[i].size()>max)
            max = arr[i].size();
    }
    return max;
}

void countSort(string a[], int size, size_t k){
    string *b = NULL; int *c = NULL;
    b = new string[size];
    c = new int[257];



    for (int i = 0; i <257; i++){
        c[i] = 0;
        cout << c[i] << " ";
    }
    cout << endl; 
    for (int j = 0; j <size; j++){   
        cout << c[a[j][k]+1] << endl;
        if (k < a[j].size()) {
            c[(int)(unsigned char)a[j][k] + 1 ]++; 
        }

        else {
            c[0]++; 
        }
           //a[j] is a string
        cout << "c[0] is " << c[0] << "//" << a[j] << endl; 
        cout << c[a[j][k]+1] << "          position:   " << a[j][k]+1 << "                           " << a[j][k] << endl;
        
        cout << endl; 
    }

    for (int f = 1; f <257; f++){
        cout << c[f] << ' '; 
    }

    cout << endl << endl << endl; 



    for (int f = 1; f <257; f++){
        c[f] += c[f - 1];
        cout << c[f] << ' '; 
    }

    cout << endl << endl << endl; 

    for (int r = size - 1; r >= 0; r--){
        
        if (k < a[r].size()) {
            b[c[(int)(unsigned char)a[r][k] + 1] - 1] = a[r]; 
            c[(int)(unsigned char)a[r][k] + 1]--; 
            cout << "In b " << a[r] << " position: " << c[(int)(unsigned char)a[r][k] + 1] << endl; 
            
        }

        else {
            b[c[0] - 1] = a[r]; 
            c[0]--; 
            cout << "In b " << a[r] << " position: " << c[0] - 1 - 1 << endl;
        }

        

    }

    for (int l = 0; l < size; l++){
        a[l] = b[l];
    }

    cout << endl; 

    // avold memory leak
    delete[] b;
    delete[] c;
}


void radixSort(string b[], int size){
    size_t max = getMax(b, size);
    for (size_t digit = max; digit > 0; digit--){ // size_t is unsigned, so avoid using digit >= 0, which is always true
        countSort(b, size, digit - 1);
        cout << digit << ' '; 
        for (int i = 0; i < size; i++) {
            cout << b[i] << ' '; 
        }
        cout << endl << endl << endl; 
    }

}

int main(void) {
    string data[] = {
        "b",
        "a", 
        "abc",
        "ab"
    };
    puts("before sorting:");
    for (size_t i = 0; i < sizeof(data) / sizeof(data[0]); i++) {
        printf("    %s\n", data[i].c_str());
    }
    radixSort(data, (int)(sizeof(data) / sizeof(data[0])));
    puts("after sorting:");
    for (size_t i = 0; i < sizeof(data) / sizeof(data[0]); i++) {
        printf("    %s\n", data[i].c_str());
    }
    return 0;
}