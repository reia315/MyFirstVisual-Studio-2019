#pragma once
#include "../Component/Component.h"

class CloneObject:public Component
{
public:
    explicit CloneObject(int num);

    explicit CloneObject(const std::weak_ptr<const CloneObject>& other);

    virtual void Update()override;

    virtual std::weak_ptr<Component> CloneComponent() const override;

private:

    int m_cloneNum;

    int m_eraseNum{ 0 };

};