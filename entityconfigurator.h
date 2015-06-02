#ifndef ENTITYCONFIGURATOR_H
#define ENTITYCONFIGURATOR_H

#include "animation.h"
#include "resourcemanager.h"

class Entity;

class EntityConfigurator
{
public:
    EntityConfigurator();
    void init(EntityState::typeOfEntity type, Entity* target);
};

#endif // ENTITYCONFIGURATOR_H
