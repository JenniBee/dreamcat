global Command;
global Object2;
global Object1;

global button_lookat;
global button_talkto;
global button_pickup;
global button_use;
global button_give;
global button_sniff;

global lookat_over;
global talkto_over;
global pickup_over;
global use_over;
global give_over;
global sniff_over;

global widget_button_lookat;
global widget_button_talkto;
global widget_button_pickup;
global widget_button_use;
global widget_button_give;
global widget_button_sniff;

function verb_setBar(caption)
{
  Command.Running = caption;
}

function verb_initBar()
{
  lookat_over  = false;
  talkto_over  = false;
  pickup_over  = false;
  use_over     = false;
  give_over    = false;
  sniff_over   = false;

  widget_button_lookat  = WinMenu.GetWidget("LookAtContainer");
  widget_button_talkto  = WinMenu.GetWidget("TalkToContainer");
  widget_button_pickup  = WinMenu.GetWidget("PickUpContainer");
  widget_button_use     = WinMenu.GetWidget("UseContainer");
  widget_button_give    = WinMenu.GetWidget("GiveContainer");
  widget_button_sniff   = WinMenu.GetWidget("SniffContainer");

  button_lookat = widget_button_lookat.GetEntity();
  button_talkto = widget_button_talkto.GetEntity();
  button_pickup = widget_button_pickup.GetEntity();
  button_use    = widget_button_use.GetEntity();
  button_give   = widget_button_give.GetEntity();
  button_sniff  = widget_button_sniff.GetEntity();

  Command.Running = "";
}

function verb_cleanBar()
{
  Command.Verb = "";
  Command.Object1_caption = "";
  Command.Object1_name = "";
  Command.Object1 = "";
  Command.Object2_caption = "";
  Command.Object2_name = "";
  Command.Object2 = "";
  Command.Running = "";
  
  lookat_over=false;
  talkto_over=false;
  pickup_over=false;
  use_over=false;
  give_over=false;
  sniff_over=false;

  button_lookat.SetSprite("interface\verbbar\lookat_off.bmp");
  button_talkto.SetSprite("interface\verbbar\talkto_off.bmp");
  button_pickup.SetSprite("interface\verbbar\pickup_off.bmp");
  button_use.SetSprite("interface\verbbar\use_off.bmp");
  button_give.SetSprite("interface\verbbar\give_off.bmp");
  button_sniff.SetSprite("interface\verbbar\sniff_off.bmp");

  var ActObj = Game.ActiveObject;
  if(ActObj!=null) ActObj.ApplyEvent("MouseEntry");
}

function verb_hover(hoverme)
{
  if(Command.Verb != hoverme)
  {
    switch(hoverme)
    {
      case "Look at":
        button_lookat.SetSprite("interface\verbbar\lookat_def.bmp");
        break;
      case "Talk to":
        button_talkto.SetSprite("interface\verbbar\talkto_def.bmp");
        break;
      case "Pick up":
        button_pickup.SetSprite("interface\verbbar\pickup_def.bmp");
        break;
      case "Use":
        button_use.SetSprite("interface\verbbar\use_def.bmp");
        break;
      case "Give":
        button_give.SetSprite("interface\verbbar\give_def.bmp");
        break;
      case "Sniff":
        button_sniff.SetSprite("interface\verbbar\sniff_def.bmp");
        break;
    }
  }
}

