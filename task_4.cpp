#include "Header.h"

int task4(void)
{

    string str;
    int i, k = 0;
    std::cout << "Введите строку" << endl;
    
    
    //cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    getline(cin, str);
    vector<int> vec;
    for (i = 0; i < str.size(); i++)
        if (isdigit(str[i]))
            vec.push_back((int)(str[i]) - 48);

    if (vec.size() == 0) {
        std::cout << "В строке \"" << str << "\"  нет цифр" << endl;
        return 0;
    }

    while (true)
    {
        vector<int> v = safeInputVec<int>("Введите номер чифры или диапазон:\n");
        if ((find(v.begin(), v.end(), ERR_INCORRECT_NUMBER) != v.end()) ||
            (find(v.begin(), v.end(), ERR_INCORRECT_NUMBER_TYPE) != v.end())) {

            cout << "В введенных данных обнаружена ошибка.";
            continue;
        }


        if (v.size() == 1)
            if (v[0] > vec.size()) {
                std::cout << "Номер не может быть больше количества цифр" << endl;
                continue;
            }
            else
                if (v[0] < 1) {
                    std::cout << "Номер не может быть меньше одного" << endl;
                    continue;
                }
                else {
                    std::cout << "Цифрой номер " << v[0] << " являеться " << vec[v[0] - 1] << endl;
                    break;
                }

        if (v.size() == 2)
            if ((v[0] < 1) || (v[0] >= v[1]) || (v[1] > vec.size())) {
                std::cout << "Некорректный диапозон" << endl;
                continue;
            }
            else {
                std::cout << "Цифрами в диапозоне от " << v[0] << " до " << v[1] << " являются: ";
                for (int i = v[0] - 1; i <= v[1] - 1; i++) {
                    std::cout << vec[i];
                }
                std::cout << endl;
                break;
            }


        if (v.size() > 2)
            std::cout << "Диапазон не может состоять из трёр чисел" << endl;
    }


        
     /**/
    /**/
    return 0;
}
