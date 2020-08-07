#pragma once
#include "../Component/Component.h"
#include <string>

class EndProcessing :public Component
{
public:
	explicit EndProcessing(const std::string& inputStr);


	virtual std::weak_ptr<Component>CloneComponent()const override;

	virtual void Input(const std::string& inputStr) override;

private:

	std::string m_endComand;

};