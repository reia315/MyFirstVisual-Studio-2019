#pragma once
#include <list>//�O���z��
#include <memory>//�X�}�[�g�|�C���^

class Component;

class ComponentManager
{
public:

	//�X�V
	static void update();
	//�`��
	static void draw();
	//�R���|�[�l���g�N���X�̐���
	template<class T,class... Args >
    static std::weak_ptr<Component> GenerateComponent(Args... args);


private:

	static std::list<std::shared_ptr<Component>>m_component;
};

template<class T,class ...Args>
inline std::weak_ptr<Component> ComponentManager::GenerateComponent(Args ...args)
{
	auto component = std::make_shared<T>(args...);
	m_component.push_back(component);
	return component;
}
