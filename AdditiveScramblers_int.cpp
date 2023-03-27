#include <iostream>
#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

int scrambling(unsigned data, unsigned key_input, int first_offset, int second_offset ) {
    string line = "";
    string key = "";
    int output;
    int size = 0;

    do {
        line.push_back('0' + (data & 1));
    }while (data >>= 1);

    do {
        key.push_back('0' + (key_input & 1));
    }while (key_input >>= 1);

    reverse(line.begin(), line.end());
    reverse(key.begin(), key.end());

    int *input_data = new int[line.length()];
    int *output_data = new int[line.length()];
    int *key_data = new int[key.length()];
    int variable;
    for(int i = 0; i < key.length(); i++){
        if((int)key[i] == 49){
            key_data[i] = 1;
        }else{
            key_data[i] = 0;
        }
    }
    for(int i = 0; i < line.length(); i++){
        if((int)line[i] == 49){
            input_data[i] = 1;
        }else input_data[i] = 0;
    }
    for(int i = 0; i < line.length();i++){
        output_data[i] = key_data[key.length() - 1] ^ input_data[i];
        int element = key_data[key.length() - 1] ^ key[first_offset] ^ key[second_offset] ^ key[0];
        variable = key_data[0];
        for(int j = 1; j < key.length(); j++){
            int element_j = key_data[j];
            key_data[j] = variable;
            variable = element_j;
        }
        key_data[0] = element;
    }
    for(int i = line.length() - 1; i > -1; i--){
        output += pow(2,size++) * output_data[i];
    }
    return output;

}

int main(){

    cout << scrambling(22, 19, 3,5); // 32640
    return 0;
}