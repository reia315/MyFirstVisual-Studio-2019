#include "EndProcessing.h"
#include "../ComponentManager/ComponentManager.h"
#include "../Game/Game.h"

EndProcessing::EndProcessing(const std::string& inputStr):
    m_endComand{inputStr}
{
}

std::weak_ptr<Component> EndProcessing::CloneComponent() const
{
    return ComponentManager::GenerateComponent<EndProcessing>(m_endComand);
}

void EndProcessing::Input(const std::string& inputStr)
{
    if (inputStr == m_endComand)
    {
        Game::End();
    }
}




