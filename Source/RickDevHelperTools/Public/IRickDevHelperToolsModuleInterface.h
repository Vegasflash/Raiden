#pragma once

#include "Modules/ModuleManager.h"

class IRickDevHelperToolModuleListenerInterface
{
public:
	virtual void StartupModule();
	virtual void ShutdownModule();
};

class IRickDevHelperToolsModuleInterface : public IModuleInterface
{
public:
	void StartupModule() override
	{

	}

	void ShutdownModule() override
	{

	}

	virtual void AddModuleListeners() {};

protected:
	TArray<TSharedRef<IRickDevHelperToolModuleListenerInterface>> module_listeners;
};