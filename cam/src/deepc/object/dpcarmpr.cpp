#include <dpcarmpr.h>

#include <propert_.h>
#include <dataops_.h>
#include <prophash.h>

#include <sdesc.h>
#include <sdesbase.h>

/////////////////////////////////////////////////////////////
// Armor values
/////////////////////////////////////////////////////////////

// the all new improved property system...
// data ops
class cArmorDataOps: public cClassDataOps<sArmor>
{
};

// storage class
class cArmorStore: public cHashPropertyStore<cArmorDataOps>
{
};

// property implementation class
class cArmorProp: public cSpecificProperty<IArmorProperty, &IID_IArmorProperty, sArmor*, cArmorStore>
{
   typedef cSpecificProperty<IArmorProperty, &IID_IArmorProperty, sArmor*, cArmorStore> cParent; 

public:
   cArmorProp(const sPropertyDesc* desc)
      : cParent(desc)
   {
   }

   STANDARD_DESCRIBE_TYPE(sArmor); 

};

IArmorProperty *g_ArmorProperty;

static sFieldDesc ArmorFields[] = 
{
   {"Combat", kFieldTypeFloat, FieldLocation(sArmor, m_combat),},
   {"Toxic", kFieldTypeFloat, FieldLocation(sArmor, m_toxic),},
   {"Radiation", kFieldTypeFloat, FieldLocation(sArmor, m_radiation),},
};

static sStructDesc ArmorStructDesc = 
   StructDescBuild(sArmor, kStructFlagNone, ArmorFields);

IArmorProperty *CreateArmorProperty(sPropertyDesc *desc, ePropertyImpl impl)
{
   StructDescRegister(&ArmorStructDesc);
   return new cArmorProp(desc);
}

static sPropertyDesc ArmorDesc = 
{
   PROP_Armor, 0,
   NULL, 0, 0,
   {"GameSys", "Armor"},
};

void ArmorPropertyInit()
{
   g_ArmorProperty = CreateArmorProperty(&ArmorDesc, kPropertyImplDense);
}

void ArmorPropertyTerm()
{
   SafeRelease(g_ArmorProperty);
}

BOOL ArmorGet(ObjID objID, sArmor **ppArmor)
{
   return g_ArmorProperty->Get(objID, ppArmor);
}


