#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;


int main() {
	int t;
	cin>>t;
	while(t--){
	    long long m,n,k;
	    cin>>n;
	    long long arr[n];
	    vector <int> v1,v2;
	    long long answer=0;
	    for (long long i = 0; i < n; i++) {
	            cin>>m;
	            if(m%2!=0)arr[i]=0;
	            
	            else if(m%4==0){arr[i]=2;v2.push_back(i);}
	            
	            else {arr[i]=1;v1.push_back(i);}
	            
	        }
	        
	        for (long long i = 0; i < n; i++) {
	            if(arr[i]==2)answer+=n-i;
	            
	            else if(arr[i]==1){
	                long long pos;
	                auto lower1=lower_bound(v1.begin(),v1.end(),i);
	                if(*lower1==v1[v1.size()-1]){
	                    auto lower2=lower_bound(v2.begin(),v2.end(),i);
	                    if(lower2!=v2.end()){
	                        pos=*lower2;
	                    }
	                    else pos=n;
	                }
	                else{
	                    lower1++;
	                    auto lower2=lower_bound(v2.begin(),v2.end(),i);
	                    if(lower2!=v2.end()){
	                        pos=min(*lower1,*lower2);
	                    }
	                    else pos=*lower1;
	                }
	                   answer+=n-pos;
	                
	            }
	            
	            else{
	                long long zeros=0;
	                while(arr[i]==0&&i<n){
	                    zeros++;
	                    i++;
	                }
	                if(i==n){
	                    answer+=zeros*(zeros+1)/2;
	                }
	                else{
	                    if(arr[i]==2)answer+=((zeros+n-i)*zeros)-(zeros*(zeros-1)/2);
	                    
	                    else if(arr[i]==1){
	                        long long pos;
        	                auto lower1=lower_bound(v1.begin(),v1.end(),i);
        	                if(*lower1==v1[v1.size()-1]){
        	                    auto lower2=lower_bound(v2.begin(),v2.end(),i);
        	                    if(lower2!=v2.end()){
        	                        pos=*lower2;
        	                    }
        	                    else pos=n;
        	                }
        	                else{
        	                    lower1++;
        	                    auto lower2=lower_bound(v2.begin(),v2.end(),i);
        	                    if(lower2!=v2.end()){
        	                        pos=min(*lower1,*lower2);
        	                    }
        	                    else pos=*lower1;
        	                }
        	                if(pos<n)answer+=((zeros+n-pos)*zeros)-(zeros*(zeros-1)/2);
	                        else{
	                            answer+=zeros*(zeros+1)/2;
	                        }
	                    }
	                }
	                i--;
	            }
	            //cout<<answer<<" ";
	        }
	        
	    cout<<answer<<"\n";
	}
	return 0;
}