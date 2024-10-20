DreamPetalburg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, DreamPetalburg_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, DreamPetalburg_OnFrameTable
	.byte 0

DreamPetalburg_OnTransition::
	setflag FLAG_VISITED_DREAM_PETALBURG
	goto_if_set FLAG_NINJA_BOY1, DreamPetalburg_DoNothing
	setninjaflags FLAG_NINJA_BOY1
DreamPetalburg_DoNothing::
	end

DreamPetalburg_OnFrameTable::
	map_script_2 VAR_FISHERMANS_DREAM_STATE, 1, DreamPetalburg_BeginFishing
	map_script_2 VAR_FISHERMANS_DREAM_STATE, 3, DreamPetalburg_KeepFishing
	.2byte 0

DreamPetalburg_FishermansDreamLoop::
	goto_if_eq VAR_FISHERMANS_DREAM_STATE, 1, DreamPetalburg_BeginFishing
	goto_if_eq VAR_FISHERMANS_DREAM_STATE, 3, DreamPetalburg_KeepFishing
	end

DreamPetalburg_KeepFishing::
	locktarget
	switch VAR_FISHERMANS_DREAM_TICKETS
	case 0, DreamPetalburg_NoMoreTickets
	msgbox DreamPetalburg_Text_KeepFishing, MSGBOX_YESNO
	switch VAR_RESULT
	case YES, DreamPetalburg_FishStartle
	case NO, DreamPetalburg_EndFishing
	end

DreamPetalburg_NoMoreTickets::
	playse SE_DING_DONG
	msgbox DreamPetalburg_Text_NoMoreTickets, MSGBOX_DEFAULT
DreamPetalburg_EndFishing::
	closemessage
	locktarget
	setvar VAR_FISHERMANS_DREAM_STATE, 4
	applymovement OBJ_EVENT_ID_PLAYER, DreamPetalburg_Movement_MoveBack
	waitmovement OBJ_EVENT_ID_PLAYER
	warp MAP_DREAM_PETALBURG_FISHERMAN_DREAM, 2
	end

DreamPetalburg_BeginFishing::
	locktarget
	setvar VAR_FISHERMANS_DREAM_STATE, 2
	applymovement OBJ_EVENT_ID_PLAYER, DreamPetalburg_Movement_MoveToFishing
	waitmovement OBJ_EVENT_ID_PLAYER
	msgbox DreamPetalburg_Text_NoFish, MSGBOX_DEFAULT
DreamPetalburg_FishStartle::
	applymovement OBJ_EVENT_ID_PLAYER, DreamPetalburg_Movement_Startled
	waitmovement OBJ_EVENT_ID_PLAYER
	msgbox DreamPetalburg_Text_Startled, MSGBOX_DEFAULT
	closemessage
	setvar VAR_FISHERMANS_DREAM_STATE, 3
	subvar VAR_FISHERMANS_DREAM_TICKETS, 1
	setvar VAR_FISHERMANS_DREAM_TICKETS, 0
	special FishermansDreamEncounter
	end

DreamPetalburg_EventScript_DreamSign1::
	msgbox DreamPetalburg_Text_DreamSign1, MSGBOX_SIGN
	end

DreamPetalburg_EventScript_DreamSign2::
	msgbox DreamPetalburg_Text_DreamSign2, MSGBOX_SIGN
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
	applymovement VAR_LAST_TALKED, Common_Movement_FaceRight
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
	trainerbattle_single TRAINER_STEPHANIE, DreamPetalburg_Text_StephanieIntro, DreamPetalburg_Text_StephanieDefeated, DreamPetalburg_EventScript_Stephanie
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

DreamPetalburg_Text_DreamSign1:
	.string "DREAM PETALBURG\n"
	.string "“Wavering nature connects to the beach.”\l"
	.string "{UP_ARROW} ROUTE 102$"

DreamPetalburg_Text_DreamSign2:
	.string "DREAM PETALBURG\n"
	.string "“Wavering nature connects to the beach.”\l"
	.string "{UP_ARROW} PETALBURG CITY$"

DreamPetalburg_Text_NoMoreTickets::
	.string "You don't have more tickets,\n"
	.string "please, go back in.$"

DreamPetalburg_Text_KeepFishing::
	.string "Do you want to keep fishing?$"

DreamPetalburg_Text_NoFish:
	.string "You don't see any fish…$"

DreamPetalburg_Text_Startled:
	.string "You were startled by a rare POKéMON!$"

DreamPetalburg_Movement_Startled:
	jump_in_place_down
	delay_8
	step_end

DreamPetalburg_Movement_MoveToFishing:
	delay_8
	walk_left
	walk_down
	step_end

DreamPetalburg_Movement_MoveBack:
	walk_up
	walk_right
	walk_up
	step_end
