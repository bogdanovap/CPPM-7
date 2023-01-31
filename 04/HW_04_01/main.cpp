#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class CAddress{
public:
    CAddress(string city, string street, int house, int flat);

    string get_address_string(){
        auto res = city + ", " + street+ ", " + to_string(house)+ ", " + to_string(flat);
        return res;
    };

private:
    string city;
    string street;
    int house;
    int flat;
};

CAddress::CAddress(string city, string street, int house, int flat) {
    this->city = city;
    this->street = street;
    this->house = house;
    this->flat = flat;
}

int main() {

    string INPUT_FILE_NAME  = "../in.txt";
    string OUTPUT_FILE_NAME  = "../out.txt";

    ifstream file_in(INPUT_FILE_NAME);
    //no file
    if (!file_in.good()) {
        cout << "E: File not found" << endl;
        return 1;
    }

    int address_count = 0;
    file_in >> address_count;
    if (address_count <= 0) return -1;

//    CAddress* address[address_count];
    std::vector<CAddress> address;
    string city, street;
    int house, flat;
    for (int i = 0; i<address_count; i++){
        file_in >> city;
        file_in >> street;
        file_in >> house;
        file_in >> flat;
//        address[i] = new CAddress(city, street, house, flat);
        address.emplace_back(city, street, house, flat);
    }

    file_in.close();

    ofstream file_out;
    file_out.open(OUTPUT_FILE_NAME);
    file_out << address_count << endl;
    for (int i=address_count-1;i>=0;i--){
//        file_out << address[i]->get_address_string() << endl;
        file_out << address[i].get_address_string() << endl;
    }

    file_out.close();

    return 0;
}
