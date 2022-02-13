#pragma once

namespace polmult
{
	struct Pol
	{
		int coef;
		int pow;
		void printInfo();
		Pol(int coef, int pow);
	};
	struct PolList 
	{
		struct Node
		{
			Pol* info;
			Node* prev = nullptr;
			Node* next = nullptr;
			Node(Pol* info);
		};
		Node* head = nullptr;
		Node* tail = nullptr;
		int findCoef(int pow);
		void removeKebab();
		void add(int coef, int pow);
	};
	PolList multiply(PolList list1, PolList list2);
}
