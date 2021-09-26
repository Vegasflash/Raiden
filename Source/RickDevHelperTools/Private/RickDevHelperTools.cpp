#include "RickDevHelperTools.h"
#include "LevelEditor.h"

DEFINE_LOG_CATEGORY(RickDevHelperTools);

#define LOCTEXT_NAMESPACE "FRickDevHelperTools"

#pragma region Public

void FRickDevHelperTools::AddMenuExtension(const FMenuExtensionDelegate& extension_delegate,
	FName extension_hook, const TSharedPtr<FUICommandList>& command_list, EExtensionHook::Position position)
{
	menu_extender->AddMenuExtension(extension_hook, position, command_list, extension_delegate);
}

void FRickDevHelperTools::StartupModule()
{
	UE_LOG(RickDevHelperTools, Warning, TEXT("RickDevHelperTools module has been loaded"));

	//if (!IsRunningCommandlet())
	{
		auto& level_editor_module = FModuleManager::LoadModuleChecked<FLevelEditorModule>("LevelEditor");
		level_editor_menu_ext_manager = level_editor_module.GetMenuExtensibilityManager();

		menu_extender = MakeShareable(new FExtender());
		menu_extender->AddMenuBarExtension("Window", EExtensionHook::After, NULL,
			FMenuBarExtensionDelegate::CreateRaw(this, &FRickDevHelperTools::DrawPulldownMenu));
		
		level_editor_menu_ext_manager->AddExtender(menu_extender);
	}

}

void FRickDevHelperTools::ShutdownModule()
{
	UE_LOG(RickDevHelperTools, Warning, TEXT("RickDevHelperTools module has been unloaded"));
}

#pragma endregion

#pragma region Protected
TSharedRef<FWorkspaceItem> FRickDevHelperTools::menu_root = FWorkspaceItem::NewGroup(FText::FromString("Menu Root"));

void FRickDevHelperTools::DrawPulldownMenu(FMenuBarBuilder& menu_bar_builder)
{
	menu_bar_builder.AddPullDownMenu(
		FText::FromString("Example"),
		FText::FromString("Open the Example Menu"),
		FNewMenuDelegate::CreateRaw(this, &FRickDevHelperTools::FillPulldownMenu),
		"Example",
		FName(TEXT("ExampleMenu")));
}

void FRickDevHelperTools::FillPulldownMenu(FMenuBuilder& menu_builder)
{
	menu_builder.BeginSection("ExampleSection", FText::FromString("Section 1"));
	menu_builder.AddMenuSeparator(FName("Section_1"));
	menu_builder.EndSection();

	menu_builder.BeginSection("ExampleSection", FText::FromString("Section 2"));
	menu_builder.AddMenuSeparator(FName("Section_2"));
	menu_builder.EndSection();
}

#pragma endregion


#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FRickDevHelperTools, RickDevHelperTools)