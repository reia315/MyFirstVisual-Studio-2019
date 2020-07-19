#pragma once
#include <memory>

//�O���錾
class GameObject;

class Component
{
public:
	//�R���X�g���N�^
	Component();

	//�X�V����
	void Update();
	//�`�揈��
	void Draw();

	void SetGameObject(std::weak_ptr<GameObject> gameObject);
private:

	std::weak_ptr<GameObject>m_gameObject;
	
};