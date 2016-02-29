#include <iostream>
#include <stack>
using namespace std;

int n;
string nums;
bool isMine[100000+10]={false}, have=false;

int alreadyHave(int cur){
    int res = 0;
    res += isMine[cur];
    if(cur>0)
        res += isMine[cur-1];
    if(cur<n-1)
        res += isMine[cur+1];
    return res;
}

bool canPut(int cur){
    if(nums[cur]=='*')
        return true;
    else
        return ('0' + alreadyHave(cur) ) <= nums[cur];
}

bool exactPut(int cur){
    if(nums[cur]=='*')
        return true;
    else
        return ('0' + alreadyHave(cur) ) == nums[cur];
}

void dfs(int cur){
    if(have)
        return;
    if(cur<0){
        have = exactPut(0);
        return;
    }
    isMine[cur] = true;
    if((cur == n-1 and canPut(cur))
       or (cur<n-1 and exactPut(cur+1)) )
        dfs(cur-1);

    if(have) return;

    isMine[cur] = false;
    if((cur == n-1 and canPut(cur))
       or (cur<n-1 and exactPut(cur+1)) )
        dfs(cur-1);
    return;
}

int main()
{
    int ans = 0;
	cin >> n >> nums;
    dfs(n-1);
    
	for (int i = 0; i < n; ++i){
        if(isMine[i]) ans++;
    }
    cout<<ans<<endl;
    
	for (int i = 0; i < n; ++i){
        cout<<isMine[i];
    }
    
	return 0;
}
