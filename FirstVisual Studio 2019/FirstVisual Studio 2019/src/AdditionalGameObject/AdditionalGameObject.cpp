#include "AdditionalGameObject.h"
#include "../ComponentManager/ComponentManager.h"
#include "../GameObjectManager/GameObjectManager.h"
#include "../TestOutPut/TestOutPut.h"
#include "../GameObject/GameObject.h"


AdditionalGameObject::AdditionalGameObject(const std::weak_ptr<const AdditionalGameObject>& other){}

std::weak_ptr<Component> AdditionalGameObject::CloneComponent() const
{
	return ComponentManager::GenerateComponent<AdditionalGameObject>(std::dynamic_pointer_cast<const AdditionalGameObject>(shared_from_this()));
}

void AdditionalGameObject::Input(const std::string& inputStr)
{
	auto gameObject = GameObjectManager::GenerateGameObject(inputStr);
	gameObject.lock()->CreateComponent<TestOutPut>();
}