function verb_unhover(unhoverme)
{
  if(Command.Verb != unhoverme)
  {
    switch(unhoverme)
    {
      case "Look at":
        button_lookat.SetSprite("interface\verbbar\lookat_off.bmp");
        break;
      case "Pick up":
        button_pickup.SetSprite("interface\verbbar\pickup_off.bmp");
        break;
      case "Talk to":
        button_talkto.SetSprite("interface\verbbar\talkto_off.bmp");
        break;
      case "Use":
        button_use.SetSprite("interface\verbbar\use_off.bmp");
        break;
      case "Give":
        button_give.SetSprite("interface\verbbar\give_off.bmp");
        break;
      case "Sniff":
        button_sniff.SetSprite("interface\verbbar\sniff_def.bmp");
        break;
    }
  }
  else
  {
    switch(unhoverme)
    {
      case "Look at":
        button_lookat.SetSprite("interface\verbbar\lookat_on.bmp");
        break;
      case "Pick up":
        button_pickup.SetSprite("interface\verbbar\pickup_on.bmp");
        break;
      case "Talk to":
        button_talkto.SetSprite("interface\verbbar\talkto_on.bmp");
        break;
      case "Use":
        button_use.SetSprite("interface\verbbar\use_on.bmp");
        break;
      case "Give":
        button_give.SetSprite("interface\verbbar\give_on.bmp");
        break;
      case "Sniff":
        button_sniff.SetSprite("interface\verbbar\sniff_on.bmp");
        break;
    }
  }
}

function verb_apply(appverb)
{
  verb_cleanBar();
  Command.Verb = appverb;
  switch(appverb)
  {
    case "Look at":
      button_lookat.SetSprite("interface\verbbar\lookat_on.bmp");
      self.ApplyEvent("LookAt");
      break;
    case "Pick up":
      button_pickup.SetSprite("interface\verbbar\pickup_on.bmp");
      self.ApplyEvent("PickUp");
      break;
    case "Talk to":
      button_talkto.SetSprite("interface\verbbar\talkto_on.bmp");
      self.ApplyEvent("TalkTo");
      break;
    case "Use":
      button_use.SetSprite("interface\verbbar\use_on.bmp");
      self.ApplyEvent("Use");
      break;
    case "Give":
      button_give.SetSprite("interface\verbbar\give_on.bmp");
      self.ApplyEvent("Give");
      break;
    case "Sniff":
      button_sniff.SetSprite("interface\verbbar\sniff_on.bmp");
      self.ApplyEvent("Sniff");
      break;
  }
}

function verb_doesNotWork()
{
  var ran;
  switch(Command.Verb)
  {
    case "Look at":
      actor.Talk("There is nothing special about it.");
      break;
    case "Talk to":
      actor.Talk("It doesn't even have lips!");
      break;
    case "Pick up":
      actor.Talk("No! I don't want this!");
      break;
    case "Use":
      ran = Random(0,1);
      if(ran==0) actor.Talk("That doesn't work!");
      if(ran==1) actor.Talk("That makes no sense at all!");
      break;
    case "Give":
      actor.Talk("I can't give this to that!");
      break;
    case "Sniff":
      actor.Talk("I'm not smelling that!");
      break;
  }
}

function verb_switchButtons(mode)
{
  switch(mode)
  {
    case 1:
      widget_button_lookat.Visible  = true;
      widget_button_talkto.Visible  = true;
      widget_button_pickup.Visible  = true;
      widget_button_use.Visible     = true;
      widget_button_give.Visible    = true;
      widget_button_sniff.Visible   = true;
      break;
    case 0:
    default:
      widget_button_lookat.Visible  = false;
      widget_button_talkto.Visible  = false;
      widget_button_pickup.Visible  = false;
      widget_button_use.Visible     = false;
      widget_button_give.Visible    = false;
      widget_button_sniff.Visible   = false;
      break;
  }
}

function verb_changeMode(mode)
{
  switch(mode)
  {
    case 2:
      WinMenu.SetImage("interface\verbbar\no_verbbar.bmp");
      Game.InventoryVisible = false;
      verb_switchButtons(0);
      break;
    case 1:
      WinMenu.SetImage("interface\verbbar\verbbar_talk.bmp");
      Game.InventoryVisible = false;
      verb_switchButtons(0);
      break;
    case 0:
    default:
      WinMenu.SetImage("interface\verbbar\verbbar.bmp");
      Game.InventoryVisible = true;
      verb_switchButtons(1);
      break;
  }
}

function verb_showBar()
{
  Game.InventoryVisible = true;
  WinMenu.Visible = true;
  verb_switchButtons(1);
}

function verb_hideBar()
{
  Game.InventoryVisible = false;
  WinMenu.Visible = false;
  verb_switchButtons(0);
}
