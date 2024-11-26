#include "Header.h"


//void creating_an_array(int** matrix, int n) {
//
//}

void matrix_output(int** matrix, int n) {

	int number_of_digits = 0;
	int k = n * n;
	while (k > 0)
	{
		k /= 10; number_of_digits++;
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			std::cout << std::setw(number_of_digits) << matrix[i][j] << ' ';
		}

		std::cout << std::endl;
	}
	std::cout << std::endl;
}

int task3(void) {
	
	int n = safeInput<int>("Ââåäèòå N äëÿ ñîçäàíèÿ ìàòğèöû N x N ");

	int** matrix = new int* [n];
	for (int i = 0; i < n; i++)
		matrix[i] = new int[n];


	

	// ÂÅĞÕÍÈÉ ËÅÂÛÉ
	std::cout << "ÂÅĞÕÍÈÉ ËÅÂÛÉ" << std::endl;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n - i; ++j)
		{
			matrix[i][j] =((i + j + 1) * (i + j) / 2 + (i + j ) % 2 * (i + 1) + (i + j+ 1) % 2 * (j + 1));
			matrix[n - i - 1][n - j - 1] = n * n + 1 - matrix[i][j];
		}
	}
	// âûâîä ìàññèâà
	matrix_output(matrix, n);

	
	/**/

	// ÂÅĞÕÍÈÉ ÏĞÀÂÛÉ
	std::cout << "ÂÅĞÕÍÈÉ ÏĞÀÂÛÉ" << std::endl;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n - i; ++j)
		{
			matrix[i][j] =((i + j + 1) * (i + j) / 2 + (i + j ) % 2 * (i + 1) + (i + j+ 1) % 2 * (j + 1));
			matrix[n - i - 1][n - j - 1] = n * n + 1 - matrix[i][j];
		}
	}
	matrix_output(matrix, n);

	
	// ÍÈÆÍÈÉ ÏĞÀÂÛÉ
	std::cout << "ÍÈÆÍÈÉ ÏĞÀÂÛÉ" << std::endl;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n - i; ++j)
		{
			matrix[i][j] = ((i + j + 1) * (i + j) / 2 + (i + j) % 2 * (i + 1) + (i + j + 1) % 2 * (j + 1));
			matrix[n - i - 1][n - j - 1] = n * n + 1 - matrix[i][j];
		}
	}

	// ÍÈÆÍÈÉ ÏĞÀÂÛÉ
	std::cout << "ÍÈÆÍÈÉ ËÅÂÛÉ" << std::endl;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n - i; ++j)
		{
			matrix[i][j] = ((i + j + 1) * (i + j) / 2 + (i + j) % 2 * (i + 1) + (i + j + 1) % 2 * (j + 1));
			matrix[n - i - 1][n - j - 1] = n * n + 1 - matrix[i][j];
		}
	}

	return 0;
}