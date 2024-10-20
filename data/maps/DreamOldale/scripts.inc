DreamOldale_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, DreamOldale_OnTransition
	.byte 0

DreamOldale_OnTransition:
	setflag FLAG_VISITED_DREAM_OLDALE
	end

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
	locktarget
	goto_if_set FLAG_DREAM_OLDALE_DEBRIS, DreamOldale_EventScript_EnterCave
	msgbox UndergroundTunnels_Text_TooMuchDebris, MSGBOX_SIGN
	release
	end

DreamOldale_EventScript_EnterCave::
	msgbox UndergroundTunnels_Text_EnterCave, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, DreamOldale_EventScript_WarpToUndergroundTunnel
	closemessage
	release
	end

DreamOldale_EventScript_WarpToUndergroundTunnel::
	setescapewarp MAP_DREAM_OLDALE, 31, 19
	warpholeto MAP_OLDALE_TOWN, 10, 9
	end

DreamOldale_EventScript_LittleGirl::
	locktarget
	faceplayer
	msgbox DreamOldale_Text_LittleGirl, MSGBOX_NPC
	release
	end

DreamOldale_EventScript_BigSis::
	locktarget
	faceplayer
	msgbox DreamOldale_Text_BigSis1, MSGBOX_NPC
	release
	end

DreamOldale_EventScript_DevonEmployee::
	locktarget
	faceplayer
	msgbox DreamOldale_Text_DevonEmployee, MSGBOX_NPC
	release
	end

DreamOldale_EventScript_Azumarill::
	locktarget
	faceplayer
	waitse
	playmoncry SPECIES_AZUMARILL, CRY_MODE_NORMAL
	msgbox DreamOldale_Text_Azumarill, MSGBOX_DEFAULT
	waitmoncry
	release
	end

DreamOldale_Text_DevonEmployee:
	.string "Did you know? At Devon we\n"
	.string "created a device to explore\l"
	.string "the deep caves underground the region.\p"
	.string "We are still finishing it.$"

DreamOldale_Text_DevonEmployeeFinished:
	.string "Did you know? At Devon we\n"
	.string "created a device to explore\l"
	.string "the deep caves underground the region.\p"
	.string "It is finished!.$"

DreamOldale_Text_DevonEmployeeHas:
	.string "Did you know? At Devon we\n"
	.string "created a device to…\l"
	.string "Oh you have it!$"

DreamOldale_Text_LittleGirl:
	.string "That Azumarill my sis has\n"
	.string "was an Azurill sometime ago.\p"
	.string "I was the one who found it!$"

DreamOldale_Text_BigSis1:
	.string "My sister likes to play in.\n"
	.string "the tall grass.\p"
	.string "But sometimes a POKéMON appears\n"
	.string "and I have to fight it!$"

DreamOldale_Text_Sign1:
	.string "You can check your POKéMON's\n"
	.string "strength by pressing A on the\l"
	.string "summary view in your party.$"

DreamOldale_Text_RouteSign:
	.string "DREAM OLDALE\n"
	.string "{UP_ARROW} ROUTE 103$"

DreamOldale_Text_Azumarill:
	.string "AZUMARILL: Zumaririll!$"
