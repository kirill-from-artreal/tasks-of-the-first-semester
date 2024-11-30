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
	{  0,  -1,	 0, "����" },											  // "Menu"      },
	{  1,   1,	-1, "������� 1:  ����������� �����"				},		  // "Task  1: Wallpaper Calculator"	},
	{  2,   2,	-1, "������� 2:  ������� � ������������"		},		  // "Task  2: Switchboard Room"		},
	{  3,   3,	-1, "������� 3:  ������ \"������\""				},		  // "Task  3: The \"Snake\" array"	},
	{  4,   4,	-1, "������� 4:  ����� � ���"					},		  // "Task  4: Numbers in a row"		},
	{  5,   5,	-1, "������� 5:  ������� � ��������� �����"		},		  // "Task  5: Big and small words"	},
	{  6,   6,	-1, "������� 6:  ������������ ��������"			},		  // "Task  6: Rearranging columns"	},
	{  7,   7,	-1, "������� 7:  ������� ������ ����� �������"	},		  // "Task  7: Simple class log"		},
	{  8,   8,	-1, "������� 8:  ������������� �����"			},		  // "Task  8: Encrypted survey"		},
	{  9,   9,	-1, "������� 9:  �������� ��������"				},		  // "Task  9: Pyramids of stars"	},
	{ 10,  10,	-1, "������� 10: ������������ �������������"	},		  // "Task 10: Fair distribution"	},
	{ 11,  11,	-1, "������� 11: ������� �������"				},		  // "Task 11: Bookstore"			},
	{ 12,  12,	-1, "������� 12: ������� �������"				},		  // "Task 12: Areas of the matrix"	},

	{ 20, -1,  1, "item list "         },
	{ 30, -1,  2, "one more� item list" },
	{ 31, 20, -1, "safe_input"         }

};

vector<MenuDB> menuDB = {
	{ 0, {1,2,3,4,5,6,7,8,9,11,10,12} },
	{ 1, {30,31}                      },
	{ 2, {31}                         }
};