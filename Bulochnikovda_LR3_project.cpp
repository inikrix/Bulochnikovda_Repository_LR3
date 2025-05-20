#include <iostream>
#include <map>
#include <string>
#include <functional>
#include <cmath>

using namespace std;

int a;

bool UserInput(string input) {
    if(input.empty()) return false;

    try {
        int number = stoi(input);
        if (number < 0) return false;
    }
    catch (...)
    { return false; }
    return true;
}

void enterNumber(int& varLink, string label){
    string str_input;
    cout << label << " = ";
    getline (cin, str_input);

    while (!UserInput(str_input)){
        cout << label << " = ";
        getline(cin, str_input);
    }
    varLink = stoi(str_input);
}

void enterA() {
    enterNumber(a, "A");
    cout << "Число A успешно сохранено: A = " << a << endl;
}

void calcS3() {
    if (a == 0) {
        cout << "Ошибка: число A не введено или равно 0" << endl;
        return;
    }
    double area = (pow(a, 2) * sqrt(3)) / 4;
    cout << "Площадь равностороннего треугольника со стороной " << a << " равна: " << area << endl;
}

void calcP3() {
    if (a == 0) {
        cout << "Ошибка: число A не введено или равно 0" << endl;
        return;
    }
    int perimeter = 3 * a;
    cout << "Периметр равностороннего треугольника со стороной " << a << " равен: " << perimeter << endl;
}

struct MenuItem{
    string title;
    function<void()> action;
};

int main() {
    map<int, MenuItem> menu = {
        {1,{"ввести положительное число А", enterA}},
        {2,{"вычислить площадь равностороннего треугольника S = а**2*Sqrt(3)/4", calcS3}},
        {3,{"вычислить периметр равностороннего треугольника Р = 3*a", calcP3}},
    };

    int choice = 0;

    while(true) {
        cout << "Меню:" << endl;
        for (const auto& item : menu){
            cout << "Task " << item.first << ". " << item.second.title << endl; 
        }
        cout << "0. Выход" << endl;
        enterNumber(choice, "Input number of menu: ");
        if (choice == 0){
            cout << "@ 2025 Bulochnikov DA" << endl;
            break;
        }
        cout << endl;
        if (menu.find(choice) != menu.end()){
            menu[choice].action();
            } else {
                cout << "Некорректный ввод.";
            }
            cout << endl;
    }
    return 0;
}