#include "node.h"

/***********************************************************************
  Задача 3. Да се дефинира шаблон на булева функция dupsub, която
  приема два параметъра: указател към линеен едносвързан списък и
  неотрицателно число k. Функцията да връща истина, ако в списъка има
  поне два различни подсписъка с дължина k, които са с еднакви
  елементи. Примери за такива списъци са 1, 2, 3, 4, 1, 2, 5 и 1, 2,
  3, 3, 3, 4 за k = 2.
************************************************************************/

/***********************************************************************
 РЕШЕНИЕ:
************************************************************************/

template<typename T>
size_t size(node<T>* n)
{
	size_t result = 0;
	while(n != nullptr)
	{
		n = n->next;
		result++;
	}
	return result;
}

template <typename T>
bool dupsub(node<T>* l, unsigned k)
{
	// 1, 2, 2, 3, 2, 2, 7
	int lSize = size(l);
	if(l == nullptr || lSize < 2 * k)
	{
		return false;
	}

    node<T>* kThPos = l;
	int lPosition = 0, counter = k;
	
	while(counter != 0)
	{
		kThPos = kThPos->next;
		counter--;
	}
	
	while(lPosition < (lSize - k))
	{
		node<T>* temp = kThPos;
		counter = lPosition + k;
		while (counter < lSize)
		{
			if (l->data == temp->data)
			{
				node<T>* save1 = l, * save2 = temp;
				int cnt = 0;
				while (save1 != nullptr && save2 != nullptr)
				{
					if (save1->data != save2->data)
					{
						break;
					}
					cnt++;
					save1 = save1->next;
					save2 = save2->next;
				}
				if (cnt >= k)
				{
					return true;
				}
			}
			temp = temp->next;
			counter++;
		}
		lPosition++;
		l = l->next;
		kThPos = kThPos->next;
	}
	
	return false;
}

/***********************************************************************
 КРАЙ НА РЕШЕНИЕТО
************************************************************************/

#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"

/***********************************************************************
  РАЗКОМЕНТИРАЙТЕ СЛЕДВАЩИЯ РЕД, ЗА ДА ВКЛЮЧИТЕ ТЕСТОВЕТЕ
************************************************************************/
#include "prob5_tests.h"

int main ()
{
    // пускане на тестовете
    doctest::Context().run();
    return 0;
}
