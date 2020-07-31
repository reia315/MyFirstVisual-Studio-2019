#pragma once
#include "../Component/Component.h"

class  TestOutPut:public Component
{
public:

     virtual void Update()override;

     virtual void Draw()override;

     virtual std::weak_ptr<Component> CloneComponent() const override;
};