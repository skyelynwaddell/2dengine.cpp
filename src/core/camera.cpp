#include "camera.h"
#include "utils.h"

Camera* Camera::s_instance = nullptr;

void Camera::Update(float dt)
{
    if (m_target == nullptr) return;

    int target_x = m_target->X - (SCREEN_WIDTH / 2);
    int target_y = m_target->Y - (SCREEN_HEIGHT / 2);

    int max_width = SCREEN_WIDTH - m_viewbox.w;
    int max_height = SCREEN_HEIGHT - m_viewbox.h;

    m_viewbox.x = target_x;
    m_viewbox.y = target_y;

    //m_viewbox.x = Utils::clamp_int(m_viewbox.x, 0, max_width);
    //m_viewbox.y = Utils::clamp_int(m_viewbox.y, 0, max_height);

    m_position = Vector2(m_viewbox.x,m_viewbox.y);
}