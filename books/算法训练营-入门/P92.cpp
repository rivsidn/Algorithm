#include <iostream>
#include <queue>


static inline int get()
{
	static int i = 0;
}

int main()
{
	int add_round, get_round;

	vector<int> add_ops;
	vector<int> get_ops;

	cin >> add_round >> get_round;
	while (add_round--) {
		int add_op;
		cin >> add_op;
		add_ops.push(add_op);
	}
	while (get_round--) {
		int get_op;
		cin >> get_op;
		get_ops.push(get_op);
	}


	return 0;
}
