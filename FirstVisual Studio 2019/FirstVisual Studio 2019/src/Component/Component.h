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

	//Object���Ƃ��Ă���
	const std::weak_ptr<GameObject>& GetGameObject() const; 

	void SetGameObject(const std::weak_ptr<GameObject>& gameObject) ;

//private:

	std::weak_ptr<GameObject>m_gameObject;
	
};