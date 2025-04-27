#include <iostream>
#include <cstring>
#include <set>

#define DEBUG

using namespace std;

bool vis[10005];
multiset<int> s;

int k;//对已删除的进程统计计数

void del(int p){
	if(s.empty()){
		printf("ans: -1\n");
		return;
	}
	if(p==1){ //删除最小成本
		if(vis[k++])
			printf("ans: %d\n",*s.begin());
		s.erase(*s.begin());
	} else { //删除最大成本
		if(vis[k++])
			printf("ans: %d\n",*s.rbegin());
		s.erase(*s.rbegin());
	}
}

int main()
{
	char c;
	int m,n,x,p;

	while(~scanf("%d%d",&m,&n)){
		memset(vis,false,sizeof(vis));
		s.clear();
		for(int i=0;i<n;i++){
			scanf("%d",&x);
			vis[x]=true;
#ifdef DEBUG
			cout << "debug: " << x << endl;
#endif
		}
		p=1;	/* 初始化策略 */
		k=1;
		while(scanf("%c",&c)){
			if(c=='e')	/* 结束 */
				break;
			if(c=='a'){	/* 添加 */
				scanf("%d",&x);
				s.insert(x);
			} else if(c=='p') {	/* 设置管理策略 */
				scanf("%d",&x);
				p=x;
			} else if(c=='r') {	/* 删除 */
				del(p);
			}
		}
		printf("\n");
	}
	return 0;
}
