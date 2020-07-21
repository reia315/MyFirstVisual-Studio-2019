#include "Component.h"
#include "../GameObject/GameObject.h"
#include <iostream>

using namespace std;

Component::Component()
{
}

void Component::Update()
{
	cout <<m_gameObject.lock()->GetName()<< "Update" << endl;
}

void Component::Draw()
{
	cout <<m_gameObject.lock()->GetName()<< "Draw" << endl;
}

void Component::SetGameObject(const std::weak_ptr<GameObject>& gameObject)
{
	m_gameObject = gameObject;
}
