#include "OutPutTitleScene.h"
#include "../ComponentManager/ComponentManager.h"
#include <iostream>

void OutPutTitleScene::Update()
{
	std::cout << "TitleScene‚Å‚·" << std::endl;
}

void OutPutTitleScene::Draw()
{
}

std::weak_ptr<Component> OutPutTitleScene::CloneComponent() const
{
	return ComponentManager::GenerateComponent<OutPutTitleScene>();
}
