#include<bits/stdc++.h>  
using namespace std;   
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef double db;
typedef long double ld;
typedef pair<int,int> PII;
typedef pair<ll,int> Pli;
typedef pair<ll,ll> Pll;
typedef vector<int> VI;
typedef vector<PII> VII;
#define rep(i,a,b) for(int i=(int)a;i<=(int)b;i++)
#define per(i,a,b) for(int i=(int)a;i>=(int)b;i--)
#define REP(i,n) for(int i=0;i<n;++i)




int main(int argc,char* argv[])
{
ifstream file_pointer;
file_pointer.open(argv[1]);

int tanu_house;
file_pointer>>tanu_house;

int total_number_of_roads;
file_pointer>>total_number_of_roads;

int x=total_number_of_roads;
int arr[100][100];

REP(i,100)
 {REP(j,100)
 {arr[i][j]=0;}}
/*in intital case all we assume no road exist b/w i and j*/
int from_village,to_village;

while(x--)
{
  file_pointer>>from_village>>to_village;
/*making an undirectional road between the village numbers to_village and from_village*/
arr[from_village][to_village]=to_village;

arr[to_village][from_village]=from_village;

}

 



 
  int parent_vertex[100];

 queue<int> verticesqueue;


	bool truth_of_vertices[100];
//initializing the rest of elements except the source as we will assume that the source is already visited. 
	REP(i,100) 
  {
		truth_of_vertices[i] = false;

	

		parent_vertex[i] = -1;

	}

	truth_of_vertices[0] = true;

	verticesqueue.push(0);
int front_element;
	/*we could have used any algorithm. but since BFS is the most simple,i used BFS.*/
	while (!verticesqueue.empty()) {
		front_element = verticesqueue.front();
		verticesqueue.pop();
		REP(i,100) {
			if (truth_of_vertices[arr[front_element][i]] == false)
       {
				truth_of_vertices[arr[front_element][i]] = true;

				

				parent_vertex[arr[front_element][i]] = front_element;

				verticesqueue.push(arr[front_element][i]);

				
					
	}
		}
	}
	VI parents_list;
	int y = tanu_house;
  //this while loop will recursivelly add the number's parents to the vector path
	parents_list.push_back(y);
	while (parent_vertex[y] != -1) {

		parents_list.push_back(parent_vertex[y]);

		y = parent_vertex[y];
	}

	
  VI pathfromsource;
	per(i,(parents_list.size()-1),0)
		{
    pathfromsource.push_back(parents_list[i]);

    //reason we are using a vector is because,we need to reverse the array as we want the order from son to father,and NOT from father to son.
    }

    int z;
    int q,w,r,t;

      ofstream output_file_ts;

  output_file_ts.open("directions.txt");
  

    REP(i,(pathfromsource.size()-1))
    {
      q=(pathfromsource[i]%10);    //y coordinate

    w=(pathfromsource[i]/10);   //x coordinate

    r=(pathfromsource[i+1]%10);   //y coordinate

    t=(pathfromsource[i+1]/10);   //x coordinate

  /*suppose the number is 23. so we will get the x coordinate by diving 23 by 10,and we will get the y coordinate by taking remainder of 23. so thats what we azre primarily checking in the code below.*/

   if(t==w-1)
   {output_file_ts<<"move west"<<endl;}
   if(t==w+1)
   {output_file_ts<<"move east"<<endl;}
   /*let us suppose the the coordinates of the two roads are 23 and 24. then  it mean tanu will have to jump 1 unit up to the north as y coordinate is increasing by 1. thats what exactly we are checking here.*/
   if(r==q-1)
   {output_file_ts<<"move south"<<endl;}
   if(r==q+1)
   {output_file_ts<<"move north"<<endl;}

    }


}
