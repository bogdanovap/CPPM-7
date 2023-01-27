#include <iostream>
#include <string>

using namespace std;

//Создайте структуру для хранения адреса. Структура должна содержать
// название страны,
// города,
// улицы,
// номер дома,
// номер квартиры и
// индекс.
struct AddressStruct {
    string country;
    string city;
    string street;
    int building;
    int flat;
    int zip_code;
};


//Создайте функцию для вывода структуры на консоль.
void show_address(const AddressStruct &address) {
    cout << "Город: " << address.city << endl;
    cout << "Улица: " << address.street << endl;
    cout << "Номер дома: " << address.building << endl;
    cout << "Номер квартиры: " << address.flat << endl;
    cout << "Индекс: " << address.zip_code << endl;
}


//Протестируйте созданную функцию.
// Создайте в коде экземпляры структуры,
// передайте их в функцию и
// выведите на консоль получившиеся экземпляры структуры.
int main() {
    AddressStruct address_1 = {"Россия","Москва","Арбат", 12, 8, 123456};
    show_address(address_1);

    cout << endl;

    AddressStruct address_2 = {"Россия","Ижевск","Пушкина", 59, 143, 953769};
    show_address(address_2);

    return 0;
}
