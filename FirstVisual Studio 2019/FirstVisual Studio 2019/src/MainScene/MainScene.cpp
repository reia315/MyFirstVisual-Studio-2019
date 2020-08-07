#include "MainScene.h"
#include "../GameObject/GameObject.h"
#include "../ComponentManager/ComponentManager.h"
#include "../GameObjectManager/GameObjectManager.h"
#include "../TestOutPut/TestOutPut.h"
#include "../DestoryObject/DestoryObject.h"
#include "../CloneObject/CloneObject.h"
#include "../AdditionalGameObject/AdditionalGameObject.h"
#include "../EndProcessing/EndProcessing.h"

void MainScnen::State()
{
	auto gameObject = GameObjectManager::GenerateGameObject("ObjectA");
	gameObject.lock()->CreateComponent<TestOutPut>();
	gameObject.lock()->CreateComponent<DestoryObject>("ObjectB");
	gameObject.lock()->CreateComponent<CloneObject>(3);
	gameObject.lock()->CreateComponent<AdditionalGameObject>("add", ',');
	gameObject.lock()->CreateComponent<EndProcessing>("end");
}

//I—¹ˆ—‚Í‚È‚µ
void MainScnen::End()
{
}
