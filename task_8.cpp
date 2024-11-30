#include <fstream>
#include "Header.h"


int task8(void) {
	std::cout << "task8\n";

	const int N = 9;

	std::cout << "���� / �� ����( ���. - https://ru.pinterest.com/pin/27936460190881703/ )\n";									// "It was / Did not have�(Ist. - https://ru.pinterest.com/pin/27936460190881703 / )\n"
	string questions[N+1] = {
		"�����(�) ���� � ����� ��?",																							// "Did you take nude photos?",
		"�����(�) ����� ������?",																								// "Did you wear someone else's clothes?",
		"����������(���) ����� � ����/��-��������?",																			// "Did you wake up next to someone you didn't know?",
		"���������������(���) �� ����� ���������?",																				// "Did you register on a dating site?",
		"������(�) ������?",																									// "Did you paint(a) hair?",
		"���(�) ������� ������?",																								// "Was (a) victim of abuse?",
		"�����(�) ���� �/��� �������?",																							// "Did (a) tattoo and/or piercing?",
		"������(�) ��� �������?",																								// "Cried(a) with friends?",
		"��������� ��������� (+) ������ ���� ������ (-)"																		// "Save the result (+) Take the test again (-)"
	};

	bool answers[N];
	bool answer_option = true;
	answers[N-1] = false;

	
	while (!answers[N - 1]) {
		for (int i = 0; i < N; i++) {

			bool isEnterPressed = false;
			while (!isEnterPressed) {

				system("cls");

				for (int j = 0; j < i; j++)
					std::cout << (answers[j] ? " + : " : " - : ") << questions[j] << endl;

				std::cout << (answer_option ? "[+]: " : "[-]: ") << questions[i] << endl;

				char act = _getch();
				int ch = static_cast<int>(act);

				switch (ch)
				{
				case 13: // Enter
					if (answer_option)
						answers[i] = true;
					else
						answers[i] = false;

					isEnterPressed = true;
					break;
				case 77: // 
					answer_option = false;
					break;
				case 75:  // 
					answer_option = true;
					break;

				case -32: break;
				default: break;
				}
			}
		}
	}
		



	


	unsigned int int_base = 0;

	for (int i = 0; i < N - 1; i++)
		if (answers[i]==true)
			int_base += 1 << i;


	unsigned char char_base = int_base;


	/**
	for (int i = 0; i < N - 1; i++)
		if (char_base & (1 << i))
			std::cout << "+" << endl;
		else
			std::cout << "-" << endl;

	std::cout << "char_base - " << char_base << endl;
	/**/


	ofstream out;				 
	out.open("task_8.txt");      
	if (out.is_open())
		out << char_base;

	out.close();																		
	std::cout << "��������� ���������� � ����� task_8.txt" << std::endl;					// "The result is encrypted in a file task_8.txt "
																						
																						
	string line;																		
	char read_from_file = 0;															
																						
	ifstream in("task_8.txt"); 															
	if (in.is_open()) {																	
		std::cout << "���� task_8.txt ������" << endl;										// "File task_8.txt open"
		in.get(read_from_file);																
	}																						
	in.close();     																		
																							
	std::cout << "������ �� ����� task_8.txt ������������� : " << endl;						// "Data from a file task_8.txt decrypted : "

	for (int i = 0; i < N - 1; i++)
		if (read_from_file &(1 << i))
			std::cout << "+ ";
		else
			std::cout << "- ";

	std::cout << endl;

	return 0;
}