#include "CubeController.h"

CubeController::CubeController() {
    m_v = 0;
    m_vMax = 250;
    m_forward = true;
}

void CubeController::update(const float dt) {
    bool moveKeyPressed = false;
    if (key_state('z')) {
        setForward(true);
        accelerate(dt);
        moveKeyPressed = true;
    }
    if (key_state('q')) {
        turnXZ(5.0);
    }
    if (key_state('s')) {
        setForward(false);
        accelerate(dt);
        moveKeyPressed = true;
    }
    if (key_state('d')) {
        turnXZ(-5.0);
    }
    if (!moveKeyPressed) {
        deccelerate(dt);
    }
    if (key_state('x')) {
        std::cout << "dt = " << dt << ", m_v = " << m_v << "\n";
    }
    m_ch2w = m_ch2w * Translation(m_v*dt, 0, 0);
}

void CubeController::turnXZ(const float &rot_angle_v) {
    m_ch2w = m_ch2w * RotationY(rot_angle_v);
}

void CubeController::accelerate(const float &dt) {
    float acceleration = 45;
    if ((m_forward && m_v < 0) || (!m_forward && m_v > 0)) {
        m_v = m_v / 1.1f;
    }
    if (m_v + dt*acceleration >= m_vMax || m_v + dt*acceleration <= -1 * m_vMax) {
        if (m_forward) {
            m_v = m_vMax;
        } else {
            m_v = -m_vMax;
        }
    } else {
        if (m_forward) {
            m_v += dt*acceleration;
        } else {
            m_v -= dt*acceleration;
        }
    }
}

void CubeController::deccelerate(const float &dt) {
    float acceleration = 50;
    if ((!m_forward && m_v + dt*acceleration >= 0) ||
        (m_forward && m_v - dt*acceleration <= 0)) { m_v = 0; }
    if (m_v > 0 && m_forward) { m_v -= dt*acceleration; }
    else if (m_v < 0 && !m_forward) { m_v += dt*acceleration; }
}
