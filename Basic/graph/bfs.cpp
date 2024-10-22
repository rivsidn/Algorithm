/*
 * 《算法训练营(入门篇)》P75: 骑士移动
 */
#include <iostream>
#include <queue>

#include <string.h>

int visit[300][300];

struct point {
	int x;
	int y;
};
struct moving_point {
	int x;
	int y;
	int step;
};

int dxdy[8][2] = {
	{-2, 1},
	{-2,-1},
	{ 2, 1},
	{ 2,-1},
	{-1, 2},
	{-1,-2},
	{ 1, 2},
	{ 1,-2}
};

static inline bool is_valid_point(int x, int y, int limit)
{
	if (x < 0 || limit <= x)
		return false;
	if (y < 0 || limit <= y)
		return false;
	return true;
}

int bfs(std::queue<moving_point> Q, struct point end, int limit)
{
	while (!Q.empty()) {
		struct moving_point next_mp;
		struct moving_point mp = Q.front(); Q.pop();

		for (int i = 0; i < 8; i++) {
			memset(&next_mp, 0, sizeof(next_mp));
			next_mp.x = mp.x + dxdy[i][0];
			next_mp.y = mp.y + dxdy[i][1];
			next_mp.step = mp.step + 1;

			if (!is_valid_point(next_mp.x, next_mp.y, limit))
				continue;

			if (next_mp.x == end.x && next_mp.y == end.y)
				return next_mp.step;
			if (!visit[next_mp.x][next_mp.y]) {
				Q.push(next_mp);
				visit[next_mp.x][next_mp.y] = 1;
			}
		}
	}
	return -1;
}

int main()
{
	int round = 0;
	int round_max = 0;

	/* 获取测试样例个数 */
	std::cin >> round_max;
	while (round < round_max) {
		int limit = 0;
		struct moving_point start;
		struct point end;

		std::cin >> limit;
		std::cin >> start.x >> start.y;
		std::cin >> end.x >> end.y;
		start.step = 0;

		memset(visit, 0, sizeof(visit));
		if (start.x == end.x && start.y == end.y) {
			std::cout << 0 << std::endl;
			continue;
		}

		std::queue<moving_point> Q;
		Q.push(start);
		visit[start.x][start.y] = 1;

		std::cout << "limit: " << limit << std::endl;
		std::cout << "start: " << start.x << " "<< start.y << std::endl;
		std::cout << "end: " << end.x << " "<< end.y << std::endl;

		int ret = bfs(Q, end, limit);
		if (ret < 0) {
			std::cout << "not found" << std::endl;
		} else {
			std::cout << "ans: " << ret << std::endl;
		}

		while (!Q.empty()) {
			Q.pop();
		}
		round++;
	}

	return 0;
}
