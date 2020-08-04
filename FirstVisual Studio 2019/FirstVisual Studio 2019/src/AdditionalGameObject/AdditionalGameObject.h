#pragma once
#include "../Component/Component.h"
#include <string>

class AdditionalGameObject :public Component
{
public:

	explicit AdditionalGameObject(const std::weak_ptr<const AdditionalGameObject>& other);


	virtual std::weak_ptr<Component>CloneComponent()const override;

	virtual void Input(const std::string& inputStr)override;

private:
};