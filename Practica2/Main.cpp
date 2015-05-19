#include "DList.h"
#include <random>


int main(int argc, char** argv)
{
	DList<int> List1;

	unsigned int count = 0;

	for (unsigned int i = 0; i <= 10000; i++)
	{
		List1.Add(rand());
	}

	printf("%d\n%d\n", count, List1.Count());

	count = List1.BubbleSort();

	printf("%d\n%d", count, List1.Count());

	getchar();

	return 0;
}