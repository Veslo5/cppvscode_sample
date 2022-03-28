#include "TopScene.h"
#include "raylib-cpp.hpp"
#include "VGame.h"
#include "rlImGui.h"
#include "imgui.h"

raylib::RenderTexture testtext;

VGameplay::TopScene::TopScene(std::string name, Vengine::VGame *game) : Vengine::VScene(name, game)
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

	ImGui::SetNextWindowSizeConstraints(ImVec2(400, 400), ImVec2(Game->WindowWidth, Game->WindowHeight));
	rlImGuiBegin();

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

	rlImGuiEnd();	

	EndDrawing();
}