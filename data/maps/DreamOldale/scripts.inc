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
	msgbox DreamOldale_Text_TooMuchDebris, MSGBOX_SIGN
	end

DreamOldale_Text_Sign1:
	.string "You can check your POKéMON's\n"
	.string "strength by pressing A on the\l"
	.string "summary view in your party.$"

DreamOldale_Text_RouteSign:
	.string "DREAM OLDALE\n"
	.string "{UP_ARROW} ROUTE 103$"

DreamOldale_Text_TooMuchDebris:
	.string "There's too much debris in the way.$"
