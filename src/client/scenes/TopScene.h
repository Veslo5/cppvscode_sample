#pragma once

#include "VScene.h"

namespace VGameplay
{
    class TopScene : public Vengine::VScene
    {
    public:
        TopScene(std::string name, Vengine::VGame* game);
        ~TopScene() override = default;

        void UnloadContent() override;
        void LoadContent() override;
        void Update(float deltaTime) override;
        void Draw() override;
    private:
        
    };
} // namespace VGameplay
