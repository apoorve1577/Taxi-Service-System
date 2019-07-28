#include<iostream>
#include<cmath>
using namespace std;
struct node
{
	int x;
	int y;
	node *next[3];
	node *prev[3];
	int disloc;
	int index;

};
struct cars
{
string size;
string ac_type;

};

class cabs
{
  public:
  cars *cc=new cars;
  node *car=new node[7];
  node *new_node=new node[20];
  void null_assign()
  {
  for(int i=1;i<=20;i++)
  {
      for(int j=1;j<=3;j++)
      {
          new_node[i].next[j]=NULL;
          new_node[i].prev[j]=NULL;
      }
  }
  }
  void index()
  {
  for(int i=1;i<=20;i++)
  {
      new_node[i].index=i;
  }
  }
  void index1()
  {
      for(int i=1;i<=20;i++)
      {
          cout<<new_node[i].index<<endl;
      }
  }
int loc,cab_loc,desti;
void create_node()
{
new_node[1].x=0;
new_node[1].y=0;

new_node[2].x=1;
new_node[2].y=0;

new_node[3].x=3;
new_node[3].y=0;

new_node[4].x=4;
new_node[4].y=0;

new_node[5].x=2;
new_node[5].y=0;

new_node[6].x=5;
new_node[6].y=3;

new_node[7].x=9;
new_node[7].y=0;

new_node[8].x=11;
new_node[8].y=11;

new_node[9].x=22;
new_node[9].y=11;

new_node[10].x=19;
new_node[10].y=0;

new_node[11].x=6;
new_node[11].y=0;

new_node[12].x=13;
new_node[12].y=0;

new_node[13].x=35;
new_node[13].y=0;

new_node[14].x=22;
new_node[14].y=16;

new_node[15].x=34;
new_node[15].y=0;

new_node[16].x=22;
new_node[16].y=0;

new_node[17].x=5;
new_node[17].y=0;

new_node[18].x=6;
new_node[18].y=2;

new_node[19].x=11;
new_node[19].y=0;

new_node[20].x=10;
new_node[20].y=0;

}
void graph()
{   //for new_node[1]
	new_node[1].next[1]=&new_node[2];
	new_node[1].next[2]=&new_node[3];
	new_node[1].next[3]=&new_node[4];
	//for &new_node[2]
	new_node[2].next[1]=&new_node[6];
	//for &new_node[3]
	new_node[3].next[1]=&new_node[17];
	//for &new_node[4]
	new_node[4].next[1]=&new_node[20];
	//newnode 5
	new_node[5].next[1]=&new_node[12];
  	//&new_node 6
	new_node[6].next[1]=&new_node[8];
	//&new_node 8
	new_node[8].next[1]=&new_node[9];
	//&new_node 9
	new_node[9].next[1]=&new_node[10];
	//&new_node 10
	new_node[10].next[1]=&new_node[11];
	//&new_node 11
	new_node[11].next[1]=&new_node[16];

	//&new_node 12
	new_node[12].next[1]=&new_node[13];
	//&new_node 13
	new_node[13].next[1]=&new_node[14];
	//&new_node 14
	new_node[14].next[1]=&new_node[15];
	//&new_node 15
	new_node[15].next[1]=&new_node[1];
	//&new_node 16
	new_node[16].next[1]=&new_node[17];
	//&new_node 17
	new_node[17].next[1]=&new_node[18];
	//&new_node 18
	new_node[18].next[1]=&new_node[19];
	//&new_node 19
	new_node[19].next[1]=&new_node[5];
	//new_node 20
	new_node[20].next[1]=&new_node[18];

	// for previous in graphs

	//for new_node[1]
	new_node[1].prev[1]=&new_node[15];

	//for &new_node[2]
	new_node[2].prev[1]=&new_node[1];

	//for &new_node[3]
        new_node[3].prev[1]=&new_node[1];

        //for &new_node[4]
	new_node[4].prev[1]=&new_node[1];

        //&new_node 5
	new_node[5].prev[1]=&new_node[19];

  	//&new_node 6
        new_node[6].prev[1]=&new_node[2];

        //&new_node 7
	new_node[7].prev[1]=&new_node[2];

        //&new_node 8
	new_node[8].prev[1]=&new_node[6];

	//&new_node 9
	new_node[9].prev[1]=&new_node[8];

	//&new_node 10
	new_node[10].prev[1]=&new_node[9];

	//&new_node 11
	new_node[11].prev[1]=&new_node[10];

	//&new_node 12
	new_node[12].prev[1]=&new_node[5];
	//&new_node 13
	new_node[13].prev[1]=&new_node[12];

	//&new_node 14
        new_node[14].prev[1]=&new_node[13];
      //&new_node 15
        new_node[15].prev[1]=&new_node[14];

        //&new_node 16
	new_node[16].prev[1]=&new_node[11];

        //&new_node 17
	new_node[17].prev[1]=&new_node[16];
        new_node[17].prev[2]=&new_node[3];

        //&new_node 18
	new_node[18].prev[1]=&new_node[17];
	new_node[18].prev[2]=&new_node[20];

        //&new_node 19
        new_node[19].prev[1]=&new_node[18];

        //&new_node 20
        new_node[20].prev[1]=&new_node[4];


}

double total_dist=0;

double min_dis=99999;

