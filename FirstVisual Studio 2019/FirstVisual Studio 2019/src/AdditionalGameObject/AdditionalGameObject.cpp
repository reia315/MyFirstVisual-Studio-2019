#include "AdditionalGameObject.h"
#include "../ComponentManager/ComponentManager.h"
#include "../GameObjectManager/GameObjectManager.h"
#include "../TestOutPut/TestOutPut.h"
#include "../GameObject/GameObject.h"


AdditionalGameObject::AdditionalGameObject(const std::string& inputStr,char separated ) :
	//�����Ƃ����Ӗ��ɂ����ق�������
	m_conditionsName{inputStr},
	m_separated { separated }{}

AdditionalGameObject::AdditionalGameObject(const std::weak_ptr<const AdditionalGameObject>& other) :
	m_conditionsName{other.lock()->m_conditionsName},
	m_separated{ other.lock()->m_separated } {}

std::weak_ptr<Component> AdditionalGameObject::CloneComponent() const
{
	return ComponentManager::GenerateComponent<AdditionalGameObject>(std::dynamic_pointer_cast<const AdditionalGameObject>(shared_from_this()));
}


//�R�}���h���Q�ŋ�؂�O����add����Ŗ��O���󂯎��
void AdditionalGameObject::Input(const std::string& inputStr)
{
	int idx = inputStr.find(m_separated);

	std::string command = inputStr.substr(0, idx);
	if (command == m_conditionsName)
	{
		std::string objectName = inputStr.substr(idx + 1, inputStr.length());

		auto gameObject = GameObjectManager::GenerateGameObject(objectName);
		gameObject.lock()->CreateComponent<TestOutPut>();
	}
	
}
