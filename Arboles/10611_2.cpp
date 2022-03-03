#include <iostream>
using namespace std;
long cham[50001];
int BinSearch(long x,long n)
{
 long low=0,high=n-1,mid,max=0,min=0;
 while(low<=high)
	{
	 mid=(low+high)/2;
	 if(x<cham[mid])max=cham[mid],high=mid-1;
	 else if(x>cham[mid])min=cham[mid],low=mid+1;
	 else
		{
		 if(mid!=n-1)max=cham[mid+1];
		 if(mid!=0)min=cham[mid-1];
		 break;
		}
	}
  if(max==0)printf("%ld X\n",min);
  else if(min==0)printf("X %ld\n",max);
  else printf("%ld %ld\n",min,max);
return 0;
}

int main()
{
 long n,q,luchu,i;
 scanf("%ld",&n);

 for(i=0;i<n;i++)
	 scanf("%ld",&cham[i]);

 scanf("%ld",&q);
 while(q--)
	{
	 scanf("%ld",&luchu);
	 BinSearch(luchu,n);
	}

    return 0;
}
