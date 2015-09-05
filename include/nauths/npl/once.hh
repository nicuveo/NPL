//
// Copyright Antoine Leblanc 2010 - 2015
// Distributed under the MIT license.
//
// http://nauths.fr
// http://github.com/nicuveo
// mailto://antoine.jp.leblanc@gmail.com
//

#ifndef NPL_ONCE_HH_
# define NPL_ONCE_HH_



//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// Macros

# define DO_ONCE(code)                        \
do                                            \
{                                             \
  static bool first = true;                   \
  if (first)                                  \
  {                                           \
    code;                                     \
  }                                           \
  first = false;                              \
}                                             \
while (false)                                 \

# define DO_ONCE_AT_LAUNCH()                  \
  class NplOnceAtLaunch                       \
  {                                           \
    private:                                  \
      NplOnceAtLaunch();                      \
      static NplOnceAtLaunch instance_;       \
  };                                          \
                                              \
  NplOnceAtLaunch NplOnceAtLaunch::instance_; \
                                              \
  NplOnceAtLaunch::NplOnceAtLaunch()          \



#endif /* !NPL_ONCE_HH_ */
