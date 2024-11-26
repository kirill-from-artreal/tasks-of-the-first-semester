#include "Header.h"

extern vector<FuncDB> funcDB;
extern vector<ItemDB> itemDB;
extern vector<MenuDB> menuDB;

list< vector<Item> > menus; // ���� ������ list ����� vector, �� ��� �� �������� 

Item makeItemFromDB(int id)
{
    ItemDB iDB = itemDB[id];
    Item i;
    i.title = iDB.title;
    if (iDB.menuID != -1)
    {
        i.pfunc = NULL;
        MenuDB mDB = menuDB[iDB.menuID];
        vector<Item> m;
        for (int j = 0; j < mDB.itemID.size(); j++)
            m.push_back(makeItemFromDB(mDB.itemID[j]));
        menus.push_back(m);
        i.pmenu = &menus.back();
    }
    else // if (iDB.funcID != -1)
    {
        i.pmenu = NULL;
        i.pfunc = funcDB[iDB.funcID].pfunc;
    }
    return i;
}


int main(void)
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    
    Item item = makeItemFromDB(0);
    vector<Item> crumbs (1, item);

    int selected_item = 0;
    int n = item.pmenu->size();
    bool isEscPressed = false;
    while (!isEscPressed)
    {
        system("cls");
        for (auto crumb : crumbs)
            cout << crumb.title << " > ";
        cout << endl;
        
        vector<Item> menu = *item.pmenu;
        for (int i = 0; i < menu.size(); i++)
            cout << "\t" << (selected_item == i ? "<#>" : "   ") << menu[i].title << endl;

        char act = _getch();// ���������� ����� ������������
        int ch = static_cast<int>(act);//���������� � ���������������� ���� 
        switch (ch)
        {
        case 13: // Enter
        case 77: // ������
            menu[selected_item].selected_item = selected_item;
            crumbs.push_back(menu[selected_item]);
            if (menu[selected_item].pfunc != NULL)
            {
                system("cls");
                for (auto crumb : crumbs)
                    cout << crumb.title << " > ";
                cout << endl;

                menu[selected_item].pfunc();
                system("pause");
                crumbs.pop_back();
            }
            else if (menu[selected_item].pmenu != NULL)
            {
                selected_item = 0;
                item = crumbs.back();
                n = item.pmenu->size();
            }
            break;
        case 75:  // �����
            if (crumbs.size() > 1)
            {
                crumbs.pop_back();
                selected_item = item.selected_item;
                item = crumbs.back();
                n = item.pmenu->size();
            }
            break;
        case 80: selected_item = (selected_item + 1 + 0) % n; break; // ����
        case 72: selected_item = (selected_item - 1 + n) % n; break; // �����
        case 27: isEscPressed = true; break; // Esc - ��� ������ �� �����
        case -32: break; // ��� ����� �������. ������ ���������� ��������, � �� ��������� � ������������ ��� ��� ����� �������.
        default: break;
        }
    }

    //system("pause");
    return 0;
}

/**
vector<Item> menu_1;
menu_1.push_back({ "������� 11: ������ �����", task1, NULL });
menu_1.push_back({ "������� 21: ������� � ���������", task2, NULL });
menu_1.push_back({ "������� 31: ������ \"�������\"", task3, NULL });
menu_1.push_back({ "������� 41: ����� ����� � ������", task4, NULL });

vector<Item> menu_main;
menu_main.push_back({ "������� 1: ������ �����", task1, NULL });
menu_main.push_back({ "������� 2: ������� � ���������", task2, NULL });
menu_main.push_back({ "������� 3: ������ \"�������\"", task3, NULL });
menu_main.push_back({ "������� 4: ����� ����� � ������", task4, NULL });
menu_main.push_back({ "item � �����������", NULL, &menu_1 });

Item item = { "����", NULL, &menu_main };
/**/
