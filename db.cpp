#include "Header.h"

vector<FuncDB> funcDB = {
	{  0, task0  },
	{  1, task1  },
	{  2, task2  },
	{  3, task3  },
	{  4, task4  },
	{  5, task5  },
	{  6, task6  },
	{  7, task7  },
	{  8, task8  },
	{  9, task9  },
	{ 10, task10 },
	{ 11, task11 },
	{ 12, task12 },
	{ 20, SF     }
};

vector<ItemDB> itemDB = {
	{  0,  -1,	 0, "Меню" },											  // "Menu"      },
	{  1,   1,	-1, "Задание 1:  Калькулятор обоев"				},		  // "Task  1: Wallpaper Calculator"	},
	{  2,   2,	-1, "Задание 2:  Комната с коммутатором"		},		  // "Task  2: Switchboard Room"		},
	{  3,   3,	-1, "Задание 3:  Массив \"Змейка\""				},		  // "Task  3: The \"Snake\" array"	},
	{  4,   4,	-1, "Задание 4:  Цифры в ряд"					},		  // "Task  4: Numbers in a row"		},
	{  5,   5,	-1, "Задание 5:  Большие и маленькие слова"		},		  // "Task  5: Big and small words"	},
	{  6,   6,	-1, "Задание 6:  Перестановка столбцов"			},		  // "Task  6: Rearranging columns"	},
	{  7,   7,	-1, "Задание 7:  Простой журнал учета занятий"	},		  // "Task  7: Simple class log"		},
	{  8,   8,	-1, "Задание 8:  Зашифрованный опрос"			},		  // "Task  8: Encrypted survey"		},
	{  9,   9,	-1, "Задание 9:  Звездные пирамиды"				},		  // "Task  9: Pyramids of stars"	},
	{ 10,  10,	-1, "Задание 10: Справедливое распределение"	},		  // "Task 10: Fair distribution"	},
	{ 11,  11,	-1, "Задание 11: Книжный магазин"				},		  // "Task 11: Bookstore"			},
	{ 12,  12,	-1, "Задание 12: Области матрица"				},		  // "Task 12: Areas of the matrix"	},

	{ 20, -1,  1, "item list "         },
	{ 30, -1,  2, "one more­ item list" },
	{ 31, 20, -1, "safe_input"         }

};

vector<MenuDB> menuDB = {
	{ 0, {1,2,3,4,5,6,7,8,9,11,10,12} },
	{ 1, {30,31}                      },
	{ 2, {31}                         }
};