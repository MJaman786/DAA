#include<iostream>
using namespace std;

void knapscack(int num, float profit[], float weight[], float cap){
	int recap = cap;
	profit[num], weight[num];
	float solution[num];
	float totalprofit = 0.0, totalweight = 0.0;
	int i;
	for(i=0; i<num; i++){
		solution[i] = 0.0;
	}
	for(i=0; i<num; i++){
		if(weight[i]>recap){
			break;
		}
		solution[i] = 1.0;
		recap = recap - weight[i];
	}
	if(i<num){
		solution[i] = recap/weight[i];
	}
	for(int i=0; i<num; i++){
		profit[i] = profit[i] * solution[i];
		weight[i] = weight[i] * solution[i];
	}
	for(int i=0; i<num; i++){
		totalprofit += profit[i];
		totalweight += weight[i];
	}
	cout<<"\nMaximum profit : "<<totalprofit<<endl;
	cout<<"\nMaximum weight : "<<totalweight<<endl;
}

int main(){
	
	int num;
	cout<<"Enter number of items : ";
	cin>>num;
	
	
	float profit[num];
	cout<<"\nEnter the profits of items : ";
	for(int i=0; i<num; i++){
		cin>>profit[i];
	}
	
	float weight[num];
	cout<<"\nEnter the weights of items : ";
	for(int i=0; i<num; i++){
		cin>>weight[i];	
	}
	
	float capacity;
	cout<<"\nEnter capacity of Knapscack : ";
	cin>>capacity;
	
	float profit_weight[num];
	for(int i=0; i<num; i++){
		profit_weight[i] = profit[i]/weight[i];
	}
	
	//sorting profit_weight in descending order
	int temp;
	for(int i=0; i<num-1; i++){
		for(int j=0; j<num-1-i; j++){
				if(profit_weight[j]<profit_weight[j+1]){
					temp = profit_weight[j];
					profit_weight[j] = profit_weight[j+1];
					profit_weight[j+1] = temp;
					
					temp = profit[j];
					profit[j] = profit[j+1];
					profit[j+1] = temp;
					
					temp = weight[j];
					weight[j] = weight[j+1];
					weight[j+1] = temp;
				}
		}
	}
	
	cout<<"| Items  |  PT |  Wt  |	P/WT	|\n";
	for(int i=0; i<num; i++){
		cout<<"| I - "<<i<<"  |  "<<profit[i]<<"  |   "<<weight[i]<<"  |  "<<profit_weight[i]	<<"	|"<<endl; 
	}
	
	knapscack(num, profit, weight, capacity);
	
	return 0;
}
/*
------ output -------

aman@aman-Latitude-E5470:~$ g++ fknap.cpp -o fknap.out
aman@aman-Latitude-E5470:~$ ./fknap.out
Enter number of items : 5

Enter the profits of items : 10 15 10 12 8

Enter the weights of items : 3 3 2 5 1

Enter capacity of Knapscack : 10
| Items  |  PT  |  Wt  |P/WT |
| I - 0  |  8   |   1  |  8	 |
| I - 1  |  15  |   3  |  5	 |
| I - 2  |  10  |   2  |  5	 |
| I - 3  |  10  |   3  |  3	 |
| I - 4  |  12  |   5  |  2	 |

Maximum profit : 45.4

Maximum weight : 10
*/
