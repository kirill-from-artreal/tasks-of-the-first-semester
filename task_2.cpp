#include "Header.h"

int task2(void) {

    vector<int> rooms;

    bool duplicate = false;
    while (int choice = safeInput<int>("Введите номер комнаты, в которую нужно провести кабель (0 для завершения): ")) {  // "Enter the number of the room to which you want to run the cable (0 to complete): "
        
        for (int i = 0; i < rooms.size(); ++i)
            if (rooms[i] == choice) {
                duplicate = true;
                break;
            }

        if (duplicate) cout << "Число повторяется. Введите другое число: " << endl;           // "The number repeats. Enter another number: "
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
        cout << "Выгоднее ставить в: " << rooms[middle] << endl;                              // "It is more profitable to put in: "
    }
    else {
        int middle1 = (int)rooms.size() / 2 - 1;
        int middle2 = (int)rooms.size() / 2;
        cout << "Выгодно ставить в " << rooms[middle1] << " и " << rooms[middle2] << " Или любое число между ними" << endl;  // ""It is advantageous to put in " " and " " Or any number between them"
    }
    
    return 0;
}
