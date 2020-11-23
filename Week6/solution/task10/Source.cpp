#include <vector>

#include "node.h"

/***********************************************************************
  Задача 2. Даден е вектор v от цели числа. Казваме, че двоичното
  дърво с положителни числа по върховете t представя v при следните
  условия:

	* v е празният вектор и t е празното дърво; или
	* ако v = v[0],…,v[k-1], a m = ⌊k / 2⌋ (долна цяла част), то коренът
	на t съдържа числото v[m], лявото поддърво на t представя вектора
	v[0],…,v[m-1], а дясното поддърво на t представя вектора
	v[m+1],…,v[k-1].

  Забележка: ако k = 2, то десния подвектор считаме за празен.

  Нека е даден следният шаблонът Node, дефиниран в node.h.
************************************************************************/

/***********************************************************************
  а) Да се реализира функция, която построява дърво, представящо
  вектора v, и връща указател към корена му.

  Упътване: Ако v е вектор, то с помощта на следния конструктор
  std::vector<unsigned> L(v.begin(), v.begin() + count) ще получите
  първите count елемента от v,
  а с std::vector<unsigned> R (v.begin() + start, v.end()), ще
  получите суфикса на v, започващ от елемента с индекс start.

  Пример:
  std::vector<unsigned> v{1, 2, 3, 4, 5, 6},
						L(v.begin(), v.begin() + 3),
						R(v.begin() + 4, v.end());

  Тогава L е векторът 1, 2, 3, а R е векторът 5, 6.

 РЕШЕНИЕ:
************************************************************************/

Node<unsigned>* buildTreeHelper(unsigned data, std::vector<unsigned>& left, std::vector<unsigned>& right) {
	if (left.empty() && right.empty()) {
		
		return new Node<unsigned>(data);
	}
	else if (left.empty()) {
		
		unsigned temp = right[0];
		
		right.erase(right.begin());
		
		return new Node<unsigned>(data, nullptr, buildTreeHelper(temp, left, right));
	}
	else if (right.empty()) {
		
		unsigned temp = left[left.size() - 1];
		
		left.erase(left.end() - 1);

		return new Node<unsigned>(data, buildTreeHelper(temp, left, right), nullptr);
	}
	else {
		unsigned tempL = left[left.size() / 2],
			     tempR = right[right.size() / 2];
		
		std::vector<unsigned> LL(left.begin(), left.begin() + left.size() / 2),
			                  LR(left.begin() + left.size() / 2 + 1, left.end()),
			                  RL(right.begin(), right.begin() + right.size() / 2),
			                  RR(right.begin() + right.size() / 2 + 1, right.end());

		return new Node<unsigned>(data, buildTreeHelper(tempL, LL, LR), buildTreeHelper(tempR, RL, RR));
	}
}

Node<unsigned>* buildTree(const std::vector<unsigned>& v) {
	if (v.size() == 0) {
		return nullptr;
	}
	std::vector<unsigned> L(v.begin(), v.begin() + v.size() / 2);
	std::vector<unsigned> R(v.begin() + v.size() / 2 + 1, v.end());

	return buildTreeHelper(v[v.size() / 2], L, R);
}

/***********************************************************************
 б) Да се реализира функция, която връща вектор, съставен от възлите
 по път в дървото от корен до листо, в който сумата на елементите е
 максимална.

 РЕШЕНИЕ:
************************************************************************/

std::vector<unsigned> sumMaxHelper(Node<unsigned>* current, std::vector<unsigned> result, unsigned currentSum = 0) {
	if (current == nullptr) {
		return std::vector<unsigned>();
	}
	else if (current->left == nullptr && current->right == nullptr) {
		result.push_back(current->data);
		return result;
	}
	if (current->left == nullptr) {
		result.push_back(current->data);
		return sumMaxHelper(current->right, result, currentSum + current->data);
	}
	else if (current->right == nullptr) {
		result.push_back(current->data);
		return sumMaxHelper(current->left, result, currentSum + current->data);
	}
	else {
		result.push_back(current->data);
		std::vector<unsigned> leftResult = sumMaxHelper(current->left, result, currentSum + current->data);
		std::vector<unsigned> rightResult = sumMaxHelper(current->right, result, currentSum + current->data);
		unsigned leftResultSum = 0, rightResultSum = 0;
		for (unsigned element : leftResult) leftResultSum += element;
		for (unsigned element : rightResult) rightResultSum += element;
		if ( leftResultSum < rightResultSum) {
			return rightResult;
		}
		return leftResult;
	}
}

std::vector<unsigned> sumMax(Node<unsigned>* t) {

	if (t == nullptr) {
		return std::vector<unsigned>();
	}
	
	return sumMaxHelper(t, std::vector<unsigned>{});
}

/***********************************************************************
 КРАЙ НА РЕШЕНИЕТО
************************************************************************/

#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"

/***********************************************************************
  РАЗКОМЕНТИРАЙТЕ СЛЕДВАЩИЯ РЕД, ЗА ДА ВКЛЮЧИТЕ ТЕСТОВЕТЕ
************************************************************************/
#include "prob_tests.h"

int main()
{
	// пускане на тестовете
	doctest::Context().run();
	return 0;
}
