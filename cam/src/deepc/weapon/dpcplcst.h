#pragma once
#ifndef __DPCPLCST_H
#define __DPCPLCST_H

typedef enum eStats {
   // stats
   kStatStrength,
   kStatEndurance,
   kStatPsi,
   kStatAgility,
   kStatCyber,

   kStatPad = 0xFFFFFFFF,
};

typedef enum eWeaponSkills {  
   // weapon skills
   // Note: stupidly, these need to stay in synch with the string constants for
   // the weapon type property in dpcgunpr. 
   kWeaponConventional,
   kWeaponEnergy,
   kWeaponHeavy,
   kWeaponAnnelid,
   kWeaponPsiAmp,

   kWeaponPad = 0xFFFFFFFF,
};

typedef enum eTechSkills {
   // tech skills
   kTechHacking,
   kTechRepair,
   kTechModify,
   kTechMaintenance,
   kTechResearch,

   kTechPad = 0xFFFFFFFF,
};

typedef enum ePsiPowers 
{  
   // psi skills
   kPsiLevel1,    
   kPsiPsiScreen,
   kPsiStillHand,
   kPsiPull,
   kPsiQuickness,    
   kPsiCyber, 
   kPsiCryokinesis,  
   kPsiCodebreaker,

   kPsiLevel2,
   kPsiStability,
   kPsiBerserk,
   kPsiRadShield,  
   kPsiHeal,      
   kPsiMight,     
   kPsiPsi,
   kPsiImmolate,

   kPsiLevel3,
   kPsiFabricate,
   kPsiElectro,
   kPsiAntiPsi,
   kPsiToxinShield,  
   kPsiRadar,    
   kPsiPyrokinesis,  
   kPsiTerror,

   kPsiLevel4,
   kPsiInvisibility,
   kPsiSeeker,
   kPsiDampen,    
   kPsiVitality,
   kPsiAlchemy,
   kPsiCyberHack,
   kPsiSword,

   kPsiLevel5,
   kPsiMajorHealing,
   kPsiSomaDrain,    
   kPsiTeleport,
   kPsiEnrage,
   kPsiForceWall,    
   kPsiMines,
   kPsiShield,

   kPsiMax,          //34
   kPsiNone = kPsiMax,
   kPsiPad = 0xFFFFFFFF,
};

#define NUM_PSI_LEVELS  5

typedef enum ePlayerEquip
{
   // main items
   kEquipWeapon,
   kEquipWeaponAlt,
   kEquipArmor,
   kEquipSpecial,
   kEquipSpecial2,

   // softs
   kEquipPDA,
   kEquipHack,
   kEquipModify,
   kEquipRepair,
   kEquipResearch,

   // fake inventory slots
   kEquipFakeNanites,
   kEquipFakeCookies,
   kEquipFakeLogs,
   kEquipFakeKeys,

   kEquipCompass,

   kEquipMax, // last
   kEquipPad = 0xFFFFFFFF,
};

typedef enum eService {
   // stats
   kServiceMarines,
   kServiceNavy,
   kServiceOSA,

   kServicePad = 0xFFFFFFFF,
};

#endif  // __DPCPLCST_H