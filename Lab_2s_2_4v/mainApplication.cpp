#include "polynomlist.h";

int main()
{
	polmult::PolList pol1, pol2, pol3;

	pol1.add(1, 0);
	pol1.add(3, 1);
	pol1.add(9, 2);

	pol2.add(0, 0);

	pol3 = polmult::multiply(pol1, pol2);
	pol3.removeDup();
	pol3.printList();
}