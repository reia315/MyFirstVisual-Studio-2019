#pragma once
#include "../Component/Component.h"
#include <string>


//�폜�I�u�W�F�N�g
//���O�������Ă��Ă��̖��O�����I�u�W�F�N�g���������ꂽ��
//���₩�ɏ���
class DestoryObject:public Component
{
public :
   
	DestoryObject(const std::string& name);

	virtual void Update()override;

private:
	 
	std::string m_name;

};