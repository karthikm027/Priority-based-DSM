

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
  
 
// for (int i = 0; i <= n; i++)
// {
//     for (int j = 0; j <= budget; j++)
//     {
//         cout << dp[i][j] << "  ";
        
//     } 
// cout << endl;
    
// } 
 
for (i = 0; i < n; i++)
{
    result[i] = 0;
}
int r = n;
int c = budget;
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
	    cout << "Appliance." << i + 1 <<" of power rating "<<power[i]<< "W is running...!!" << endl;
	    
	}
    
}
return dp[n][budget];
    
}

int main () 
{
    // int budget = 5000;
    // int power[4] = { 1800, 1500, 700, 2000 };
    // int priority[4] = { 1, 4, 2, 3 };
    // int n = 4;
    int budget,n;
    cout<<"Enter the number of appliances  : ";
    cin>>n;
    cout<<"Enter the maximum power limit in watts  : ";
    cin>>budget;
    int power[n];
    int priority[n];
    int prior;
    for(int i=0;i<n;i++){
        cout<<"Enter the power rating of "<<i+1<<"th appliance in watts  : ";
        cin>>power[i];
    }
    cout<<"\nEnter the priority for each appliance, should be between 1 and "<<n<<"1 being lowest priority and N being highest\n";
    for(int i=0;i<n;i++){
        cout<<"Enter the priority of "<<i+1<<" th appliance : ";
        cin>>prior;
        if(prior>=1 && prior<=n){priority[i]=prior;}
        else{cout<<"Enter a proper priority.....!!!";}
    }
    
    int answer = knapsack (budget, power, priority, n);
    cout<<"\nAppliances are chosen by maximizing their priority such that total power is below the limit.\n";
    cout<<"Project done by :\n";
    cout<<"1.Karthik M \n2.Manjunath M \n3.Ravinandan K \n4.Vinayak Aski \nThank you.";
    // cout << endl;
    // cout << answer;
    
} 
