#include "ProfileManager.h"

namespace Profiler {

ProfileManager* ProfileManager::_instance = 0;

ProfileManager* ProfileManager::Instance() {
    if (_instance == 0) {
        _instance = new ProfileManager ;
    }
	return _instance;
}

ProfileEntry* ProfileManager::FindOrCreate (Profiler::FuncInfo func_info)
{
    // Check that callStack is empty
    // "YES" - create new ProfileEntry and add it to stack
    // "NO" - try to find existing entry with the same FUNC_NAME and FILE_NAME
    // before create its own one
    // TODO Describe why I don't check if map is empty

    // Contains child Entry
    ProfileEntry * childEntry;
    // Detection of a parent Entry
    if (callStack.empty()) {
        // There are not any "active" functions
        childEntry = rootEntry.AddChild(func_info.func_name, func_info.file_name );
    }
    else
    {
        childEntry = callStack.back()->AddChild(func_info.func_name, func_info.file_name );
    };
    // Add new "Entry record" into 'callStack'
    callStack.push_back (childEntry);

    return childEntry;
}

ProfileManager::ProfileManager() {

}

std::list<ProfileEntry* >* ProfileManager::Get_callStack () {
    return &callStack;
}

ProfileEntry* ProfileManager::Get_rootEntry() {
    return &rootEntry;
}

void ProfileManager::RemoveLastInCallStack() {
	callStack.pop_back();
}

}   // end namespace Profiler
