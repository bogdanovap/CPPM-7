#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {

    // файл лежат в директории с исходным кодом, а не в debug
    // поэтому указываем адрес на один уровень выше
    string INPUT_FILE_NAME  = "../in.txt";
    string OUTPUT_FILE_NAME  = "../out.txt";

    // открываем файл для чтения и сразу проверяем корректность
    ifstream file_in(INPUT_FILE_NAME);
    //no file
    if (!file_in.good()) {
        cout << "E: File not found" << endl;
        return 1;
    }

    // по аналогии с дипломным блоком предыдущего модуля, рассчитываем что структура файла задается не строго
    // создаем вектор, куда мы поместим все значения из файла
    std::vector<int> all_numbers;

    // читаем файл в вектор
    int count=0;
    int number;
    while(file_in >> number){
        all_numbers.push_back(number);
        count++;
    }
    // сразу после чтения, файл закрываем
    file_in.close();

    // опредялем длину первого и второго массивово
    int len_1 = all_numbers[0];
    int len_2 = all_numbers[len_1+1];

    // выдлеяем память под массивы и иницруем значения - 0
    int *line_1 = new int[len_1]();
    int *line_2 = new int[len_2]();

    // нам нужно поменять порядок значений в массиве
    // делаем это сразу при чтении данных из вектора
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

    // теперь массивы готовы и мы можем начинать запись в файл
    // отркываем файл для чтения
    ofstream file_out;
    file_out.open(OUTPUT_FILE_NAME);
    // записываем размер второго массива
    file_out << len_2 << endl;
    // записывыаем значнеия второго массива
    file_out << line_2[0];
    for (int i = 1; i<len_2; i++) {
        file_out << " " << line_2[i];
    }
    file_out << endl;
    // записываем длину первого массива
    file_out << len_1 << endl;
    // записываем значения первого массива
    file_out << line_1[0];
    for (int i = 1; i<len_1; i++){
        file_out << " " << line_1[i];
    }
    file_out << endl;
    // после записи - закрываем файл
    file_out.close();

    // освобождаем память (удаляем массивы)
    delete [] line_1;
    delete [] line_2;

    return 0;
}
