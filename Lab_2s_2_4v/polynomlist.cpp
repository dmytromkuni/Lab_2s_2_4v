#include "polynomlist.h"

#include <string>
#include <iostream>

void polmult::Pol::printInfo()
{
	std::cout << this->coef << "*x^" << this->pow << " ";
}

polmult::Pol::Pol(int coef, int pow)
{
	this->coef = coef;
	this->pow = pow;
}

polmult::PolList::Node::Node(Pol* info)
{
	this->info = info;
}

void polmult::PolList::removeKebab()
{
	Node* iter1 = head;
	Node* iter2 = head;
	Node* temp;
	while (iter1->next)
	{
		iter2 = iter1;
		while (iter2->next)
		{
			//main LOGIC
			if (iter2->info->pow == iter1->info->pow)
			{
				iter1->info->coef += iter2->info->coef;
				temp = iter2;

				(iter2->prev)->next = iter2->next;
				iter2->next->prev = iter2->prev;
				iter2 = iter2->next;

				delete(temp);
				temp = NULL;
			}
			else iter2 = iter2->next;
		}
		iter1 = iter1->next;
	}
}

void polmult::PolList::add(int coef, int pow)
{
	Pol temp(coef, pow);
	Pol* to_add = &temp;
	Node* node = new Node(to_add);
	if (head == nullptr)
	{
		head = node;
		tail = node;
	}
	else
	{
		node->prev = tail;
		tail->next = node;
		tail = node;
	}
}


polmult::PolList polmult::multiply(PolList list1, PolList list2)
{
	PolList result;
	if (!list1.tail || !list2.tail)
	{
		Pol temp(0, 0);
		Pol* to_add = &temp;
		PolList::Node* node = new PolList::Node(to_add);
		result.head = node;
		result.tail = node;
		return result;
	}
	else
	{
		polmult::PolList::Node* iter1 = list1.head;
		polmult::PolList::Node* iter2 = list2.head;
		while (iter1)
		{
			while (iter2)
			{
				int coef = iter1->info->coef + iter2->info->coef;
				int pow = iter1->info->pow + iter2->info->pow;
				result.add(coef, pow);
				iter2 = iter2->next;
			}
			iter1 = iter1->next;
			iter2 = list2.head;
		}
		result.removeKebab();
		return result;
	}
}
