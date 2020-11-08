#include "node.h"
#include<iostream>
/***********************************************************************
  Задача 6. Да се дефинира шаблон на функция removesub, която приема
  два параметъра first и second — указатели към линейни едносвързани
  списъци. Функцията да изтрива от списъка с начало first
  последователно всички срещания на подсписъци, които съвпадат със
  списъка с начало second. Например, при списък first с елементи 1, 2,
  3, 3, 3, 4, 5, 3, 3, 6 и second с елементи 3, 3, first да се
  преобразува до списъка 1, 2, 3, 4, 5, 6.
************************************************************************/

/***********************************************************************
 РЕШЕНИЕ:
************************************************************************/

template <typename T>
void removesub(node<T>*& first, node<T>* second){
	if(second == nullptr){
    return;
	}
    node<T>* currentFirst = first,
        * previousFirst,
        * currentSecond = second,
        * save;
	bool match = true;
  
	while(currentFirst){
		if (currentFirst->data == second->data) {
			save = currentFirst;

			while (currentFirst && currentSecond) {
				if (currentFirst->data != currentSecond->data) {
					match = false;
				}
				currentFirst = currentFirst->next;
				currentSecond = currentSecond->next;
			}

			if (currentSecond != nullptr) {
				match = false;
			}
			if (match) {
				if (save == first && currentFirst != nullptr) {
					first = currentFirst;
				}
				else if (save == first && currentFirst == nullptr) {
					first = nullptr;
					return;
				}
				else {
					if (currentFirst == nullptr) {
						save = previousFirst;
						save->next = nullptr;
					}
					else {
						save = previousFirst;
						save->next = currentFirst;
					}
				}
			}
			else {
				match = true;
			}
			currentFirst = save;
			currentSecond = second;
		}
		previousFirst = currentFirst;
		currentFirst = currentFirst->next;
	}
}

/***********************************************************************
 КРАЙ НА РЕШЕНИЕТО
************************************************************************/

#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"

/***********************************************************************
  РАЗКОМЕНТИРАЙТЕ СЛЕДВАЩИЯ РЕД, ЗА ДА ВКЛЮЧИТЕ ТЕСТОВЕТЕ
************************************************************************/
#include "prob7_tests.h"

int main ()
{
    // пускане на тестовете
    doctest::Context().run();
    return 0;
}
