#include <iostream>
using namespace std;


string scrambling(string line, string key, int first_offset, int second_offset){
    int *input_data = new int[line.length()];
    int *output_data = new int[line.length()];
    int *key_data = new int[key.length()];
    string line_output = "";
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
    for(int i = 0; i <line.length(); i++){
        line_output += to_string(output_data[i]);
    }
    return line_output;
}

int main()
{
    string line = "10110";
    string key = "10011";
    cout << scrambling(line, key, 2,3);

}