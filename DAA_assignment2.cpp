#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;

int main(){
    // Q1
    vector<int> s={1,3,0,5,8,5},f={2,4,6,7,9,9};
    vector<pair<int,int>> a;
    for(int i=0;i<s.size();i++) a.push_back({f[i],s[i]});
    sort(a.begin(),a.end());
    int cnt=0,last=-1;
    vector<pair<int,int>> sel;
    for(auto &x:a){
        if(x.second>=last){
            cnt++;
            sel.push_back({x.second,x.first});
            last=x.first;
        }
    }
    cout<<"max no of activities = "<<cnt<<"\n selected activities: ";
    for(auto &x:sel) cout<<"("<<x.first<<","<<x.second<<") ";
    cout<<"\n\n";

    // Q2 
    vector<int> at={900,910,920,1100,1120},dt={940,1200,950,1130,1140};
    sort(at.begin(),at.end());
    sort(dt.begin(),dt.end());
    int i=0,j=0,plat=0,ans=0;
    while(i<at.size()){
        if(at[i]<dt[j]){
            plat++;
            ans=max(ans,plat);
            i++;
        }else{
            plat--;
            j++;
        }
    }
    cout<<"min no of platforms required = "<<ans<<"\n\n";

    // Q3 
    vector<int> val={100,60,120},wt={20,10,40};
    int W=50;
    vector<pair<double,int>> v;
    for(int i=0;i<val.size();i++) {
        v.push_back({(double)val[i]/wt[i],i});
    }
    sort(v.rbegin(),v.rend());
    double res=0;
    for(auto &x:v){
        int i=x.second;
        if(W>=wt[i]){
            W-=wt[i];
            res+=val[i];
        }else{
            res+=x.first*W;
            break;
        }
    }
    cout<<"max value = "<<(int)res<<"\n\n";

    // Q4 
    vector<string> jobs={"J1","J2","J3","J4","J5"};
    vector<int> d={2,1,2,1,3},p={100,19,27,25,15};
    vector<int> idx(jobs.size());
    for(int i=0;i<idx.size();i++) idx[i]=i;
    sort(idx.begin(),idx.end(),[&](int a,int b){return p[a]>p[b];});
    vector<int> slot(4,-1);
    int prof=0;
    vector<string> done;
    for(int i:idx){
        for(int j=d[i];j>0;j--){
            if(slot[j]==-1){
                slot[j]=i;
                prof+=p[i];
                done.push_back(jobs[i]);
                break;
            }
        }
    }
    cout<<"Selected Jobs: ";
    for(auto &x:done) cout<<x<<" ";
    cout<<"\nMaximum Profit = "<<prof<<"\n\n";

    // Q5
    vector<char> ch={'a','b','c','d','e','f'};
    vector<int> fr={5,9,12,13,16,45};
    priority_queue<pair<int,string>,vector<pair<int,string>>,greater<>> pq;
    for(int i=0;i<ch.size();i++) pq.push({fr[i],string(1,ch[i])});
    vector<string> code(256,"");
    while(pq.size()>1){
        auto a=pq.top();pq.pop();
        auto b=pq.top();pq.pop();
        for(char c:a.second) code[c]="0"+code[c];
        for(char c:b.second) code[c]="1"+code[c];
        pq.push({a.first+b.first,a.second+b.second});
    }
    cout<<"Character Huffman Code\n";
    for(char c:ch) cout<<c<<" "<<code[c]<<"\n";
}
