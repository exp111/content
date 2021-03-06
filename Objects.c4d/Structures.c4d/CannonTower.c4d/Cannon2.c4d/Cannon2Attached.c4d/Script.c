/*--- Artilleriegeschütz (angeschraubt) ---*/

#strict

#include CTW2

/* Einige andere Eigenschaften */

protected func RotationSpeed() { return(1); }
protected func CannonMobileID() { return(CTW5); }
protected func CannonAmmo(object obj) { return((GetOCF(obj) & OCF_Collectible()) || (GetOCF(obj) & OCF_CrewMember()) ); }
protected func CannonPowderNeeded(object obj) { return(2 + 2 * ((GetOCF(obj) & OCF_CrewMember()) != 0) ); }
protected func CannonPower(object obj) { return(20 - 2 * ((GetOCF(obj) & OCF_CrewMember()) != 0) ); }
protected func CannotShootMenuName(object obj) { return Format("$TxtShootsn$", obj->GetName(), CannonPowderNeeded(obj)); }

