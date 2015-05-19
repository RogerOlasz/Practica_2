#include "DList.h"

int main(int argc, char** argv)
{
	DList<int> List1;

	List1.Add(5);
	List1.Add(8);
	List1.Add(2);
	List1.Add(12);
	List1.Add(4);

	printf("%d", List1[1]);

	getchar();

	return 0;
}