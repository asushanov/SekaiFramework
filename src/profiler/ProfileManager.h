#ifndef __PROFILEMANAGER_H_INCLUDED__
#define __PROFILEMANAGER_H_INCLUDED__

#include <list>
#include <map>
#include "ProfileEntry.h"
#include "ProfileTypes.h"
#include <string.h>

namespace Profiler {

struct map_key_comp {
  bool operator() (const Profiler::FuncInfo& lhs, const Profiler::FuncInfo& rhs) const
  {
        std::string lhs_s, lhs_s1, lhs_s2, rhs_s, rhs_s1, rhs_s2;
        lhs_s1 = ((const char*) lhs.file_name);
        lhs_s2 = ((const char*) lhs.func_name);
        lhs_s = lhs_s1+lhs_s2;
        rhs_s1 = ((const char*) rhs.file_name);
        rhs_s2 = ((const char*) rhs.func_name);
        rhs_s = rhs_s1+rhs_s2;
      return lhs_s<rhs_s;}
};

class ProfileManager {
 private:
        static ProfileManager* _instance;
        // Map for quick search of necessary entry
        std::map<Profiler::FuncInfo ,ProfileEntry* , map_key_comp> entryMap;
		// Active, not finished functions and their ProfileEntry
        std::list<ProfileEntry*> callStack;
        // Root entry fith NULL attributes 'funcName' and 'fileName'
        ProfileEntry rootEntry;
 public:
        std::list<ProfileEntry* >* Get_callStack ();
        ProfileEntry* Get_rootEntry();
        // Find existed or create new ProfileEntry
        ProfileEntry* FindOrCreate (Profiler::FuncInfo func_info);
        static ProfileManager* Instance();
		void RemoveLastInCallStack();
protected:
        ProfileManager();
};

} // namespace

#endif // __PROFILEMANAGER_H_INCLUDED__
