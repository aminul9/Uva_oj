#include <bits/stdc++.h>
using namespace std;

int main()
{

       // freopen("input.txt","r",stdin);
       // freopen("output.txt","w",stdout);

        set<string>setisfied;
        string mainstring;
        stringstream ss;
        string orginal[5000],duplicate[5000];
        int sum[5000],index=0;

        while(getline(cin,mainstring))
        {
            ss.str("");
            if(mainstring[0]=='#') break;
            else
            {

                ss<<mainstring;

                while(!ss.eof())
                {
                    string temp="";
                    ss>>temp;

                    orginal[index]=temp;
                    transform(temp.begin(),temp.end(),temp.begin(),::toupper);
                    sort(temp.begin(),temp.end());
                    duplicate[index]=temp;
                    index++;

                }
                ss.clear();

            }


        }



//        for(int i=0;i<index;i++)
//            cout<<orginal[i]<<" "<<duplicate[i]<<endl;


        for(int i=0;i<index;i++)
        {
            bool check=false;

            for(int j=i+1;j<index;j++)
            {
                if(duplicate[i]==duplicate[j])
                {
                    check=true;
                    duplicate[j]="@";
                }
            }
            if(check==true) duplicate[i]="@";
            if(duplicate[i]!="@") setisfied.insert(orginal[i]);

        }


//
//
//
//
       for(set<string>::iterator it= setisfied.begin();it!=setisfied.end();++it)
           cout<<*it<<endl;
           //cout<<endl;

    return 0;
}
