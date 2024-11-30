#include "Header.h"

int task4(void) {

    string str;
    int i, k = 0;
    std::cout << "Введите строку" << endl;                                                      // "Enter a line"
    
    getline(cin, str);
    vector<int> vec;
    for (i = 0; i < str.size(); i++)
        if (isdigit(str[i]))
            vec.push_back((int)(str[i]) - 48);

    if (vec.size() == 0) {
        std::cout << "В строке \"" << str << "\"  нет цифр" << endl;                            // "There are no numbers in the string \"" << str << "\"
        return 0;
    }

    while (true)
    {
        vector<int> v = safeInputVec<int>("Введите номер цифры или диапозон цифр­:\n");         // "Enter the number of the digit or the range of digits:\n"
        if ((find(v.begin(), v.end(), ERR_INCORRECT_NUMBER) != v.end()) ||
            (find(v.begin(), v.end(), ERR_INCORRECT_NUMBER_TYPE) != v.end())) {

            cout << "Неккоректный ввод";
            continue;
        }


        if (v.size() == 1)
            if (v[0] > vec.size()) {
                std::cout << "Номер цыфры не может превышать количество цифо" << endl;         // ""The number of a digit cannot exceed the number of digits"
                continue;
            }
            else
                if (v[0] < 1) {
                    std::cout << "Номер цыфры не может быть меньше еденицы" << endl;            // "Номер цыфры не может быть меньше еденицы"
                    continue;
                }
                else {
                    std::cout << "Цифрой номер " << v[0] << " является " << vec[v[0] - 1] << endl;           //"Digit number " " is "
                    break;
                }

        if (v.size() == 2)
            if ((v[0] < 1) || (v[0] >= v[1]) || (v[1] > vec.size())) {
                std::cout << "Неккоректный ввод диапозона" << endl;                                           // "Incorrect range input"
                continue;
            }
            else {
                std::cout << "Цифрами в диапозоне от " << v[0] << " до" << v[1] << " являются ";              // "The numbers in the range from " " to " " are "
                for (int i = v[0] - 1; i <= v[1] - 1; i++) {
                    std::cout << vec[i];
                }
                std::cout << endl;
                break;
            }


        if (v.size() > 2)
            std::cout << "Диапозон не может состоять более чем из двух элементов" << endl;                     // "A range cannot consist of more than two elements"
    }


    return 0;
}
