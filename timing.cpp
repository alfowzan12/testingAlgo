#include <iostream>
#include <ctime>
using namespace std;
const int MAX = 26;
std::string longest_oreo(const std::string& s) {
  assert(s.size() > 0);


  if(s.size() == 1) { return s; }
  //int last_char_position = 0;
  clock_t t; //add this line and the line below on the top of your algorith you are testing.
  t = clock();
  std::string str1 = "";


  for(int i = 0; i < s.size(); i++){

    for(int j = s.size()-1; j > i ; j--){
      if(s[i] == s[j]){
        if (i == 0){
          if(str1.size() < (s.substr(i, j-i)).size()){
            str1 = s.substr(i, j-i+2);

          }
        }
        else if (str1.size() < (s.substr(i-1, j-i)).size()){

          str1 = s.substr(i, j-i+2);

        }
      }

    }


  }
  
  t = clock() - t; //add this line and the line below it at the end of your algorithm that you are testing
  cout << float( clock () - t ) /  CLOCKS_PER_SEC<< " miliseconds." << endl;
  //std::cout << "str1 = " << str1 << std::endl;

  if(str1.size() > 1){

    return str1;
  }

  // TODO: replace this comment, and bogus return statement, with an actual
  // implementation of the function.
  return "";
}
int vowel_count(const std::string& s) {
  clock_t t;
  t = clock();
  int vowels = 0;



  if (s.size() == 0) { return vowels; }
  for(int i = 0; i < s.size(); i++){
    if(s[i] == 'A' or s[i] == 'a') { vowels++; }
    if(s[i] == 'E' or s[i] == 'e') { vowels++; }
    if(s[i] == 'I' or s[i] == 'i') { vowels++; }
    if(s[i] == 'O' or s[i] == 'o') { vowels++; }
    if(s[i] == 'U' or s[i] == 'u') { vowels++; }
  }
  t = clock() - t; //add this line and the line below it at the end of your algorithm that you are testing
  cout << float( clock () - t ) /  CLOCKS_PER_SEC<< " miliseconds." << endl;
  // TODO: replace this comment, and bogus return statement, with an actual
  // implementation of the function.
  return vowels;
}
string printRandomString(int n)
{
    char alphabet[MAX] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g',
                          'h', 'i', 'j', 'k', 'l', 'm', 'n',
                          'o', 'p', 'q', 'r', 's', 't', 'u',
                          'v', 'w', 'x', 'y', 'z' };

    string res = "";
    for (int i = 0; i < n; i++)
        res = res + alphabet[rand() % MAX];

    return res;
}
string subString1(std::string& s)
{
    int length = s.size();
    int counter = ((length*length) + length)/2;
    //int max = 0;
    string max = "";
    string substring[counter];
    string substring2[counter];
    int a = 0;

    clock_t t;
    t = clock();
    for (int len = 1; len <= s.size(); len++)
    {

        for (int i = 0; i <= s.size() - len; i++)
        {
            string str1 = "";

            int j = i + len - 1;
            for (int k = i; k <= j; k++){
              string str2 = "";
                //cout << s[k] << s[k];
                str1 += s[k];
                if(k+1 > j ){
                  substring[a] = str1;
                  //substring2[a] = str1;
                  a++;
                  //cout <<"Str1 : " <<str1 << endl;
                }
              }


        }
    }


    for(int z = 0; z < counter; z++){
      cout << "substring" << "[" << z << "]: " << substring[z] << endl;
      //cout << "sub2" << substring2[z] << endl;
    }


    for (int i = 0; i < counter; i++) {

        for (int j = i + 1; j < counter; j++) {
            if (substring[i] == substring[j]) {
                max = substring[i];
            }
        }


    }


    cout <<"Longest : " << max << endl;
    cout << float( clock () - t ) /  CLOCKS_PER_SEC<< " miliseconds." << endl;

}
int main() {

   srand(time(NULL));
   int n = 200;
  // cout << printRandomString(n) << endl;

// Returns a string of random alphabets of
// length n.

  string str1 = "hello";
  subString1(printRandomString(n)); //replace subString1 with whatever algorithm you are testing.
  return 0;
}
