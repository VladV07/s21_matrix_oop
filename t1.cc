#include "testt.h"

int main()
{
	printf(GREEN "///////////////////////////////////////////\n");
	printf("s t a r t \n");
	printf("///////////////////////////////////////////\n" RESET);
	S21Matrix A(3, 3);
	S21Matrix B(3, 3);
	S21Matrix C;

	A(0,0) = 1;
	A(0,1) = 1;
	A(0,2) = 1;
	A(1,0) = 1;
	A(1,1) = 1;
	A(1,2) = 1;
	A(2,0) = 1;
	A(2,1) = 1;
	A(2,2) = 1;

	A.setCols(3);
	A.setRows(3);
	printf("//////////////\n");


	printf("ok!\n");
	return 0;
}