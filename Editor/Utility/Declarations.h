#ifndef DECLARATIONS_H_INCLUDED
#define DECLARATIONS_H_INCLUDED

#include "Application/ApplicationData.h"
#include "Application/Entity.h"
#include "Application/Map.h"

using EntityManagerEntry = GG_ApplicationDataEntry<'entityManager', GG_EntityManager>;
using MapEntry           = GG_ApplicationDataEntry<'map', GG_Map>;
using CameraEntry        = GG_ApplicationDataEntry<'camera', unsigned int>;

#endif // DECLARATIONS_H_INCLUDED
