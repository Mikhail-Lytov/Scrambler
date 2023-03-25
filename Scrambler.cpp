

#include <iostream>
using namespace std;

string scrambling(string line, int first_offset, int second_offset ) {
    int *input_data = new int[line.length()];
    int *output_data = new int[line.length()];
    string line_output = "";

    for (int i = 0; i < line.length(); i++) {
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
            output_data[i] = input_data[i] ^ output_data[i - first_offset];
        }
        else {
            output_data[i] = input_data[i] ^ output_data[i - first_offset] ^ output_data[i - second_offset];
        }

    }
    for(int i = 0; i <line.length(); i++){
        line_output += to_string(output_data[i]);
    }
    return line_output;
}
int main()
{
    string line_2 = "111111110000000";
    cout << scrambling(line_2, 3,5);

}

