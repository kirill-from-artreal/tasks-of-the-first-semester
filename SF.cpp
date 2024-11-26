#include "Header.h"


int SF(void) {

	//int i = safe_input_int("1111\n");
	
	/**/
	vector<double> v = safeInputVec<double>(":\n");
	if ((find(v.begin(), v.end(), ERR_INCORRECT_NUMBER) != v.end()) || 
		(find(v.begin(), v.end(), ERR_INCORRECT_NUMBER_TYPE) != v.end()))
		cout << "В введенных данных обнаружена ошибка.";
	else
		for (auto i : v)
			cout << i << " ";
	cout << endl;
	/**/

	/**
	double v = safeInput<double>(":\n");

	if ((v == ERR_INCORRECT_NUMBER) ||
		(v == ERR_INCORRECT_NUMBER_TYPE) )
		cout << "В введенных данных обнаружена ошибка.";
	else
		cout << v << " ";
	cout << endl;
	/**/
	
	return 0;
}