/* 《算法训练营(入门篇)》 P89 ： 度度熊学队列*/
#include <iostream>
#include <deque>

/* 双向队列指针 */
std::deque<int> **deques = NULL;

static inline int uv2index(int num)
{
	return num-1;
}

/* 访问双向队列指针 */
void ops_1()
{
	int u, is_back, val;
	std::cin >> u >> is_back >> val;

	int index;

	index = uv2index(u);
	if (is_back) {
		deques[index]->push_back(val);
	} else {
		deques[index]->push_front(val);
	}
}
void ops_2()
{
	int u, is_back;
	std::cin >> u >> is_back;

	int index;
	index = uv2index(u);
	if (deques[index]->empty()) {
		std::cout << "is empty" << std::endl;
		return;
	}
	int result;
	if (is_back) {
		result = deques[index]->back();
		deques[index]->pop_back();
	} else {
		result = deques[index]->front();
		deques[index]->pop_front();
	}
	std::cout << "result: " << result << std::endl;
}
void ops_3()
{
	int u, v, is_reverse;
	std::cin >> u >> v >> is_reverse;
	int uindex, vindex;

	uindex = uv2index(u);
	vindex = uv2index(v);

	if (is_reverse) {
		deques[uindex]->insert(deques[uindex]->end(), deques[vindex]->rbegin(),
				deques[vindex]->rend());
	} else {
		deques[uindex]->insert(deques[uindex]->end(), deques[vindex]->begin(),
				deques[vindex]->end());
	}
	deques[vindex]->clear();
}

int main()
{
	int N, rounds;

	std::cin >> N;
	std::cin >> rounds;

	/* new() 双向队列 */
	deques = new std::deque<int>*[N];
	for (int i = 0; i < N; i++) {
		deques[i] = new std::deque<int>();
	}

	while (rounds--) {
		int ops;
		std::cin >> ops;

		switch (ops) {
			case 1:
				ops_1();
				break;
			case 2:
				ops_2();
				break;
			case 3:
				ops_3();
				break;
			default:
				//ERROR
				break;
		}
	}

	return 0;
}
