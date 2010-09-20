#include "ProfileEntry.h"

namespace Profiler {

ProfileEntry* ProfileEntry::AddChild (char* new_func_name, char* new_file_name)
{
    return (*subCalls.insert(subCalls.end(), new ProfileEntry(new_func_name, new_file_name)));
}

ProfileEntry* ProfileEntry::AddExistedChild (ProfileEntry* child_item) {
    if (find (subCalls.begin(), subCalls.end(), child_item) == subCalls.end()) {
        this->subCalls.push_back(child_item);
    };
    return child_item;
};

ProfileEntry::ProfileEntry(char* function_name, char* file_name)
{
        file = (char*) file_name ;
        function = (char*) function_name;
}

ProfileEntry::ProfileEntry()
{

}

std::string ProfileEntry::Get_function() {
    return function;
}

std::string ProfileEntry::Get_file() {
    return file;
}

Profiler::ProfileContext* ProfileEntry::Get_currentContext() {
    return &currentContext;
}

}       // end namespace Profiler
