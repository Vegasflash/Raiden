#pragma once
#include "UnrealEd.h"
#include "SlateBasics.h"
#include "SlateExtras.h"
//#include "LevelEditor.h"
#include "Editor/PropertyEditor/Public/PropertyEditing.h"
#include "IAssetTypeActions.h"
#include "Modules/ModuleManager.h"

DECLARE_LOG_CATEGORY_EXTERN(RickDevHelperTools, All, All);

class FRickDevHelperTools : public IModuleInterface
{
public:
	void AddMenuExtension(const FMenuExtensionDelegate& extension_delegate,
		FName extension_hook, const TSharedPtr<FUICommandList>& CommandList = NULL,
		EExtensionHook::Position position = EExtensionHook::Before);

	TSharedRef<FWorkspaceItem> GetMenuRoot() { return menu_root; }

	/* Called when the module is loaded */
	virtual void StartupModule() override;

	/* Called when the module is unloaded */
	virtual void ShutdownModule() override;

	static inline FRickDevHelperTools& Get()
	{
		return FModuleManager::LoadModuleChecked<FRickDevHelperTools>("RickDevHelperTools");
	}
	
	static inline bool IsAvailable()
	{
		return FModuleManager::Get().IsModuleLoaded("RickDevHelperTools");
	}

protected:
	TSharedPtr<FExtensibilityManager> level_editor_menu_ext_manager;
	TSharedPtr<FExtender> menu_extender;
	
	static TSharedRef<FWorkspaceItem> menu_root;
	
	void DrawPulldownMenu(FMenuBarBuilder& menu_bar_builder);
	void FillPulldownMenu(FMenuBuilder& menu_builder);
};