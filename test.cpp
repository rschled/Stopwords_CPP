#include <iostream>
#include <string>
#include "stopwords.h"
using namespace std;

int main()
{
  string hi = "this is a string for testing, i like this string and it has plenty of stopwords for testing the removal of stopwords";
  string empty = "leftword";
  cout << empty << endl;
  cout << hi << endl;
  stopwords sw;
  sw.remove_stopwords(hi);
  sw.remove_stopwords(empty);
  cout << hi << endl;
  cout << empty << endl;
}