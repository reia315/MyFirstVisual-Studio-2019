#include "AdditionalGameObject.h"
#include "../ComponentManager/ComponentManager.h"
#include "../GameObjectManager/GameObjectManager.h"
#include "../TestOutPut/TestOutPut.h"
#include "../GameObject/GameObject.h"


AdditionalGameObject::AdditionalGameObject(char named, const std::string& findCommand) :m_gameObjectName{ named }, m_findCommand{findCommand} {}

AdditionalGameObject::AdditionalGameObject(const std::weak_ptr<const AdditionalGameObject>& other) :m_gameObjectName{ other.lock()->m_gameObjectName }, m_findCommand{other.lock()->m_findCommand} {}

std::weak_ptr<Component> AdditionalGameObject::CloneComponent() const
{
	return ComponentManager::GenerateComponent<AdditionalGameObject>(std::dynamic_pointer_cast<const AdditionalGameObject>(shared_from_this()));
}


//コマンドを２つで区切る前方でadd後方で名前を受け取る
void AdditionalGameObject::Input(const std::string& inputStr)
{
	int idx = inputStr.find(m_gameObjectName);

	std::string command = inputStr.substr(0, idx);
	if (command == m_findCommand)
	{
		std::string objectName = inputStr.substr(idx + 1, inputStr.length());

		auto gameObject = GameObjectManager::GenerateGameObject(objectName);
		gameObject.lock()->CreateComponent<TestOutPut>();
	}
	
}
