#include <iostream>
#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

int scrambling(unsigned data, int first_offset, int second_offset ) {
    string line = "";
    int size = 0;

    do {
        line.push_back('0' + (data & 1));
    }while (data >>= 1);
    reverse(line.begin(), line.end());
    int input_data[15];
    int output_data[15];
    int output = 0;

    for (int i = 0; i < line.length(); i++) {\
        if ((int)line[i] == 49) {
            input_data[i] = 1;
        }
        else {
            input_data[i] = 0;
        }
    }
    for (int i = 0; i < line.length(); i++)
    {
        if (i < first_offset) {
            output_data[i] = (int)input_data[i];
        }
        else if (i < second_offset) {
            output_data[i] = input_data[i] ^ input_data[i - first_offset];
        }
        else {
            output_data[i] = (input_data[i] ^ input_data[i - first_offset]) ^ input_data[i - second_offset];
        }

    }
    for(int i = 0; i < line.length();i++){
        cout << output_data[i];
    }
    cout << "\n";
    for(int i = line.length() - 1; i > -1; i--){
        output += pow(2,size++) * output_data[i];
    }
    return output;
}

int main(){

    cout << scrambling(29273,3,5); // 32640
    return 0;
}