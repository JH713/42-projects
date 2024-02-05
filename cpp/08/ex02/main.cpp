#include <iostream>
#include "MutantStack.hpp"


int main(void) {
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
	std::cout << *it << std::endl;
	++it;
	}
	std::stack<int> s(mstack);
	return 0;
}

// #include <list>

// int main() {
//     std::list<int> mlist;
//     mlist.push_back(5);
//     mlist.push_back(17);

//     std::cout << mlist.back() << std::endl; // 맨 뒤의 요소 출력

//     mlist.pop_back(); // 맨 뒤의 요소 제거

//     std::cout << mlist.size() << std::endl; // 사이즈 출력

//     mlist.push_back(3);
//     mlist.push_back(5);
//     mlist.push_back(737);
//     //[...]
//     mlist.push_back(0);

//     // list의 iterator 사용
//     std::list<int>::iterator it = mlist.begin();
//     std::list<int>::iterator ite = mlist.end();
//     ++it;
//     --it;

//     while (it != ite) {
//         std::cout << *it << std::endl;
//         ++it;
//     }

//     // std::stack<int> s(mlist); 

//     return 0;
// }