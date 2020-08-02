#include "GameObjectManager.h"
#include "../GameObject/GameObject.h"


std::forward_list<std::shared_ptr<GameObject>>GameObjectManager::m_gameObject;

std::forward_list<std::shared_ptr<GameObject>>GameObjectManager::m_addGaneObject;



std::forward_list<std::weak_ptr<GameObject>> GameObjectManager::SearchObject(const std::string& name)
{
	std::forward_list<std::weak_ptr<GameObject>> matchObjectName;

	for (const auto& gameObject : m_gameObject)
	{
		if (gameObject->GetName() == name)
		{
			matchObjectName.push_front(gameObject);
		}
	}

	return matchObjectName;
}

void GameObjectManager::UpdateGamObjectList()
{
	for (const auto& gameObject : m_addGaneObject)
	{
		m_gameObject.push_front(gameObject);
	}
}

std::weak_ptr<GameObject> GameObjectManager::GenerateGameObject(const std::string& name)
{
	auto gameObject =std::make_shared<GameObject>(name);
	m_gameObject.push_front(gameObject);
	return gameObject;
}

void GameObjectManager::DeleteGameObject()
{
	//�����_��[]�����_���`���v�^�[�i�j�p�����[�^�[��`�߁o�p�����X�e�[�g�����g�i�j�֐��Ăяo�����G
	//gameObject�̒���IsDead��true�ɂȂ��Ă�v�f���폜����
	m_gameObject.remove_if([](const auto& gameObject) {return gameObject->IsDead(); });//�����_�����g�p
}


std::weak_ptr<GameObject> GameObjectManager::CloneGameObject(const std::weak_ptr<GameObject>& gameObject)
{
	//make_shared<�N���X>(�R���X�g���N�^�̈���)
	//���̍s�͎��̂��쐬
	auto clone = std::make_shared<GameObject>(gameObject);
	m_addGaneObject.push_front(clone);
	return clone;
}
