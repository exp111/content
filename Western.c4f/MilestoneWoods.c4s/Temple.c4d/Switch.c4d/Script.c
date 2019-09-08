/*-- Schalter --*/

#strict

local fSpecial;

protected func Initialize()
  {
  SetAction("Normal");
  SetPhase(Random(1));
  }

protected func ControlLeft(object pClonk)
  {
  [DescSwitch]
  if(fSpecial) return();	  
  if (!GetPhase()) return();
  Sound("Click"); SetPhase();
  // Angeschlossene Objekte benachrichtigen
  var i,obj; while (obj = Local(i++))
  {	  
    if (Local(i)==1)
      obj->~ControlLeft(this());
    else if (Local(i)==0)
      obj->~ControlRight(this());
    else if (Local(i)==3)
      obj->~ControlUp(this());
    else if(Local(i)==2)
      obj->~ControlDown(this());
    i++;
  }
  if (Local()) SetPlrView(GetController(pClonk), Local());
  return(true);
  }

protected func ControlRight(object pClonk)
  {
  [DescSwitch]
  if (GetPhase()) return();
  Sound("Click"); SetPhase(1);
  // Angeschlossene Objekte benachrichtigen
  var i,obj; while (obj = Local(i++))
  {	  
    if(fSpecial)
      obj->~ControlSpecial(this());
    else if (Local(i)==0)
      obj->~ControlLeft(this());
    else if(Local(i)==1)
      obj->~ControlRight(this());
    else if (Local(i)==2)
      obj->~ControlUp(this());
    else if(Local(i)==3)
      obj->~ControlDown(this());
    i++;
  }
  if (Local()) SetPlrView(GetController(pClonk), Local());
  return(true);
  }

public func AttachBottom()
  {
  var obj = FindObject(0, 0,13,0,0);
  if (!obj) return();
  // Vertex ankleben
  SetVertex(0, 0, obj->GetX()-GetX()+GetVertex(0, 0, obj));
  SetVertex(0, 1, obj->GetY()-GetY()+GetVertex(0, 1, obj));
  SetAction("Attach", obj);
  return(true);
  }

public func AddTarget(object pTarget, int iDir)
  {
//  if (!iDir) iDir=1;
  var i; while (Local(i)) ++++i;
  Local(i++) = pTarget; Local(i) = iDir;
  }

public func IsSwitch() { return(true); }
