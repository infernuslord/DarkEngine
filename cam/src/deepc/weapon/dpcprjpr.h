// Deep Cover projectile related properties
#pragma once

#ifndef __DPCPRJPR_H
#define __DPCPRJPR_H

#ifndef PROPFACE_H
#include <propface.h>
#endif // !PROPFACE_H

#ifndef __DPCPJBAS_H
#include <dpcpjbas.h>
#endif // !__DPCPJBAS_H

F_DECLARE_INTERFACE(IProjectileProperty);

#undef INTERFACE
#define INTERFACE IProjectileProperty

DECLARE_PROPERTY_INTERFACE(IProjectileProperty)
{
   DECLARE_UNKNOWN_PURE();                // IUnknown methods 
   DECLARE_PROPERTY_PURE();               // IProperty methods
   DECLARE_PROPERTY_ACCESSORS(sProjectile*);  // Type-specific accessors, by reference
};

#define PROP_PROJECTILE_DESC "Projectile"

EXTERN IProjectileProperty *g_pProjectileProperty;

EXTERN void ProjectilePropertyInit();
EXTERN BOOL ProjectileGet(ObjID objID, sProjectile **ppProjectile);
#define PROJECTILE_DESC_SET(objID, ppParams) \
   PROPERTY_SET(g_projectileProperty, objID, (sProjectile**)ppParams)
#define PROJECTILE_DESC_DELETE(objID) \
   IProperty_Delete(g_projectileProperty, objID)

#endif  // !__DPCPRJPR_H