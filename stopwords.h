#include <iostream>
#include <string>
#include <map>
#include <set>
#include <float.h>
#include <cmath>
#include <sstream>
#include <fstream>
#include <sstream>
#include <cassert>
#include <regex>
#include <exception>

using namespace std;

//////////////HELPERS///////////////////


string default_words()
{
  string ret = " !! ?! ?? !? ` `` '' -lrb- -rrb- -lsb- -rsb- , . : ; ' ? < > { } [ ] + - ( ) & % $ @ ! ^ # * .. ... 'll 's 'm a about above after again against all am an and any are aren't as at be because been before being below between both but by can can't cannot could couldn't did didn't do does doesn't doing don't down during each few for from further had hadn't has hasn't have haven't having he he'd he'll he's her here here's hers herself him himself his how how's i i'd i'll i'm i've if in into is isn't it it's its itself let's me more most mustn't my myself no nor not of off on once only or other ought our ours  ourselves out over own same shan't she she'd she'll she's should shouldn't so some such than that that's the their theirs them themselves then there there's these they they'd they'll they're they've this those through to too under until up very was wasn't we we'd we'll we're we've were weren't what what's when when's where where's which while who who's whom why why's with won't would wouldn't you you'd you'll you're you've your yours yourself yourselves ### return arent cant couldnt didnt doesnt dont hadnt hasnt havent hes heres hows im isnt its lets mustnt shant shes shouldnt thats theres theyll theyre theyve wasnt were werent whats whens wheres whos whys wont wouldnt youd youll youre youve";
  return ret;
}
set<string> uqwords(const string &str)
{
  // Fancy modern C++ and STL way to do it
  istringstream source{str};
  return {istream_iterator<string>{source},
          istream_iterator<string>{}};
}

class stopwords {
public:
  //Constructor to initialize map
  stopwords();
  //Constructor for own string
  stopwords(const string inWords);
  // Remove stop words from string
  void remove_stopwords(string & str);
  // Print Stop words list
  void print_stopwords(ostream & os);
private:
  //words to be treated as stopwords
  string words;
  set<string> uwords;
};

/////////////IMPLEMENTATION//////////////
//default ctor
stopwords::stopwords()
{
  string inWords = default_words();
  uwords = uqwords(inWords);
}
stopwords::stopwords(const string inWords)
{
  uwords = uqwords(inWords);
}
// Remove stop words from string
void stopwords::remove_stopwords(string & str)
{
  size_t pos = string::npos;
  for(auto it=uwords.begin();it != uwords.end(); it++)
  {
    if (str.length() >= it->length() + 1)
    {
      // Search for the substring in string in a loop untill nothing is found
      while (((pos = str.find(" " + *it + " ")) != std::string::npos) && (str.length() >= it->length() + 1))
      {
        // If found then erase it from string
        str.erase(pos, it->length()+1);
      }
      
      if (str.find(*it + " ") == 0)
      {
        // If found then erase it from string
        str.erase(0, it->length());
      }
      if (str.find(" " + *it) == (str.length() - it->length() - 1))
      {
        // If found then erase it from string
        str.erase(str.length() - it->length() -1, it->length());
      }
    }
  }
}
// Print Stop words list
void stopwords::print_stopwords(ostream & os)
{
  os << words;
}

