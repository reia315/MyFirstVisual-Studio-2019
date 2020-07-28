#pragma once
#include "../Component/Component.h"
#include <string>


//削除オブジェクト
//名前を持っていてその名前を持つオブジェクトが生成されたら
//速やかに消す
class DestoryObject:public Component
{
public :
   
	explicit DestoryObject(const std::string& name);

	virtual void Update()override;
	virtual void Draw()override;
private:
	 
	std::string m_name;

};