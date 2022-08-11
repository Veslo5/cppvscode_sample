#pragma once
#include <memory>

#include "VScene.h"
#include "widgets/ScriptWidget.h"


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
        std::unique_ptr<VGameplay::ScriptWidget> scriptWidget;
    };
} // namespace VGameplay
