#include <bits/stdc++.h>

using namespace std;



set<int> operator|(set<int>s1, set<int>s2)
{
    set <int>unionset;
    set_union(s1.begin(),s1.end(),s2.begin(),s2.end(),::inserter(unionset,unionset.begin()));
    return unionset;
}

set<int> operator&(set<int>s1,set<int>s2)
{
    set<int> intersectset;
    set_intersection(s1.begin(),s1.end(),s2.begin(),s2.end(),::inserter(intersectset,intersectset.begin()));
    return intersectset;
}

map< int ,set<int> >mp;
map< set<int> ,int >rmp;
stack <int> stc;
int idcount;

void push()
{
    if(idcount==0)
    {
        set<int>s;
        mp[0]=s;
        rmp[s]=0;

    }
    stc.push(0);

}
void DUP()
{

    stc.push(stc.top());
}

void exec(int op)
{
    int id1=stc.top();
    stc.pop();
    int id2=stc.top();
    stc.pop();

    set<int> s1=mp[id1];
    set<int> s2=mp[id2];
    set<int>s;

    if(op==1)
            s=s1|s2;
    else if(op==2)
            s=s1&s2;
    else{
        s2.insert(id1);
        s=s2;
    }

    if(rmp.find(s)==rmp.end())
    {
        stc.push(++idcount);
        mp[idcount]=s;
        rmp[s]=idcount;
    }
    else
        stc.push(rmp[s]);
}

int main()
{
    int T,N;
    cin>>T;
    for(int tc=0;tc<T;tc++)
    {
        cin>>N;
        for(int i=0;i<N;i++)
        {
            string command;
            cin>>command;

            if(command=="PUSH") push();
            else if(command=="DUP") DUP();
            else if(command=="UNION") exec(1);
            else if(command=="INTERSECT") exec(2);
            else  exec(3);

            cout<<mp[stc.top()].size()<<endl;

        }
        cout<<"***"<<endl;

    }
    return 0;
}
