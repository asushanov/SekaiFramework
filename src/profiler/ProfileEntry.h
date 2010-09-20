#ifndef __PROFILEENTRY_H_INCLUDED__
#define __PROFILEENTRY_H_INCLUDED__

#include <string>
#include <vector>
#include "ProfileContext.h"
#include <algorithm>
// #include "../time/TimeSourceWin.h"

namespace Profiler {

class ProfileEntry {
 private:
        char* function;
        char* file;
        Profiler::ProfileContext currentContext;
 public:
        std::vector <ProfileEntry* > subCalls;
        // Add child item and return a pointer to it for 'Map'
        ProfileEntry* AddChild(char* new_func_name, char* new_file_name);
        ProfileEntry* AddExistedChild (ProfileEntry*);
        ProfileEntry (char* function_name, char* file_name);
        ProfileEntry();
        // Access methods
        std::string Get_function();
        std::string Get_file();
        Profiler::ProfileContext* Get_currentContext();
};

} // namespace

#endif // __PROFILEENTRY_H_INCLUDED__
