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

struct edge{
  bool used;
  int p1;
  int p2;
  double distance;
  friend bool operator<(struct edge e1,struct edge e2){
    return (e1.distance < e2.distance);
  };
};

typedef struct point Point;

typedef struct edge Edge;

Point sets[100];

Edge adje[5000];

bool exist[100];

vector<double> MST;

int main(){
  int n = 0, k = 0, rp = 0;
  while (cin>>n>>k)
    {
      rp = 0;
      MST.clear();
      memset(exist, false, sizeof(exist));
      for (int i = 0; i < n; i++)
	cin >> sets[i].x >> sets[i].y;
      for (int i = 0; i < n - 1; i++)
        {
	  for (int j = i + 1; j < n; j++)
            {
	      double tmp;
	      tmp = sqrt((double)(sets[i].x - sets[j].x)*(sets[i].x - sets[j].x) +
			 (sets[i].y - sets[j].y)*(sets[i].y - sets[j].y));
	      adje[rp].distance = tmp;
	      adje[rp].p1 = i;
	      adje[rp].p2 = j;
	      adje[rp++].used = false;
            }
        }
      sort(adje, adje + rp);
      int counter = 1;
      exist[0] = true;
      while (counter<n){
	for (int i = 0; i < rp; i++)
	  {
	    if (!adje[i].used)
	      {
		if (exist[adje[i].p1] ^ exist[adje[i].p2])
		  {
		    MST.push_back(adje[i].distance);
		    adje[i].used = true;
		    exist[adje[i].p1] = true;
		    exist[adje[i].p2] = true;
		    counter++;
		    break;
		  }
	      }
	  }
      }
      sort(MST.begin(), MST.end());
      cout << setprecision(2) << std::fixed << MST[MST.size()-k+1] << endl;
    }
  return 0;
}
