#include <iostream>
#include <queue>

int main(int argc, char *argv[])
{
	int add_cnt;
	std::vector<int> add_ops;
	int get_cnt;
	std::vector<int> get_ops;

	/* 获取第一行输入，add/get操作次数 */
	std::cin >> add_cnt >> get_cnt;

	/* 获取add输入到向量表中 */
	while (add_cnt--) {
		int add;
		std::cin >> add;
		add_ops.push_back(add);
	}
	/* 获取get输入到向量中 */
	while (get_cnt--) {
		int get;
		std::cin >> get;
		get_ops.push_back(get);
	}

	/*
	 * 准备两个优先级队列q1/q2.
	 * q1是最大堆，存储前(i-1)个最小值，新输入的值与top()比较，
	 * 如果小于top()，即当前的最大值，则加入到q1中；将top()加入到
	 * q2中.
	 * q2是最小堆，top()为第i 个最小值.
	 */
	std::priority_queue<int> q1;
	std::priority_queue<int, std::vector<int>, std::greater<int>> q2;
	int add_id = 0;
	int get_id = 0;
	int count = 0;
	while (get_id < get_ops.size()) {
		if (get_ops[get_id] != 0)
			break;
		get_id++;
	}

	/* get_id 有两种情况，1.越界 2.有效 */

	while (add_id < add_ops.size()) {
		int add = add_ops[add_id];
		if (!q1.empty() && add < q1.top()) {
			q1.push(add);
			q2.push(q1.top());
			q1.pop();
		} else {
			q2.push(add);
		}
		/* 注意递加操作 */
		add_id++;
		count++;

		/* get_ops[] 中存储的是第几个数时获取数 */
		while (get_id < get_ops.size()) {
			if (get_ops[get_id] > count)
				break;
			if (get_ops[get_id] < count) {
				//ERROR
				std::cout << "ERROR" << std::endl;
				break;
			}
			if (q2.empty()) {
				//ERROR
				std::cout << "ERROR" << std::endl;
				break;
			}
			std::cout << q2.top() << std::endl;
			q1.push(q2.top());
			q2.pop();

			get_id++;
		}
	}

	return 0;
}
