#include "Header.h"


int SF(void) {

	vector<double> v = safeInputVec<double>(":\n");
	if ((find(v.begin(), v.end(), ERR_INCORRECT_NUMBER) != v.end()) || 
		(find(v.begin(), v.end(), ERR_INCORRECT_NUMBER_TYPE) != v.end()))
		cout << "Â ââåäåííûõ äàííûõ îáíàðóæåíà îøèáêà.";
	else
		for (auto i : v)
			cout << i << " ";
	cout << endl;

	
	return 0;
}