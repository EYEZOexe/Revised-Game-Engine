//
// Created by NAT20 on 10/12/2023.
//

#ifndef PROJECTILE_H
#define PROJECTILE_H

#include "Framework/Actor.h"

namespace labyrinth_engine
{
    class Projectile : public Actor
    {
    public:
        Projectile(World* a_world, Actor* a_owner, std::string& a_texturePath, float a_speed, float a_damage);
        ~Projectile();

    private:

    };
}

#endif //PROJECTILE_H
