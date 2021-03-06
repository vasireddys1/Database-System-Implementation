#ifndef _QUERYOPS_H_
#define _QUERYOPS_H_

#include <algorithm>
#include <string>

class Queryops {
public:
  bool createTable();
  bool insertInto();
  bool dropTable();
  void setOutput();

private:
  bool exists(const char* relName);

  static inline std::string &ltrim(std::string &s) {
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), std::not1(std::ptr_fun<int, int>(std::isspace))));
    return s;
  }

  // trim from end
  static inline std::string &rtrim(std::string &s) {
    s.erase(std::find_if(s.rbegin(), s.rend(), std::not1(std::ptr_fun<int, int>(std::isspace))).base(), s.end());
    return s;
  }

  // trim from both ends
  static inline std::string &trim(std::string &s) {
    return ltrim(rtrim(s));
  }
};


#endif
