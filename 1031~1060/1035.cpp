#include<bits/stdc++.h>
using namespace std;

int main(){
   int N;
   string name, password;
   vector< string >v;
   cin >> N;
   for(int k = 0; k < N; k++){
      cin >> name >> password;
      bool ok = true;
      for(int i = 0; i < password.length(); i++){
         if(password[i] == '1')  { password[i] = '@'; ok = false;}
         else if(password[i] == '0') { password[i] = '%'; ok = false; }
         else if(password[i] == 'O') { password[i] = 'o'; ok = false; }
         else if(password[i] == 'l') { password[i] = 'L'; ok = false; }
      }
      if(!ok) { v.push_back(name); v.push_back(password); }
   }
   if( v.empty() ) printf("There %s %d account%sand no account is modified", (N == 1)?"is": "are", N, (N == 1)?" ": "s " );
   else {
      cout << v.size()/2 <<endl;
      for(int i = 0; i < (int)v.size(); i += 2)
         cout << v[i] << " " << v[i+1] << endl;
   }
   return 0;
}