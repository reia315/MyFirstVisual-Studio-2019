#include "CloneObject.h"
#include "../GameObject/GameObject.h"
#include "../GameObjectManager/GameObjectManager.h"
#include "../ComponentManager/ComponentManager.h"

CloneObject::CloneObject(int Num) :m_cloneNum{Num}{}

CloneObject::CloneObject(const std::weak_ptr<const CloneObject>& other):
	m_cloneNum{other.lock()->m_cloneNum},
	m_eraseNum{other.lock()->m_eraseNum}{}

void CloneObject::Update()
{
	if (m_cloneNum - m_eraseNum <= 0)return;

	m_eraseNum++;

	auto clone = GameObjectManager::CloneGameObject(GetGameObject());

	for (const auto& component : GetGameObject().lock()->GetComponentAll())
	{
		clone.lock()->AddComponent(component.lock()->CloneComponent());
	}
}

std::weak_ptr<Component> CloneObject::CloneComponent() const
{
	return ComponentManager::GenerateComponent<CloneObject>(std::dynamic_pointer_cast<const CloneObject>(shared_from_this()));
}
