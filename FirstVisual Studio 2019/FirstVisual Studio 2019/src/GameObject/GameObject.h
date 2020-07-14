#pragma once
#include <string>

#include <vector>

#include <memory>

class GameObject
{
public:
	GameObject(const std::string name);


	const std::string GetName();

private:

	std::string m_name;

};