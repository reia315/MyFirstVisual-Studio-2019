#pragma once
#include <string>
class GameObject
{
public:
	//constリファレンスを使用
	GameObject(const std::string& name);
	

	//const参照型の戻り値（仕様用途はconstリファレンスと同じ）
	const std::string& GetName()const;

private:

	std::string m_name;

};