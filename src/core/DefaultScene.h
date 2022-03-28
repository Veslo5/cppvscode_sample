#pragma once

#include "VScene.h"
#include "VTimer.h"
#include "raylib-cpp.hpp"

class DefaultScene : public Vengine::VScene
{
public:
	DefaultScene(std::string name, Vengine::VGame* game);
	~DefaultScene() override = default;

	raylib::Camera2D Camera;
	raylib::Texture2D Logo;	
	Vengine::VTimer countdown;

	void TimerCallback();

	void UnloadContent() override;
	void LoadContent() override;
	void Update(float deltaTime) override;
	void Draw() override;
};
