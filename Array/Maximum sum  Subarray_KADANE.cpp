
#include<cmath>
#include<iostream>
#include<climits>
using namespace std;

int Maximum_Sum_Subarray(int arr[],int n)	//Overall Time Complexity O(n)
{
	int ans = arr[0],sum = 0;
	//Check if all are negative
	for(int i = 1;i < n; ++i)
		ans = max(ans,arr[i]);
	if(ans<0)					//if Max < 0 return Max
		return ans;

    //for atleast one positive no.
	ans = 0;
	for(int i = 0 ;i < n; ++i)
	{
		if(sum + arr[i] > 0)
			sum+=arr[i];
		else
			sum  = 0;
		ans = max(ans,sum);
	}
	return ans;
}
//int main(int argc, char const *argv[]
int main()
{
	int arr[] = {-2,3,-4,2};
	cout<<Maximum_Sum_Subarray(arr,4)<<"\n";
	return 0;
}
