/* 集合运算 */
#include <iostream>
#include <bitset>
#include <vector>

using namespace std;

const int maxn=10010;
bitset<1010> s[maxn]; //s[x]表示元素 x 所属集合的二进制表示

/*
 * 与下边写法相比，转换了一下思路.
 *
 * 本质是构建一个二维矩阵[m][n]。
 * 1. 第一种写法
 *    m 表示集合中数值
 *    n 表示集合下标
 *    s[x] & s[y] 会获得一个新的bitset 类型，如果不为空表示存
 *    在集合x, y 都设置了.
 * 2. 第二种写法
 *    m 表示集合下标
 *    n 表示集合中数值
 *    需要依次遍历集合，检查s[m][x] s[m][y] 是否都设置了.
 *
 * 相比较而言，如果集合数量大，通过第一种方式，通过检查bitset 是否为0
 * 会有更高效率.
 */
int main()
{
	int N,Q,num,x,y;
	scanf("%d",&N);
	for(int i=1;i<=N;i++){
		scanf("%d",&num);
		while(num--){
			scanf("%d",&x);
			s[x][i]=1;
		}
	}

	scanf("%d",&Q);
	while(Q--){
		scanf("%d%d",&x,&y);
		/* 与运算之后也是bitset() */
		if((s[x]&s[y]).count())//统计与运算后二进制数中 1 的个数
			printf("Yes\n");
		else printf("No\n");
	}

	return 0;
}

#if 0
void build_units(vector<bitset<10000>>& units, int size)
{
	int num;
	bitset<10000> bits;
	while (size--) {
		cin >> num;
		bits[num] = 1;
	}
	units.push_back(bits);
}

int main()
{
	int unit_n;	//集合数量
	int query_n;	//查询次数

	/* 获取集合数量 */
	cin >> unit_n;

	/* 创建集合 */
	vector<bitset<10000>> units;

	/* 构建集合 */
	for (int i=0; i < unit_n; i++) {
		int size;
		cin >> size;
		build_units(units, size);
	}

	/* 获取查询次数 */
	cin >> query_n;

	/* 查询 */
	while (query_n--) {
		int x, y;
		cin >> x >> y;

		int unit_idx;
		/* 遍历集合 */
		for (unit_idx = 0; unit_idx < unit_n; unit_idx++) {
			if (units[unit_idx][x] && units[unit_idx][y])
				break;
		}
		if (unit_idx == unit_n) {
			/* 输出No */
			cout << "ans: No" << endl;
		} else {
			/* 输出Yes */
			cout << "ans: Yes" << endl;
		}
	}

	return 0;
}
#endif
