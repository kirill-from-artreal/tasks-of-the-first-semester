#include "Header.h"

int task4(void)
{

    string str;
    int i, k = 0;
    std::cout << "������� ������" << endl;
    
    
    //cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    getline(cin, str);
    vector<int> vec;
    for (i = 0; i < str.size(); i++)
        if (isdigit(str[i]))
            vec.push_back((int)(str[i]) - 48);

    if (vec.size() == 0) {
        std::cout << "� ������ \"" << str << "\"  ��� ����" << endl;
        return 0;
    }

    while (true)
    {
        vector<int> v = safeInputVec<int>("������� ����� ����� ��� ��������:\n");
        if ((find(v.begin(), v.end(), ERR_INCORRECT_NUMBER) != v.end()) ||
            (find(v.begin(), v.end(), ERR_INCORRECT_NUMBER_TYPE) != v.end())) {

            cout << "� ��������� ������ ���������� ������.";
            continue;
        }


        if (v.size() == 1)
            if (v[0] > vec.size()) {
                std::cout << "����� �� ����� ���� ������ ���������� ����" << endl;
                continue;
            }
            else
                if (v[0] < 1) {
                    std::cout << "����� �� ����� ���� ������ ������" << endl;
                    continue;
                }
                else {
                    std::cout << "������ ����� " << v[0] << " ��������� " << vec[v[0] - 1] << endl;
                    break;
                }

        if (v.size() == 2)
            if ((v[0] < 1) || (v[0] >= v[1]) || (v[1] > vec.size())) {
                std::cout << "������������ ��������" << endl;
                continue;
            }
            else {
                std::cout << "������� � ��������� �� " << v[0] << " �� " << v[1] << " ��������: ";
                for (int i = v[0] - 1; i <= v[1] - 1; i++) {
                    std::cout << vec[i];
                }
                std::cout << endl;
                break;
            }


        if (v.size() > 2)
            std::cout << "�������� �� ����� �������� �� ��� �����" << endl;
    }


        
     /**/
    /**/
    return 0;
}
