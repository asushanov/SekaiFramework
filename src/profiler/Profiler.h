#ifndef PROFILER_H_INCLUDED
#define PROFILER_H_INCLUDED

#include "ProfileSample.h"

#define __PROFILE_FUNCTION__ Profiler::ProfileSample pMember(const_cast<char*>(__FUNCTION__), const_cast<char*>(__FILE__));

#endif // PROFILER_H_INCLUDED
