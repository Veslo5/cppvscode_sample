add_library(vengine STATIC 
VTimer.cpp 
VScene.cpp 
VPersistentData.cpp 
VObjectHolder.cpp 
VGame.cpp 
VDataManager.cpp 
VDataHolder.cpp
VAtlas.cpp
VAnimation.cpp
SceneManager.cpp
DefaultScene.cpp
)
target_include_directories(vengine PUBLIC ${raylib400_src} PUBLIC ${raylibcpp_src})