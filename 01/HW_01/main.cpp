#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {

    string INPUT_FILE_NAME  = "../in.txt";
    string OUTPUT_FILE_NAME  = "../out.txt";

    ifstream file_in(INPUT_FILE_NAME);
    //no file
    if (!file_in.good()) {
        cout << "E: File not found" << endl;
        return 1;
    }

    std::vector<int> all_numbers;

    int count=0;
    int number;
    while(file_in >> number){
        all_numbers.push_back(number);
        count++;
    }
    file_in.close();

    int len_1 = all_numbers[0];
    int len_2 = all_numbers[len_1+1];

    int *line_1 = new int[len_1]();
    int *line_2 = new int[len_2]();

//    5
//    1 2 3 4 5
//    5
//    2 3 4 5 1
    for (int i = 0; i<len_1-1; i++){
        line_1[i] = all_numbers[i+1+1];
    }
    line_1[len_1-1] = all_numbers[1];

//    6
//    10 20 30 40 50 60
//    6
//    60 10 20 30 40 50
    line_2[0] = all_numbers[count-1];
    for (int i = 1; i<len_2; i++){
        line_2[i] = all_numbers[1+len_1+i];
    }

    ofstream file_out;
    file_out.open(OUTPUT_FILE_NAME);
    file_out << len_2 << endl;
    file_out << line_2[0];
    for (int i = 1; i<len_2; i++){
        file_out << " " << line_2[i];
    }
    file_out << endl;
    file_out << len_1 << endl;
    file_out << line_1[0];
    for (int i = 1; i<len_1; i++){
        file_out << " " << line_1[i];
    }
    file_out << endl;

    file_out.close();

    delete [] line_1;
    delete [] line_2;

    return 0;
}
