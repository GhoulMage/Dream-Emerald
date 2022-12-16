DreamPetalburg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, DreamPetalburg_OnTransition
	.byte 0

DreamPetalburg_OnTransition::
	goto_if_set FLAG_NINJA_BOY1, DreamPetalburg_DoNothing
	setninjaflags FLAG_NINJA_BOY1
DreamPetalburg_DoNothing::
	end

DreamPetalburg_EventScript_RouteSign::
	msgbox DreamPetalburg_Text_RouteSign, MSGBOX_SIGN
	end

DreamPetalburg_EventScript_Sign1::
	msgbox DreamPetalburg_Text_Sign1, MSGBOX_SIGN
	end

DreamPetalburg_EventScript_Sign2::
	msgbox DreamPetalburg_Text_Sign2, MSGBOX_SIGN
	end

DreamPetalburg_EventScript_Item1::
	finditem ITEM_TM51
	end

DreamPetalburg_EventScript_Item2::
	finditem ITEM_DAWN_STONE
	end

DreamPetalburg_EventScript_Item3::
	finditem ITEM_TM72
	end

DreamPetalburg_EventScript_Sailor::
	locktarget
	faceplayer
	msgbox DreamPetalburg_Text_Sailor, MSGBOX_DEFAULT
	release
	end

DreamPetalburg_EventScript_CaveLocked::
	locktarget
	goto_if_set FLAG_DREAM_PETALBURG_DEBRIS, DreamPetalburg_EventScript_EnterCave
	msgbox UndergroundTunnels_Text_TooMuchDebris, MSGBOX_SIGN
	release
	end

DreamPetalburg_EventScript_EnterCave::
	msgbox UndergroundTunnels_Text_EnterCave, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, DreamPetalburg_EventScript_WarpToUndergroundTunnel
	closemessage
	release
	end

DreamPetalburg_EventScript_WarpToUndergroundTunnel::
	setescapewarp MAP_DREAM_PETALBURG, 16, 43
	warpholeto MAP_DREAM_PETALBURG, 16, 43
	end

DreamPetalburg_EventScript_Mike::
	trainerbattle_single TRAINER_MIKE_3, DreamPetalburg_Text_MikeIntro, DreamPetalburg_Text_MikeDefeated
	msgbox DreamPetalburg_Text_MikePostBattle, MSGBOX_DEFAULT
	release
	end

DreamPetalburg_EventScript_Julie::
	trainerbattle_single TRAINER_JULIE_2, DreamPetalburg_Text_JulieIntro, DreamPetalburg_Text_JulieDefeated
	msgbox JuliePostBattle, MSGBOX_DEFAULT
	release
	end

DreamPetalburg_EventScript_Charles::
	trainerbattle_single TRAINER_CHARLES, DreamPetalburg_Text_CharlesIntro, DreamPetalburg_Text_CharlesDefeated
	msgbox DreamPetalburg_Text_CharlesPostBattle, MSGBOX_DEFAULT
	release
	end

DreamPetalburg_EventScript_Jacob::
	trainerbattle_single TRAINER_JACOB_2, DreamPetalburg_Text_JacobIntro, DreamPetalburg_Text_JacobDefeated
	msgbox DreamPetalburg_Text_JacobPostBattle, MSGBOX_DEFAULT
	release
	end

DreamPetalburg_EventScript_Clementine::
	trainerbattle_single TRAINER_CLEMENTINE, DreamPetalburg_Text_ClementineIntro, DreamPetalburg_Text_ClementineDefeated
	msgbox DreamPetalburg_Text_ClementinePostBattle, MSGBOX_DEFAULT
	release
	end

DreamPetalburg_EventScript_Stacy::
	trainerbattle_single TRAINER_STACY, DreamPetalburg_Text_StacyIntro, DreamPetalburg_Text_StacyDefeated
	msgbox DreamPetalburg_Text_StacyPostBattle, MSGBOX_DEFAULT
	release
	end

DreamPetalburg_EventScript_Stephanie::
	trainerbattle_single TRAINER_STEPHANIE, DreamPetalburg_Text_StephanieIntro, DreamPetalburg_Text_StephanieDefeated
	msgbox DreamPetalburg_Text_StephaniePostBattle, MSGBOX_DEFAULT
	release
	end

DreamPetalburg_Text_StephanieIntro:
	.string "I AM STEPHANIE, Painter Of The Seas.\n"
	.string "Inspire me.$"

DreamPetalburg_Text_StephanieDefeated:
	.string "YOUR HELP, is appreciated.$"

DreamPetalburg_Text_StephaniePostBattle:
	.string "I AM GREATLY INSPIRED,\n"
	.string "come back here in a while.$"

DreamPetalburg_Text_StacyIntro:
	.string "Every month in summer I come to\n"
	.string "swim here for some days. Guess why.$"

DreamPetalburg_Text_StacyDefeated:
	.string "Yeah.$"

DreamPetalburg_Text_StacyPostBattle:
	.string "Do not harass me, go away.$"

DreamPetalburg_Text_ClementineIntro:
	.string "Why are these rocks always\n"
	.string "conveniently at the end of routes?$"

DreamPetalburg_Text_ClementineDefeated:
	.string "There must be a conspiracy.$"

DreamPetalburg_Text_ClementinePostBattle:
	.string "Do you think I can slip in between\n"
	.string "these rocks?$"

DreamPetalburg_Text_JacobIntro:
	.string "There's nothing like the great\n"
	.string "smell of the sea!$"

DreamPetalburg_Text_JacobDefeated:
	.string "Smells a bit fishy.$"

DreamPetalburg_Text_JacobPostBattle:
	.string "Do you know why SOUND POKéMON are\n"
	.string "weak to water?\l"
	.string "Because they drown in it! HA HA HA!$"

DreamPetalburg_Text_JulieIntro:
	.string "This is the best place to\n"
	.string "train near home!$"

DreamPetalburg_Text_JulieDefeated:
	.string "I need more training.$"

JuliePostBattle:
	.string "There's a rare bird POKéMON in\n"
	.string "the trees but I can never reach it.$"

DreamPetalburg_Text_CharlesIntro:
	.string "I am watching you very\n"
	.string "carefully!$"

DreamPetalburg_Text_CharlesDefeated:
	.string "Sorry my glasses fell\n"
	.string "to the ground.$"

DreamPetalburg_Text_CharlesPostBattle:
	.string "I am a bit clumsy sometimes.$"

DreamPetalburg_Text_MikeIntro:
	.string "I battle everyone who comes here!$"

DreamPetalburg_Text_MikeDefeated:
	.string "Wow, I don't usually lose.$"

DreamPetalburg_Text_MikePostBattle:
	.string "My bug senses tell me you're\n"
	.string "special, for real.$"

DreamPetalburg_Text_Sailor:
	.string "I came all the way from Sinnoh\n"
	.string "to see the rare POKéMON here.\p"
	.string "They are rare alright, but\n"
	.string "the price is quite high.$"

DreamPetalburg_Text_Sign1:
	.string "Many POKéMON climb up trees to\n"
	.string "hide and live there.\p"
	.string "Some trainers hit the trees to\n"
	.string "bring POKéMON down and catch them.$"

DreamPetalburg_Text_Sign2:
	.string "FISHERMAN's DREAM\p"
	.string "Come and get the fish of your dreams!$"

DreamPetalburg_Text_RouteSign:
	.string "DREAM PETALBURG\n"
	.string "{UP_ARROW} ROUTE 102$"
