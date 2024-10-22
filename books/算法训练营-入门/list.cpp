#include <iostream>
#include <list>

int main()
{
	int round = 0;
	int round_max;

	std::cin >> round_max;
	while (round < round_max) {
		int number;
		int remain;
		list<int> list;
		std::cin >> number;

		/* 队列初始化 */
		for (int i = 1; i <= number; i++)
			list.push_front(i);

		remain = number;
		while (remain > 3) {
			remove_2();
			if (remain > 3) {
			}
			remove_3(list);
		}

		round++;
	}

	return 0;
}
