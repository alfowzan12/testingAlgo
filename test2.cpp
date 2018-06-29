#include<iostream>
#include <algorithm>
#include <cstdint>
#include <random>
#include <string>
using namespace std;

// Function to print all sub strings

std::string exhaustive_longest_substring(const std::string& a,
                                         const std::string& b) {

  clock_t t;
  t = clock();
  std::string best = "";
  int m = a.size();
  if(a.size() == 0 || b.size() == 0)
  {
    return best;
  } else if(a == b) {
    return a;
  }
  std::string s = "";
  for(int i = 0; i < m; i++)
  {

    for(int k = 1; k <= m-i; k++)
    {
      s = a.substr(i, k);
      if((b.find(s) != -1) && (s.size() > best.size()))
      {

        best = s;
      }
    }
  }
  cout << float( clock () - t ) /  CLOCKS_PER_SEC<< " miliseconds." << endl;

  return best;
}
const int MAX = 26;
void subString1(std::string& s)
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
    cout << float( clock () - t ) /  CLOCKS_PER_SEC<< " miliseconds." << endl;


    cout <<"Longest : " << max << endl;
}





void subString(std::string& s)
{
    int max = 0;
    string str3 = "";
    string substring[10];
    string substring2[10];
    int a = 0;

    // Pick starting point
    for (int len = 1; len <= s.size(); len++)
    {


        // Pick ending point
        for (int i = 0; i <= s.size() - len; i++)
        {
            string str1 = " ";



            //  Print characters from current
            // starting point to current ending
            // point.
            int j = i + len - 1;
            for (int k = i; k <= j; k++){
              string str2 = " ";

                str1 += s[k];
                if(k+1 > j){
                  substring[a] = str1;
                  substring2[a] = str1;
                  a++;
                  //cout <<"Str1 : " <<str1 << endl;
                }
              }


        }
    }

    for(int z = 0; z < 10; z++){
      cout << "sub1 "<< substring[z] << endl;
      cout << "sub2" << substring2[z] << endl;
    }
    //cout <<"Longest : " << str3 << endl;
}



void subString5(std::string& s)
{
    int length = s.size();
    int counter = ((length*length) + length)/2;
    //int max = 0;
    string max = "";
    string substring[counter];
    string substring2[counter];
    int a = 0;

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
                  substring2[a] = str1;
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

    if (substring[0] == substring[3]) {
        cout << "They same" << endl;
    } // WHY CAN'T THE LOOP COMPARE LIKE THIS??

    for (int i = 0; i < counter; i++) {

        for (int j = 1; j < counter; j++) {
            if (substring[i] == substring[j]) {
                max = substring[i];
            }
        }


    }


    cout <<"Longest : " << max << endl;
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
bool detect_subsequence(const std::string& candidate_subsequence,
                        const std::string& candidate_supersequence) {
  int sub_length = candidate_subsequence.size();
  int super_length = candidate_supersequence.size();

  while(sub_length > -1)
  {
    if (sub_length == 0) return true;
    if (super_length == 0) return false;
    if (candidate_subsequence[sub_length-1] == candidate_supersequence[super_length-1])
    {
      sub_length--;
      super_length--;
    } else
    {
      super_length--;
    }
  }
  return false;
}
int n = 20;
std::string exhaustive_longest_subsequence(const std::string& a,
                                           const std::string& b) {

clock_t t;
  t = clock();
  std::string shorter;
  std::string longer;
  std::string best = "";

  if(a.size() > b.size())
  {
    longer = a;
    shorter = b;
  } else {
    longer = b;
    shorter = a;
  }


  for (int i = 0; i < pow(2,shorter.size()); i++){
    std::string s = "";

    for (int j = 0; j < shorter.size(); j++){

      if ( ((i >> j) & 1) ==1 ){
      s += shorter[j];
    }

    }

    if(detect_subsequence(s, longer) && (s.size() > best.size())){
      best = s;
    }

  }
  cout << "N = " << n << endl;
  cout << float( clock () - t ) /  CLOCKS_PER_SEC<< " miliseconds." << endl;

  return best;
}

int main()
{
    srand(time(NULL));
    //int n = 20;
    string str1 = printRandomString(n);
    string str2 = printRandomString(n);
    exhaustive_longest_substring(str1, str2);
    return 0;
}
