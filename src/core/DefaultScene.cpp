#include "DefaultScene.h"
#include "VGame.h"

DefaultScene::DefaultScene(std::string name, Vengine::VGame *game) : VScene(name, game), Logo("res/logo.png"),
																	 countdown(
																		 0.5f, [this]()
																		 { TimerCallback(); },
																		 false)

{
}

void DefaultScene::TimerCallback()
{
	this->Game->SceneManager.ChangeSceneNextFrame = true;
}

void DefaultScene::UnloadContent()
{
}

void DefaultScene::LoadContent()
{
	/*this->Game->DataManager.TextureHolder.AddToLoadingQueue("res/test.png");
	this->Game->DataManager.Load();
	auto texture = this->Game->DataManager.GetTexture("res/test.png");*/
}

void DefaultScene::Update(float deltaTime)
{
	this->Camera.SetZoom(this->Game->WindowWidth / 1366.f);
	this->Camera.SetOffset(raylib::Vector2(this->Game->WindowWidth / 2, this->Game->WindowHeight / 2));
	this->Camera.SetTarget(raylib::Vector2(Logo.width / 2, Logo.height / 2));
	this->Camera.rotation = 0.f;
	
	countdown.Update(deltaTime);
}

void DefaultScene::Draw()
{
	BeginDrawing();

	Game->ClearBackground();

	Camera.BeginMode();
	Logo.Draw(0, 0);
	Camera.EndMode();

	EndDrawing();
}
