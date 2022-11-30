DreamOldale_MapScripts::
	.byte 0

DreamOldale_EventScript_RouteSign::
	msgbox DreamOldale_Text_RouteSign, MSGBOX_SIGN
	end

DreamOldale_EventScript_Sign1::
	msgbox DreamOldale_Text_Sign1, MSGBOX_SIGN
	end

DreamOldale_EventScript_Item1::
	finditem ITEM_POTION, 3
	end

DreamOldale_EventScript_Item5::
	finditem ITEM_SHARPEDONITE
	end

DreamOldale_EventScript_CaveLocked::
	goto_if_set FLAG_DREAM_OLDALE_DEBRIS, DreamOldale_EventScript_EnterCave
	msgbox UndergroundTunnels_Text_TooMuchDebris, MSGBOX_SIGN
	setflag FLAG_DREAM_OLDALE_DEBRIS
	end

DreamOldale_EventScript_EnterCave::
	msgbox UndergroundTunnels_Text_EnterCave, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, DreamOldale_EventScript_WarpToUndergroundTunnel
	closemessage
	end

DreamOldale_EventScript_WarpToUndergroundTunnel::
	clearflag FLAG_DREAM_OLDALE_DEBRIS
	setescapewarp MAP_DREAM_OLDALE, 31, 19
	warpholeto MAP_OLDALE_TOWN, 10, 9
	end

DreamOldale_Text_Sign1:
	.string "You can check your POKéMON's\n"
	.string "strength by pressing A on the\l"
	.string "summary view in your party.$"

DreamOldale_Text_RouteSign:
	.string "DREAM OLDALE\n"
	.string "{UP_ARROW} ROUTE 103$"
