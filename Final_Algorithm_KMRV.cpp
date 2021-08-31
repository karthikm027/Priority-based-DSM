

#include <stdio.h>
#include<iostream>
using namespace std;

int knapsack (int budget, int power[], int priority[], int n) 
{
int dp[n + 1][budget + 1];
int zeroOne[n + 1][budget + 1], i, j;
int result[n];
for (int i = 0; i <= n; i++)
{
    for (int j = 0; j <= budget; j++)
    {dp[i][j] = 0;
    zeroOne[i][j] = 0;
    } 
} 
for (i = 0; i <= n; i++)
{
    zeroOne[i][0] = 1;
}
for (int i = 1; i <= n; i++)
{
    for (int j = 1; j <= budget; j++)
    {
        if (power[i - 1] > j)
        {
            dp[i][j] = dp[i - 1][j];
            zeroOne[i][j] = zeroOne[i - 1][j];
            }
        else
        {
            dp[i][j] = max (priority[i - 1] + dp[i - 1][j - power[i - 1]],dp[i - 1][j]);
            zeroOne[i][j] = zeroOne[i - 1][j] || zeroOne[i - 1][j - power[i - 1]];
        }
    }
    
}

for (i = 0; i < n; i++)
{
    result[i] = 0;
}
int r = n;
int c = budget;
int aAscii=65;
while (r > 0 && c > 0)
{
    if (dp[r][c] == dp[r - 1][c])
    {
        r--;
        
    }
    else
    {
        result[r - 1] = 1;
        c = c - power[r - 1];
        r--;
    }
    
}
cout<<endl<<endl<<endl;
cout<<"-------------------------------Appliances that are currently running-----------------------------------------"<<endl;
for (i = 0; i < n; i++)
{
    if (result[i])
	{
	    cout << "Load " << (char)(aAscii+i) <<" of power rating "<<power[i]<< "W is running...!!" << endl;
	}
}
return 0;
    
}

int main () 
{
    int budget,n;
    cout<<"Enter the number of appliances  : ";
    cin>>n;
    cout<<"Enter the maximum power limit in watts  : ";
    cin>>budget;
    int power[n];
    int priority[n];
    int temporaryPriorityArray[n];
    int prior;
    int individualPower;
    int asciiOfA=65;
    int ans[n];
    for(int i=0;i<n;i++){

        cout<<"Enter the power rating of Load "<<(char)asciiOfA<<" in watts  : ";
        
        cin>>individualPower;
        if (individualPower<=0 || individualPower>=budget){
            cout<<"Enter a proper power rating of the machine, it must be between 1W and " <<budget <<", try again by rerunning the program";
            return 0;
        }
        else{
            power[i]=individualPower;
        }
        cout<<"Enter the priority of Load : "<<(char)asciiOfA;
        cin>>prior;
        if(prior>=1 && prior<=n){temporaryPriorityArray[i]=prior;}
        else{cout<<"Enter a proper priority.....!!! It must be between 1 and "<<n;return 0;}
        asciiOfA++;

    }
    for(int i=0;i<n;i++){
        priority[i]=n-temporaryPriorityArray[i]+1;
    }
    
    int answer = knapsack (budget, power, priority, n);
    
    cout<<"\nAppliances are chosen by maximizing their priority such that total power is below the limit.\n";
    cout<<"Project done by :\n";
    cout<<"1.Karthik M \n2.Manjunath M \n3.Ravinandan K \n4.Vinayak Aski \n Guided by : Prof. Madhusudan J \n Thank you.";
    
    
} 
