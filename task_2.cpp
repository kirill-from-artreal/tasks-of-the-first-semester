#include "Header.h"

int task2(void) {

    vector<int> rooms;

    bool duplicate = false;
    while (int choice = safeInput<int>("Введите номер комнаты, в которую нужно провести кабель (0 для завершения): ")) {
        
        for (int i = 0; i < rooms.size(); ++i)
            if (rooms[i] == choice) {
                duplicate = true;
                break;
            }

        if (duplicate) cout << "Число повторяется. Введите другое число: " << endl;
            else rooms.push_back(choice);
    }

    for (int i = 0; i < rooms.size() - 1; ++i) {
        for (int j = 0; j < rooms.size() - i - 1; ++j) {
            if (rooms[j] > rooms[j + 1]) {
                int temp = rooms[j];
                rooms[j] = rooms[j + 1];
                rooms[j + 1] = temp;
            }
        }
    }

    if (rooms.size() % 2 == 1) {
        int middle = (int)rooms.size() / 2;
        cout << "Выгоднее ставить в: " << rooms[middle] << endl;
    }
    else {
        int middle1 = (int)rooms.size() / 2 - 1;
        int middle2 = (int)rooms.size() / 2;
        cout << "Выгодно ставить в " << rooms[middle1] << " и " << rooms[middle2] << " Или любое число между ними" << endl;
    }
    
    return 0;
}
