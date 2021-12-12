/*
Author: Shaily Roy
Input:
int a, b, 
c;
float d , e ;
a = b = 5;
c = 6;
if ( a == b)
{
	c = a98 - b;
	e = d - 2.6790;
}
else
{
	d = e + 6.0;
	b = a + c;
}

*/

#include<bits/stdc++.h>
#include<fstream>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

using namespace std;

vector<char>mo;
vector<char>lo;
vector<string>key;
vector<string>iden;
vector<string>num;
map<char,int>mp;
vector<char>others;
map<string,int>mp2;

int isKey(char ch[]){
    char keywords[32][10] = {"auto","break","case","char","const","continue","default",
                            "do","double","else","enum","extern","float","for","goto",
                            "if","int","long","register","return","short","signed",
                            "sizeof","static","struct","switch","typedef","union",
                            "unsigned","void","volatile","while"};
    int i, b = 0;

    for(i = 0; i < 32; ++i){
        if(strcmp(keywords[i], ch) == 0){
            b = 1;
            break;
        }
    }

    return b;
}

int main(){
    char ch, buffer[15];
    char operators[] = "+-*/%";
    string reloperators[8] ={"=",">","<"};

    ifstream fin("input.txt");

    int i,j=0;

    if(!fin.is_open()){
        cout<<"file not found\n";
        exit(0);
    }

    while(!fin.eof()){
           ch = fin.get();

        for(i = 0; i < 6; ++i){
        if(ch == operators[i]){
           mp[ch]++;
                  if(mp[ch]==1) mo.push_back(ch);
           }}
             for(i = 0; i < 3; ++i)
            {
             if(ch == reloperators[i][0])
           {
               mp[ch]++;
                  if(mp[ch]==1)
                              lo.push_back(ch);
           }}


           if(isalnum(ch)){
               buffer[j++] = ch;
           }
           else if(ch=='.'){
            buffer[j++] = ch;
           }

           else if(ch==';'||ch==','||ch=='('||ch==')'||ch=='{'||ch=='}'){
            mp[ch]++;
            if(mp[ch]==1)
            others.push_back(ch);
           }

           else if((ch == ' ' || ch == '\n') && (j != 0)){
                   buffer[j] = '\0';
                   j = 0;

                   if(isKey(buffer) == 1){
                   mp2[buffer]++;
                  if(mp2[buffer]==1)
                key.push_back(buffer);

                }
                   else if(isdigit(buffer[0])){
                  mp2[buffer]++;
                  if(mp2[buffer]==1)
         num.push_back(buffer);}

                    else{
                        mp2[buffer]++;
                  if(mp2[buffer]==1)
                    iden.push_back(buffer);

           }}


    }



           cout<<"Keyword: ";
           for(int i=0;i<key.size();i++){
            cout<<key[i]<<" ";
           }
           cout<<"\n";


           cout<<"identifier: ";
           for(int i=0;i<iden.size();i++){
            cout<<iden[i]<<" ";
           }
            cout<<"\n";

           cout<<"Mathematical operator: ";
           for(int i=0;i<mo.size();i++){
            cout<<mo[i]<<" ";
           }
            cout<<"\n";

           cout<<"Logical operator: ";
           for(int i=0;i<lo.size();i++){
            cout<<lo[i]<<" ";
           }
            cout<<"\n";

           cout<<"Numeric value: ";
           for(int i=0;i<num.size();i++){
            cout<<num[i]<<" ";
           }
            cout<<"\n";


           cout<<"Others: ";
             for(int i=0;i<others.size();i++){
            cout<<others[i]<<" ";
           }
            cout<<"\n";



    fin.close();

    return 0;
}
