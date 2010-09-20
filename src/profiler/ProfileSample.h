#ifndef __PROFILESAMPLE_H_INCLUDED__
#define __PROFILESAMPLE_H_INCLUDED__

#include "ProfileManager.h"
#include "ProfileEntry.h"
#include "ProfileTypes.h"

namespace Profiler {

class ProfileSample {
     private:
            ProfileManager* pProfileManager;
            ProfileEntry* pProfileEntry;
            double startTime;
			double TimeCalculate();
     public:
            ProfileSample(char* func_name, char* file_name);        // Constructor
            ProfileSample();
            ~ProfileSample();       // Destructor
};

} // namespace

#endif // __PROFILESAMPLE_H_INCLUDED__
