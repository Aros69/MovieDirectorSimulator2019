#ifndef GKIT2LIGHT_MASTER_CHARANIM_CUBECONTROLLER_H
#define GKIT2LIGHT_MASTER_CHARANIM_CUBECONTROLLER_H

#include "mat.h"
#include "vec.h"
#include "window.h"
#include "Skeleton.h"

class CubeController {
public:
    CubeController();

    /**
     *
     * @param dt temp écoulé depuis dernier appel en seconde
     */
    virtual void update(const float dt);

    void turnXZ(const float &rot_angle_v);

    void accelerate(const float &dt);

    void deccelerate(const float &dt);

    void setVelocityMax(const float vmax) { m_vMax = vmax; }

    void setPosition(const Vector &p) { m_ch2w(p); }

    void setVelocity(const float v) { m_v = v; }

    void setForward(bool forward) { m_forward = forward; }

    const Vector direction() const { return m_ch2w(Vector(1, 0, 0)); }

    const Point getCharacterPosition() const { return m_ch2w(Point(0, 0, 0)); }

    const Transform getMatChar() const { return m_ch2w; }

    float velocity() const { return m_v; }

    float velocityMax() const { return m_vMax; }

protected:
    Transform m_ch2w;   // matrice du character vers le monde
    // le personnage se déplace vers X
    // il tourne autour de Y
    // Z est sa direction droite

    float m_v;          // le vecteur vitesse est m_v * m_ch2w * Vector(1,0,0)
    float m_vMax;       // ne peut pas accélérer plus, le cube ne peux pas faire plus que Translation(10,0,0) par seconde
    bool m_forward;     // direction de l'accélération
};

#endif //GKIT2LIGHT_MASTER_CHARANIM_CUBECONTROLLER_H
