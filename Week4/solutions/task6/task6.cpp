#include "node.h"

/***********************************************************************
  Задача 5. Да се дефинира функция removedups, която приема като
  единствен параметър указател към линеен едносвързан списък от цели
  числа, наредени в ненамаляващ ред. Функцията да изтрива всички
  повторения на елементи в списъка, така че всеки от оригиналните му
  елементи да се среща само веднъж, така че елементите на списъка да
  образуват строго растяща редица. Задачата да се реши без използване
  на помощна структура от данни (с константна сложност по памет).
************************************************************************/

/***********************************************************************
 РЕШЕНИЕ:
************************************************************************/

void removedups(node<int>* l){
    node<int>* current = l,
        * save = l;
	if (current == nullptr) {
      return;
	}
	else
	{
		while (current->next) {
			if (current->data != current->next->data) {
				save->next = current->next;
				save = current->next;
			}
			current = current->next;
		}
	}
	save->next = nullptr;
}

/***********************************************************************
 КРАЙ НА РЕШЕНИЕТО
************************************************************************/

#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"

/***********************************************************************
  РАЗКОМЕНТИРАЙТЕ СЛЕДВАЩИЯ РЕД, ЗА ДА ВКЛЮЧИТЕ ТЕСТОВЕТЕ
************************************************************************/
#include "prob6_tests.h"

int main ()
{
    // пускане на тестовете
    doctest::Context().run();
    return 0;
}
