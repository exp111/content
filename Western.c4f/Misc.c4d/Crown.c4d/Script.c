#strict

protected func Initialize()
  {
  // Blinkaktivitšt setzen
  SetAction("Glitter0");
  return(1);
  }

// Auftreffsound
protected func Hit() { return(Sound("Crystal*")); }

// Aktivitšt
protected func Glittering()
  {
  // Effekt
  return(SetAction(Format("Glitter%d", Random(5))));
  }
