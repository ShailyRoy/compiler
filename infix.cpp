//author: Shaily Roy


#include<bits/stdc++.h>
#include<fstream>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

using namespace std;
vector<string>out;
stack<string>st;
map <string,double> var;
map<string,int>opr;




void infix(string ss){

    stringstream sss;
    sss<<ss;
    string chk;
        while(sss>>chk){
          //  cout<<chk<<endl;
            //2
            if(var[chk]!=0)
            out.push_back(chk);
            //3
            else if(chk=="(")
                st.push(chk);
            //4
            else if(opr[chk]!=0){
                bool bb=true;
                while(bb){
                if(st.empty()){
                    st.push(chk);
                    bb=false;
                }
                else if(st.top()=="("){
                    st.push(chk);
                    bb=false;
                }
                else if(opr[st.top()]<opr[chk])
                 {
                     st.push(chk);
                     bb=false;
                 }
                else
                {
                    string s=st.top();
                    st.pop();
                    out.push_back(s);
                    bb=true;
                }
                }}

            //5
            if(chk==")"){
              string s=st.top();
              while(s!="("){

                    // cout<<s<<" ";
                    st.pop();
                    out.push_back(s);
                     s=st.top();
            }
                st.pop();
            }
            }

            while(!st.empty()){
                string s=st.top();
                out.push_back(s);
                st.pop();
            }
        }

double cal(){
    stack<double>num;
for(int i=0;i<out.size();i++){
    string t=out[i];
    if(var[out[i]]!=0){
        num.push(var[t]);}

   else if(opr[t]!=0){
        double b=num.top();
        num.pop();
        double a=num.top();
        num.pop();
        double nn;
        if(t=="+"){
            nn=a+b;
        }

        else if(t=="-"){
            nn=a-b;
        }

        else if(t=="x"){
            nn=a*b;
        }

        else if(t=="/"){
            nn=a/b;
        }

        else if(t=="^")
            nn=pow(a,b);

        num.push(nn);
    }
    }

    return num.top();

}



int main(){

    freopen("input.txt", "r", stdin);

            opr["^"]=2;
            opr["x"]=2;
            opr["/"]=2;
            opr["+"]=1;
            opr["-"]=1;
            char s[1000];
            double num;
            int n;
            scanf("%d",&n);
            for(int i=0;i<n;i++){
            scanf("%s = %lf",s,&num);
            var[s]=num;
            }
    scanf("%d",&n);
    getchar();
    while(n--){
    map<string,int>chkr;
       out.clear();
        string ss;
        getline(cin,ss);
        stringstream sss;
        sss<<ss;
        string chk;
        int c=1;

        while(sss>>chk){
        if(opr[chk]!=0&&c==1){
                 cout<<"Can't start with operator error"<<endl;
        c=0;
        break;
        }
        else if(var[chk]==0&&opr[chk]==0&&chk!="("&&chk!=")"){
            cout<<"Compilation error"<<endl;
        c=0;
        break;
        }
        else if(opr[chk]!=0){
            sss>>chk;
            if(opr[chk]!=0){
                cout<<"operator Error"<<endl;
                  c=0;
        break;
        }
            else if(var[chk]==0&&opr[chk]==0&&chk!="("&&chk!=")"){
            cout<<"Compilation error"<<endl;
          c=0;
        break;
        }

            else if(chk=="(")
            chkr["("]++;

            else if(chk==")")
            {
                chkr["("]--;
                if(chkr["("]<0){
                cout<<"parenthesis error"<<endl;
              c=0;
        break;
        }
            }
            }

         else if(var[chk]!=0){
            sss>>chk;
            if(var[chk]!=0){
                cout<<"variables Error"<<endl;
                  c=0;
        break;
        }
            else if(opr[chk]==0&&var[chk]==0&&chk!="("&&chk!=")"){
            cout<<"Compilation error"<<endl;
          c=0;
        break;
        }

            else if(chk=="(")
            chkr["("]++;

            else if(chk==")")
            {
                chkr["("]--;
                if(chkr["("]<0){
                cout<<"parenthesis error"<<endl;
              c=0;
        break;
        }
            }
            }


        else if(chk=="(")
            chkr["("]++;

        else if(chk==")")
            {
                chkr["("]--;
                if(chkr["("]<0){
                cout<<"parenthesis error"<<endl;
              c=0;
        break;
        }
            }

        c++;

        }
        if(c){
        infix(ss);
     //   cout<<ss<<endl;
       /* for(int i=0;i<out.size();i++)
            cout<<out[i]<<" ";
            cout<<endl;
*/


        double ans= cal();
        cout<<ans<<endl;
        }
    }
}
