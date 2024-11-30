#include "Header.h"

extern vector<FuncDB> funcDB;
extern vector<ItemDB> itemDB;
extern vector<MenuDB> menuDB;

list< vector<Item> > menus; //  list  vector

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

        char act = _getch();
        int ch = static_cast<int>(act);
        switch (ch)
        {
        case 13: // Enter
        case 77: // RIGHT
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
        case 75:  // LEFT
            if (crumbs.size() > 1)
            {
                crumbs.pop_back();
                selected_item = item.selected_item;
                item = crumbs.back();
                n = item.pmenu->size();
            }
            break;
        case 80: selected_item = (selected_item + 1 + 0) % n; break; // DOWN
        case 72: selected_item = (selected_item - 1 + n) % n; break; // UP
        case 27: isEscPressed = true; break; // Esc - EXIT
        case -32: break; // SKIP ARROW BLOCK
        default: break;
        }
    }

    system("pause");
    return 0;
}
