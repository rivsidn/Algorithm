#include <iostream>
#include <set>

using namespace std;

set<int> sum;
int main()
{
	int x;
	int m;
	int n;
	while(~scanf("%d%d", &n,&m)){
		sum.clear();
		for(int i=0;i<n;i++){
			scanf("%d", &x);
			sum.insert(x);
		}
		for(int j=0;j<m;j++){
			scanf("%d", &x);
			sum.insert(x);
		}
		for(set<int>::iterator it=sum.begin();it!=sum.end();it++){
			/* 这样处理，不会在最后一个数据后留下空格 */
			if(it!=sum.begin())
				printf(" ");
			printf("%d",*it);
		}
		printf("\n");
	}
	return 0;
}

#if 0
int main()
{
	int size_a;
	int size_b;
	set<int> num_set;

	while (cin >> size_a >> size_b) {
		int num;

		num_set.clear();

		while (size_a--) {
			cin >> num;
			num_set.insert(num);
		}
		while (size_b--) {
			cin >> num;
			num_set.insert(num);
		}

		for (set<int>::iterator it = num_set.begin();
			it != num_set.end(); it++) {
			cout << "ans: "<< *it << " ";
		}
		cout << endl;
	}


	return 0;
}
#endif
