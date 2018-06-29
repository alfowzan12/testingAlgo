// concatenating strings
#include <iostream>
#include <string>
using namespace std;
int main()
{
  //fares


  cout << "----------------------------------" << endl;
  int n = 0;
  string str2 = "";
  string str1 = "banana";
  for(int i = 0; i < str1.size()-1; i++){
    bool exist = false;
    int n = 0;
    for(int j = str1.size()-1; j > i; j--){
      if(str1[i] == str1[j]){
        n++;
      }
      if((j-1) == i){
        cout << "C: " << n << endl;

        if(n == 1){

        }else{
          if(n%2 == 1){
            n++;
            n = n / 2;

          }else{
          n = n / 2;
        }
        }

        for(int b = 0; b < str2.size(); b++){
          if(str2[b] == str1[i]){
            exist = true;
          }
        }
        cout << "CA: " << n << endl;
        if(exist != true){
        for(int a = 0; a < n; a++){
          str2 += str1[i];
        }
        }
      }
    }
  }

  cout << str2 << endl;

  return 0;
}
