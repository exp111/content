#strict

public func Activate(pCaster)
{
  // Effekt pr�fen
  var iChkEff;
  if (iChkEff = CheckEffect("FFWallPSpell", 0, 150)) return (iChkEff!=-1 && RemoveObject());
  // Wand erstellen
  var iPos = -25; if (GetDir(pCaster) == DIR_Right()) iPos = +25;
  ObjectSetAction( CreateObject(FRCW,iPos,50,GetOwner()) ,"Field",pCaster);
  CastParticles("MSpark", 5, 50, 0,0, 100, 200, RGBa(100,100,255,128), RGBa(0,0,255,0));
  CreateParticle("MSpark", 0,0, 1000, RGBa(50,50,255,150));
  RemoveObject();
  return(1);
}

public func GetSpellClass(object pMage) { return(WATR); }
public func GetSpellCombo(pMage) { return ("222"); } // (1: Backward; 2: Down; 3: Forward; 4: Throw; 5: Jump; 6: Dig)
public func GetResearchBase () { return (MFFS); }
