#include "RickDevHelperTools.h"

DEFINE_LOG_CATEGORY(RickDevHelperTools);

#define LOCTEXT_NAMESPACE "FRickDevHelperTools"

void FRickDevHelperTools::StartupModule()
{
	UE_LOG(RickDevHelperTools, Warning, TEXT("RickDevHelperTools module has been loaded"));
}

void FRickDevHelperTools::ShutdownModule()
{
	UE_LOG(RickDevHelperTools, Warning, TEXT("RickDevHelperTools module has been unloaded"));
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FRickDevHelperTools, RickDevHelperTools)