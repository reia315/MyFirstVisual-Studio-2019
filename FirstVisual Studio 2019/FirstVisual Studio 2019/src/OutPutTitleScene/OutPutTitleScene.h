#pragma once
#include "../Component/Component.h"
#include <memory>


class OutPutTitleScene:public Component
{
public:

	virtual void Update() override;

	virtual void Draw() override;

	virtual std::weak_ptr<Component> CloneComponent() const override;

};