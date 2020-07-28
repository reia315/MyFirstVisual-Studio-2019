#pragma once
#include "../Component/Component.h"
#include <string>


//�폜�I�u�W�F�N�g
//���O�������Ă��Ă��̖��O�����I�u�W�F�N�g���������ꂽ��
//���₩�ɏ���
class DestoryObject:public Component
{
public :
   
	explicit DestoryObject(const std::string& name);

	virtual void Update()override;
	virtual void Draw()override;
private:
	 
	std::string m_name;

};