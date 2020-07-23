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
	virtual void Update() {};
	//�`�揈��
	virtual void Draw() {};

	void SetGameObject(const std::weak_ptr<GameObject>& gameObject) ;

//private:

	std::weak_ptr<GameObject>m_gameObject;
	
};