 int min_loc=0;

double shortest_route(int loc,int desti)
{ 
cout<<loc<<"->";
 if(new_node[loc].next[1]->index!=new_node[desti].index)
 {
     total_dist=total_dist+dist_calculator(&new_node[loc],new_node[loc].next[1]);
     loc=new_node[loc].next[1]->index;
 }
 if(new_node[loc].next[1]->index==new_node[desti].index)
 {
     total_dist=total_dist+dist_calculator(&new_node[loc],&new_node[desti]);
     cout<<loc<<"->"<<desti<<endl;
   cout<<"dist "<<total_dist<<endl;
   return total_dist;
 }
shortest_route(loc,desti);
}
double total_dist1=0;

double shortest_prev(int loc1,int desti)
{ 
cout<<loc1<<"->";
 if(new_node[loc1].prev[1]->index!=new_node[desti].index)
 {
     total_dist1=total_dist1+dist_calculator(&new_node[loc1],new_node[loc1].prev[1]);
     loc1=new_node[loc1].prev[1]->index;
 }
 if(new_node[loc1].prev[1]->index==new_node[desti].index)
 {
     total_dist1=total_dist1+dist_calculator(&new_node[loc1],&new_node[desti]);
     cout<<loc1<<"->"<<desti<<endl;
   cout<<"dist "<<total_dist1<<endl;
   return total_dist1;
 }
shortest_prev(loc1,desti);
}

double dist_calculator(node *g1,node *g2)
{
	double disx,disy,dist;
	disx=(g1->x - g2->x);
	disx=pow(disx,2);
	disy=(g1->y - g2->y);
	disy=pow(disy,2);
	dist=(disx+disy);
	dist=sqrt(dist);
	return dist;
}

int nearest_cab(int loc)
{
	double cab_dist,min=9999;
	int min_loc=0;
	for(int i=1;i<=7;i++)
	{
	  
	  cab_dist=dist_calculator(car[i].next[1],&new_node[loc]);
	  if(cab_dist<min)
	  {
		  min=cab_dist;
		  min_loc=i;
	  }
	}
	double time_cab=(cab_dist/30)*60;
	cout<<"PLEASE WAIT THE CAB WILL BE ARRIVING IN "<<time_cab<<" mins"<<endl;
	return min_loc;
}

void car_loc()
{
	car[1].next[1]=&new_node[1];
    car[2].next[1]=&new_node[2];
	car[3].next[1]=&new_node[3];
	car[4].next[1]=&new_node[4];
    car[5].next[1]=&new_node[5];
	car[6].next[1]=&new_node[6];
	car[7].next[1]=&new_node[7];
}


};
int main()
{
cabs cab;
cab.create_node();
cab.graph();
cab.index();
cab.car_loc();
int loc,drop;
cout<<"enter the pickup location"<<endl;
cin>>loc;
int loc1=loc;
cout<<"enter drop location"<<endl;
cin>>drop;
int ccc=cab.nearest_cab(loc1);
cout<<"the nearest cab is at "<<ccc<<"th "<<"location"<<endl;
cout<<"the ways to reach the destination are as follows"<<endl;
double dnext,dprev=999999;
dnext=cab.shortest_route(loc,drop);
if(loc!=12)
{
dprev= cab.shortest_prev(loc,drop);
}
if(dnext<dprev)
{
 cout<<"hence distance "<<dnext<<" is the shortest distance"<<endl;
}
else
{
cout<<"hence distance "<<dprev<<" is the shortest distance"<<endl;    
}
}
