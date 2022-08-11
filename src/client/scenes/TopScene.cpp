#include "TopScene.h"
#include "raylib-cpp.hpp"
#include "VGame.h"
#include "rlImGui.h"
#include "imgui.h"

raylib::RenderTexture testtext;

VGameplay::TopScene::TopScene(std::string name, Vengine::VGame *game) : Vengine::VScene(name, game), scriptWidget(std::make_unique<VGameplay::ScriptWidget>())
{
}

void VGameplay::TopScene::LoadContent()
{
	rlImGuiSetup(true);
	testtext = raylib::RenderTexture(Game->WindowWidth, Game->WindowHeight);
}

void VGameplay::TopScene::UnloadContent()
{
	rlImGuiShutdown();
}

void VGameplay::TopScene::Update(float deltaTime)
{
}

void VGameplay::TopScene::Draw()
{

	BeginTextureMode(testtext);
	Game->ClearBackground();
	DrawRectangle(0, 0, 100, 100, raylib::Color::Red());
	EndTextureMode();

	BeginDrawing();
	Game->ClearBackground();

	rlImGuiBegin();

	ImGui::SetNextWindowSize(ImVec2(200, 100));
	ImVec2 size = ImGui::GetContentRegionAvail();

	// // center the scratch pad in the view
	// Rectangle viewRect = {0};
	// viewRect.x = 0;
	// viewRect.y = 0;
	// viewRect.width = size.x;
	// viewRect.height = size.y;

	ImGui::Begin("Window with raylib textuer");
	// rlImGuiImageRect(&testtext.texture, static_cast<int>(size.x), static_cast<int>(size.y), viewRect);
	rlImGuiImage(&testtext.texture);
	ImGui::End();

// MAIN MENU
#pragma region
	if (ImGui::BeginMainMenuBar())
	{
		if (ImGui::BeginMenu("Settings"))
		{
			if (ImGui::MenuItem("Use vertical menu", nullptr, false))
			{
			}

			ImGui::EndMenu();
		}

		if (ImGui::BeginMenu("Windows"))
		{

			if (ImGui::MenuItem("Grid Map"))
			{
			}
			if (ImGui::MenuItem("Script editor"))
			{
			}
			if (ImGui::MenuItem("Info"))
			{
			}

			ImGui::EndMenu();
		}

		ImGui::EndMainMenuBar();
	}
#pragma endregion

	// SCRIPT WINDOW
	scriptWidget->Draw();

// IMAGE SPRITE EDITOR
#pragma region
	ImGui::Begin("Next scene");

	ImGui::End();
#pragma endregion

	rlImGuiEnd();

	EndDrawing();
}