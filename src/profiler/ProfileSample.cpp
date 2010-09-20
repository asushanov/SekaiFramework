#include "ProfileSample.h"

// TODO TEMP_CODE
#include <time.h>
// END TEMP_CODE

namespace Profiler {

ProfileSample::ProfileSample(char* func_name, char* file_name) {
    pProfileManager = Profiler::ProfileManager::Instance();
    // Get ProfileEntry for current Sample
    pProfileEntry = pProfileManager->FindOrCreate({file_name, func_name}) ;
    // Current time value
	startTime = TimeCalculate();
}

ProfileSample:: ~ProfileSample()  {
    // Update time information
	(*pProfileEntry).Get_currentContext()->Update(TimeCalculate() - startTime);
	pProfileManager->RemoveLastInCallStack();
}

double ProfileSample::TimeCalculate() {
    // TODO !!!
	// Time::TimeSourceWin * A = new Time::TimeSourceWin();
	// __int64 ticks_, resolution_;
	// A->GetTicks(ticks_);
	// A->GetResoulution(resolution_);
	// double currentTime = (double)ticks_ / (double)resolution_;
    // delete A;
    // return currentTime;
	return time(NULL);
}

}       // end namespace "Profiler"
