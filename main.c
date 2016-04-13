#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
#include <iomanip>
#include<cstring>

using namespace std;

struct point
{
  int x;
  int y;
};

struct edge
{
  bool used;//是否访问过
  int p1;//第一个点
  int p2;//第二个点
  double distance;//两点间的距离
  friend bool operator<(struct edge e1,struct edge e2)
  {
      return (e1.distance < e2.distance);//比较两个边界的长度，如果第二个边界长，返回true
  };
};

typedef struct point Point;

typedef struct edge Edge;

Point sets[100];

Edge adje[5000];

bool exist[100];

vector<double> MST;//存放两点间的距离

int main()
{
	int n = 0,//点的个数
		k = 0, rp = 0;
	cout<<"please input two ints"<<endl;
	while (cin>>n>>k)
	{
		rp = 0;
		MST.clear();
		memset(exist, false, sizeof(exist));//在一段内存块中填充某个给定的值，它是对较大的结构体或数组进行清零操作的一种最快方法
		for (int i = 0; i < n; i++)
			cin >> sets[i].x >> sets[i].y;//输入点的横纵坐标
		for (int i = 0; i < n - 1; i++)
		{
		    for (int j = i + 1; j < n; j++)
			{
				double tmp;
				tmp = sqrt((double)(sets[i].x - sets[j].x)*(sets[i].x - sets[j].x) +
					(sets[i].y - sets[j].y)*(sets[i].y - sets[j].y));//两点间的距离
				adje[rp].distance = tmp;
				adje[rp].p1 = i;
				adje[rp].p2 = j;
				adje[rp++].used = false;
			}
		}
		sort(adje, adje + rp);//排序
		int counter = 1;
		exist[0] = true;
		while (counter<n)//如果n>1
			for (int i = 0; i < rp; i++)
				if (!adje[i].used)
					if (exist[adje[i].p1] ^ exist[adje[i].p2])
					{
						MST.push_back(adje[i].distance);//vector的push_back：将元素插入至最尾端
						adje[i].used = true;
						exist[adje[i].p1] = true;
						exist[adje[i].p2] = true;
						counter++;
						break;
					}
		sort(MST.begin(), MST.end());
		cout << setprecision(2)<< std::fixed << MST[MST.size()-k+1] << endl;//输出第k个两点间的距离
	}
	return 0;
}
