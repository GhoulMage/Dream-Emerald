.set LOCALID_GRUNTS_1, 8
.set LOCALID_GRUNTS_2, 9
.set LOCALID_CHILL_GRUNT, 13
.set LOCALID_ANNA, 11
.set LOCALID_MARIA, 12

NewMauville_LowerFloor1_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, NewMauville_LowerFlor1_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, NewMauville_LowerFlor1_OnTransition
	.byte 0

NewMauville_LowerFlor1_OnResume:
	call_if_eq VAR_TEMP_1, 1, NewMauville_LowerFlor1_EventScript_SetBarrierStateBlueButton
	call_if_eq VAR_TEMP_2, 1, NewMauville_LowerFlor1_EventScript_SetBarrierStateGreenButton
	end

NewMauville_LowerFlor1_OnTransition::
	setweather WEATHER_TOXIC
	call_if_eq VAR_NEW_MAUVILLE_STATE, 6, NewMauville_LowerFlor1_EventScript_SetGeneratorOffMetatiles
	call_if_eq VAR_NEW_MAUVILLE_STATE, 7, NewMauville_LowerFlor1_EventScript_SetGeneratorOffMetatiles
	call_if_eq VAR_NEW_MAUVILLE_STATE, 8, NewMauville_LowerFlor1_EventScript_SetGeneratorOffMetatiles
	end

NewMauville_LowerFloor1_EventScript_Call1::
	lockall
	pokenavcall NewMauville_Text_CrazyCall1
	waitmessage
	setvar VAR_NEW_MAUVILLE_STATE, 3
	releaseall
	end

NewMauville_LowerFloor1_EventScript_Call2::
	lockall
	pokenavcall NewMauville_Text_CrazyCall2
	waitmessage
	setvar VAR_NEW_MAUVILLE_STATE, 4
	releaseall
	end

NewMauville_LowerFloor1_EventScript_Call3::
	lockall
	pokenavcall NewMauville_Text_CrazyCall3
	waitmessage
	setvar VAR_NEW_MAUVILLE_STATE, 5
	releaseall
	end

NewMauville_Text_CrazyCall1:
	.string "… … … … … …\n"
	.string "The crazy scientist is calling…\p"
	.string "Crazy Scientist: Okay so now…\n"
	.string "Uh oh, a POKéMON is coming…\l"
	.string "Don't move! I'll call your right back!\p"
	.string "… … … … … …\n"
	.string "… … … … … Click!\p"
	.string "Better get going.$"

NewMauville_Text_CrazyCall2:
	.string "… … … … … …\n"
	.string "The crazy scientist is calling…\p"
	.string "Crazy Scientist: Sorry about that,\n"
	.string "what? You moved?\p"
	.string "Against all odds you managed to\n"
	.string "fight through waves of POKéMON\l"
	.string "and TRAINERS?\p"
	.string "Even through this thick\n"
	.string "and poisonous mist?\p"
	.string "Oh sorry, I got carried away.\n"
	.string "But yeah, beware of the\l"
	.string "TOXIC WEATHER.\p"
	.string "Specially if your POKéMONs have\n"
	.string "a status effect!\p"
	.string "Though I don't know what's with\n"
	.string "the ELECTRIC TERRAIN.\p"
	.string "Maybe the Generators are leaking\n"
	.string "electric power through the floor?\p"
	.string "Anyways, once you go deeper,\n"
	.string "do call me again.\p"
	.string "… … … … … …\n"
	.string "… … … … … Click!$"

NewMauville_Text_CrazyCall3:
	.string "Calling the Crazy Scientist…\n"
	.string "… … … … … …\p"
	.string "Crazy Scientist: Hello? Who's this?\n"
	.string "{PLAYER}? I don't know no {PLAYER}!\l"
	.string "Oh… the kid down there…\p"
	.string "Sorry I get a lot of junk calls.\p"
	.string "You have to find the active\n"
	.string "generator down there and disable it.\p"
	.string "It'll shoot out a piece of metal,\n"
	.string "be careful about that.\p"
	.string "Bring that piece up here and I'll\n"
	.string "fix this in no time!\p"
	.string "Then we'll be able to disable it\n"
	.string "without any EXPLOSION.\p"
	.string "Don't worry, it's only a 1% chance\n"
	.string "the one down there explodes.\p"
	.string "… … … … … …\l"
	.string "… … … … … Click!\p"
	.string "{PLAYER}: …$"

NewMauville_LowerFlor1_EventScript_GenButton::
	lockall
	waitse
	msgbox NewMauville_LowerFlor1_Text_SteppedOnSwitchGeneratorStopped, MSGBOX_DEFAULT
	closemessage
	setwildbattle SPECIES_ROTOM, 55, ITEM_SONIC_PLATE
	playmoncry SPECIES_ROTOM, CRY_MODE_ENCOUNTER
	delay 30
	waitmoncry
	dowildbattle
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, NewMauville_LowerFlor1_EventScript_AfterBattle
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, NewMauville_LowerFlor1_EventScript_AfterBattleRan
	releaseall
	end

NewMauville_LowerFlor1_EventScript_AfterBattle::
	lockall
	call NewMauville_LowerFlor1_EventScript_SetGeneratorOffMetatiles
	delay 20
	msgbox NewMauville_LowerFlor1_Text_GeneratorStopped, MSGBOX_DEFAULT
	setvar VAR_NEW_MAUVILLE_STATE, 6
	setflag FLAG_NEW_MAUVILLE_MAGMA
	releaseall
	end

NewMauville_LowerFlor1_EventScript_AfterBattleRan::
	lockall
	msgbox NewMauville_LowerFlor1_Text_RotomRan, MSGBOX_DEFAULT
	call NewMauville_LowerFlor1_EventScript_SetGeneratorOffMetatiles
	delay 20
	msgbox NewMauville_LowerFlor1_Text_GeneratorStopped, MSGBOX_DEFAULT
	setvar VAR_NEW_MAUVILLE_STATE, 6
	setflag FLAG_NEW_MAUVILLE_MAGMA
	releaseall
	end

NewMauville_LowerFlor1_EventScript_SetGeneratorOffMetatiles::
	setmetatile 52, 7, METATILE_BikeShop_Button_Pressed, FALSE
	setmetatile 49, 2, METATILE_BikeShop_Generator_Off_Tile0, TRUE
	setmetatile 50, 2, METATILE_BikeShop_Generator_Off_Tile1, TRUE
	setmetatile 51, 2, METATILE_BikeShop_Generator_Off_Tile2, TRUE
	setmetatile 52, 2, METATILE_BikeShop_Generator_Off_Tile3, TRUE
	setmetatile 49, 3, METATILE_BikeShop_Generator_Off_Tile4, TRUE
	setmetatile 50, 3, METATILE_BikeShop_Generator_Off_Tile5, TRUE
	setmetatile 51, 3, METATILE_BikeShop_Generator_Off_Tile6, TRUE
	setmetatile 52, 3, METATILE_BikeShop_Generator_Off_Tile7, TRUE
	special DrawWholeMapView
	return

NewMauville_LowerFlor1_Text_SteppedOnSwitchGeneratorStopped:
	.string "{PLAYER} stepped on the switch.\p"
	.string "Click…\p"
	.string "… … … … … … … …\n"
	.string "… … … … … … … !\p"
	.string "A wild POKéMON threw something!\p"
	.string "The wild POKéMON attacked!$"

NewMauville_LowerFlor1_Text_RotomRan:
	.string "The ROTOM ran away…$"

NewMauville_LowerFlor1_Text_GeneratorStopped:
	.string "… … … … … … … …\n"
	.string "The generator appears to have\l"
	.string "stopped…\p"
	.string "You grabbed the Generator Part.\p"
	.string "… STOMP … STOMP … \n"
	.string "There's loud steps coming from\l"
	.string "the floor above.$"

NewMauville_LowerFlor1_EventScript_BlueButton::
	lockall
	setvar VAR_TEMP_1, 1
	setvar VAR_TEMP_2, 0
	playse SE_PIN
	call NewMauville_LowerFlor1_EventScript_SetBarrierStateBlueButton
	special DrawWholeMapView
	releaseall
	end

NewMauville_LowerFlor1_EventScript_GreenButton::
	lockall
	setvar VAR_TEMP_1, 0
	setvar VAR_TEMP_2, 1
	playse SE_PIN
	call NewMauville_LowerFlor1_EventScript_SetBarrierStateGreenButton
	special DrawWholeMapView
	releaseall
	end

NewMauville_LowerFlor1_EventScript_SetBarrierStateBlueButton::
	setmetatile 36, 6, METATILE_BikeShop_Barrier_Hidden_Top, TRUE
	setmetatile 36, 7, METATILE_BikeShop_Barrier_Hidden_Bottom, TRUE
	setmetatile 36, 8, METATILE_BikeShop_Floor_Shadow_Top, FALSE
	setmetatile 36, 9, METATILE_BikeShop_Wall_Edge_Top, FALSE
	
	setmetatile 11, 32, METATILE_BikeShop_Barrier_Hidden_Top, TRUE
	setmetatile 11, 33, METATILE_BikeShop_Barrier_Hidden_Bottom, TRUE
	setmetatile 11, 34, METATILE_BikeShop_Floor_Shadow_Top, FALSE
	setmetatile 11, 35, METATILE_BikeShop_Wall_Edge_Top, FALSE

	setmetatile 54, 25, METATILE_BikeShop_Barrier_Hidden_Top, TRUE
	setmetatile 54, 26, METATILE_BikeShop_Barrier_Hidden_Bottom, TRUE
	setmetatile 54, 27, METATILE_BikeShop_Floor_Shadow_Top, FALSE
	setmetatile 54, 28, METATILE_BikeShop_Wall_Edge_Top, FALSE

	setmetatile 35, 31, METATILE_BikeShop_Barrier_Green_Top, TRUE
	setmetatile 35, 32, METATILE_BikeShop_Barrier_Green_TopMid, TRUE
	setmetatile 35, 33, METATILE_BikeShop_Barrier_Green_BottomMid, TRUE
	setmetatile 35, 34, METATILE_BikeShop_Barrier_Green_Bottom, TRUE

	setmetatile 16, 1, METATILE_BikeShop_Barrier_Green_Top, TRUE
	setmetatile 16, 2, METATILE_BikeShop_Barrier_Green_TopMid, TRUE
	setmetatile 16, 3, METATILE_BikeShop_Barrier_Green_BottomMid, TRUE
	setmetatile 16, 4, METATILE_BikeShop_Barrier_Green_Bottom, TRUE
	
	setmetatile 14, 11, METATILE_BikeShop_Barrier_Green_Top, TRUE
	setmetatile 14, 12, METATILE_BikeShop_Barrier_Green_TopMid, TRUE
	setmetatile 14, 13, METATILE_BikeShop_Barrier_Green_BottomMid, TRUE
	setmetatile 14, 14, METATILE_BikeShop_Barrier_Green_Bottom, TRUE

	setmetatile 21, 6, METATILE_BikeShop_Button_Pressed, FALSE
	setmetatile 4, 34, METATILE_BikeShop_Button_Pressed, FALSE
	setmetatile 46, 25, METATILE_BikeShop_Button_Pressed, FALSE
	setmetatile 22, 36, METATILE_BikeShop_Button_Pressed, FALSE
	
	setmetatile 2, 6, METATILE_BikeShop_Button_Green, FALSE
	setmetatile 25, 18, METATILE_BikeShop_Button_Green, FALSE
	setmetatile 21, 36, METATILE_BikeShop_Button_Green, FALSE
	setmetatile 4, 15, METATILE_BikeShop_Button_Green, FALSE
	return

NewMauville_LowerFlor1_EventScript_SetBarrierStateGreenButton::
	setmetatile 36, 6, METATILE_BikeShop_Barrier_Blue_Top, TRUE
	setmetatile 36, 7, METATILE_BikeShop_Barrier_Blue_TopMid, TRUE
	setmetatile 36, 8, METATILE_BikeShop_Barrier_Blue_BottomMid, TRUE
	setmetatile 36, 9, METATILE_BikeShop_Barrier_Blue_Bottom, TRUE

	setmetatile 11, 32, METATILE_BikeShop_Barrier_Blue_Top, TRUE
	setmetatile 11, 33, METATILE_BikeShop_Barrier_Blue_TopMid, TRUE
	setmetatile 11, 34, METATILE_BikeShop_Barrier_Blue_BottomMid, TRUE
	setmetatile 11, 35, METATILE_BikeShop_Barrier_Blue_Bottom, TRUE

	setmetatile 54, 25, METATILE_BikeShop_Barrier_Blue_Top, TRUE
	setmetatile 54, 26, METATILE_BikeShop_Barrier_Blue_TopMid, TRUE
	setmetatile 54, 27, METATILE_BikeShop_Barrier_Blue_BottomMid, TRUE
	setmetatile 54, 28, METATILE_BikeShop_Barrier_Blue_Bottom, TRUE

	setmetatile 35, 31, METATILE_BikeShop_Barrier_Hidden_Top, TRUE
	setmetatile 35, 32, METATILE_BikeShop_Barrier_Hidden_Bottom, TRUE
	setmetatile 35, 33, METATILE_BikeShop_Floor_Shadow_Top, FALSE
	setmetatile 35, 34, METATILE_BikeShop_Wall_Edge_Top, FALSE

	setmetatile 16, 1, METATILE_BikeShop_Barrier_Hidden_Top, TRUE
	setmetatile 16, 2, METATILE_BikeShop_Barrier_Hidden_Bottom, TRUE
	setmetatile 16, 3, METATILE_BikeShop_Floor_Shadow_Top, FALSE
	setmetatile 16, 4, METATILE_BikeShop_Wall_Edge_Top, FALSE
	
	setmetatile 14, 11, METATILE_BikeShop_Barrier_Hidden_Top, TRUE
	setmetatile 14, 12, METATILE_BikeShop_Barrier_Hidden_Bottom, TRUE
	setmetatile 14, 13, METATILE_BikeShop_Floor_Shadow_Top, FALSE
	setmetatile 14, 14, METATILE_BikeShop_Wall_Edge_Top, FALSE
	
	setmetatile 21, 6, METATILE_BikeShop_Button_Blue, FALSE
	setmetatile 4, 34, METATILE_BikeShop_Button_Blue, FALSE
	setmetatile 46, 25, METATILE_BikeShop_Button_Blue, FALSE
	setmetatile 22, 36, METATILE_BikeShop_Button_Blue, FALSE

	setmetatile 2, 6, METATILE_BikeShop_Button_Pressed, FALSE
	setmetatile 25, 18, METATILE_BikeShop_Button_Pressed, FALSE
	setmetatile 21, 36, METATILE_BikeShop_Button_Pressed, FALSE
	setmetatile 4, 15, METATILE_BikeShop_Button_Pressed, FALSE
	return

NewMauville_LowerFloor1_Warren::
	trainerbattle_single TRAINER_WARREN2, NewMauville_LowerFloor1_Text_WarrenIntro, NewMauville_LowerFloor1_Text_WarrenDefeated
	msgbox NewMauville_LowerFloor1_Text_WarrenPostBattle, MSGBOX_DEFAULT
	release
	end

NewMauville_LowerFloor1_Text_WarrenIntro:
    .string "Oh kid, there are weird\n"
    .string "people here, not like me.\p"
    .string "I need some distraction.$"

NewMauville_LowerFloor1_Text_WarrenDefeated:
    .string "Thank you.$"

NewMauville_LowerFloor1_Text_WarrenPostBattle:
    .string "I shall go no further.$"

NewMauville_LowerFloor1_Omelia::
	trainerbattle_single TRAINER_OMELIA, NewMauville_LowerFloor1_Text_OmeliaIntro, NewMauville_LowerFloor1_Text_OmeliaDefeated
	msgbox NewMauville_LowerFloor1_Text_OmeliaPostBattle, MSGBOX_DEFAULT
	release
	end

NewMauville_LowerFloor1_Text_OmeliaIntro:
    .string "This place was abandoned in\n"
    .string "favour of a new energy system\l"
    .string "and everyone left in a hurry.\p"
    .string "Anyways, someone told me there's\n"
    .string "treasure down here, but these\l"
    .string "weirdos don't let me pass.\p"
    .string "If I win this battle give me\n"
    .string "everything you find!$"

NewMauville_LowerFloor1_Text_OmeliaDefeated:
    .string "Oh well, I guess I'll leave.$"

NewMauville_LowerFloor1_Text_OmeliaPostBattle:
    .string "This place sucks. I better go\n"
    .string "to the mysterious tower\l"
    .string "in the desert…$"

NewMauville_LowerFloor1_Jack::
	trainerbattle_single TRAINER_JACK2, NewMauville_LowerFloor1_Text_JackIntro, NewMauville_LowerFloor1_Text_JackDefeated
	msgbox NewMauville_LowerFloor1_Text_JackPostBattle, MSGBOX_DEFAULT
	release
	end

NewMauville_LowerFloor1_Text_JackIntro:
    .string "AAH! DON'T ATTACK ME!$"

NewMauville_LowerFloor1_Text_JackDefeated:
    .string "Wait, you're not-$"

NewMauville_LowerFloor1_Text_JackPostBattle:
    .string "Sorry, I'm so scared.\p"
    .string "When are these guys gonna\n"
    .string "leave? Mom is gonna worry…$"

NewMauville_LowerFloor1_Vivian::
	trainerbattle_single TRAINER_VIVIAN2, NewMauville_LowerFloor1_Text_VivianIntro, NewMauville_LowerFloor1_Text_VivianDefeated
	msgbox NewMauville_LowerFloor1_Text_VivianPostBattle, MSGBOX_DEFAULT
	release
	end

NewMauville_LowerFloor1_Text_VivianIntro:
    .string "I fended off some of these\n"
    .string "TEAM MAGMA freaks.\p"
    .string "…But this lady down there\n"
    .string "behind the window is giving\l"
    .string "me the creeps.$"

NewMauville_LowerFloor1_Text_VivianDefeated:
    .string "…Why did we battle again?$"

NewMauville_LowerFloor1_Text_VivianPostBattle:
    .string "Sorry, force of habit.$"

NewMauville_LowerFloor1_Sofia::
	trainerbattle_single TRAINER_SOFIA, NewMauville_LowerFloor1_Text_SofiaIntro, NewMauville_LowerFloor1_Text_SofiaDefeated
	msgbox NewMauville_LowerFloor1_Text_SofiaPostBattle, MSGBOX_DEFAULT
	release
	end

NewMauville_LowerFloor1_Text_SofiaIntro:
    .string "I AM SOFIA, Painter of The Grotesque.\n"
    .string "Endarken me.$"

NewMauville_LowerFloor1_Text_SofiaDefeated:
	.string "AMAZING, you have something.$"

NewMauville_LowerFloor1_Text_SofiaPostBattle:
	.string "I AM GREATLY INSPIRED,\n"
	.string "come down someday again.$"

NewMauville_LowerFloor1_Agustin::
	trainerbattle_single TRAINER_AGUSTIN, NewMauville_LowerFloor1_Text_AgustinIntro, NewMauville_LowerFloor1_Text_AgustinDefeated
	msgbox NewMauville_LowerFloor1_Text_AgustinPostBattle, MSGBOX_DEFAULT
	release
	end

NewMauville_LowerFloor1_Text_AgustinIntro:
    .string "Hey! Not here because I'm\n"
    .string "scared of TEAM MAGMA\l"
    .string "or anything!$"

NewMauville_LowerFloor1_Text_AgustinDefeated:
    .string "No, I'm serious. Those guys\n"
    .string "are chill if you leave them alone$"

NewMauville_LowerFloor1_Text_AgustinPostBattle:
	.string "Those guys are blocking the way\n"
	.string "out though.\p"
	.string "I hope they leave soon,\n"
    .string "I'm hungry.$"

NewMauville_LowerFloor1_Anna::
	trainerbattle_double TRAINER_ANA_MARY, NewMauville_LowerFloor1_Text_AnnaIntro, NewMauville_LowerFloor1_Text_AnnaMariaDefeated, NewMauville_LowerFloor1_Text_AnnaNotEnough, LookAtMaria
	trainerbattle_double TRAINER_ANA_MARY, Route121_Text_KateIntro, Route121_Text_KateDefeat, Route121_Text_KateNotEnoughMons
LookAtMaria::
	msgbox NewMauville_LowerFloor1_Text_AnnaPostBattle, MSGBOX_DEFAULT
    applymovement LOCALID_ANNA, Common_Movement_FaceRight
	release
	end

NewMauville_LowerFloor1_Maria::
	trainerbattle_double TRAINER_ANA_MARY, NewMauville_LowerFloor1_Text_MariaIntro, NewMauville_LowerFloor1_Text_AnnaMariaDefeated, NewMauville_LowerFloor1_Text_MariaNotEnough, LookAtAnna
LookAtAnna::
	msgbox NewMauville_LowerFloor1_Text_MariaPostBattle, MSGBOX_DEFAULT
    applymovement LOCALID_MARIA, Common_Movement_FaceLeft
	release
	end

NewMauville_LowerFloor1_Text_AnnaIntro::
    .string "Hey! Like, we're on a\n"
    .string "date, like, go away creep!$"

NewMauville_LowerFloor1_Text_MariaIntro::
    .string "Ew, who are you? Why\n"
    .string "are you talking to us? Ew.$"

NewMauville_LowerFloor1_Text_AnnaMariaDefeated::
    .string "Why did you even get near us?$"

 NewMauville_LowerFloor1_Text_AnnaNotEnough::
	.string "Like, your ONLY POKéMON,\n"
	.string "totally sucks.$"

 NewMauville_LowerFloor1_Text_MariaNotEnough::
	.string "Ew, you don't even have\n"
	.string "two POKéMON! Ew!$"

NewMauville_LowerFloor1_Text_AnnaPostBattle::
    .string "Can't you just, like, leave?$"

NewMauville_LowerFloor1_Text_MariaPostBattle::
    .string "Just go, don't touch me.$"

NewMauville_LowerFloor1_Grunt1::
	trainerbattle_single TRAINER_GRUNT_NEW_MAUVILLE_1, NewMauville_LowerFloor1_Text_Grunt1Intro, NewMauville_LowerFloor1_Text_Grunt1Defeated
	msgbox NewMauville_LowerFloor1_Text_Grunt1PostBattle, MSGBOX_DEFAULT
	release
	end

NewMauville_LowerFloor1_Grunt2::
	trainerbattle_single TRAINER_GRUNT_NEW_MAUVILLE_2, NewMauville_LowerFloor1_Text_Grunt2Intro, NewMauville_LowerFloor1_Text_Grunt2Defeated
	msgbox NewMauville_LowerFloor1_Text_Grunt2PostBattle, MSGBOX_DEFAULT
	release
	end

NewMauville_LowerFloor1_Grunt3::
	trainerbattle_single TRAINER_GRUNT_NEW_MAUVILLE_3, NewMauville_LowerFloor1_Text_Grunt3Intro, NewMauville_LowerFloor1_Text_Grunt3Defeated
	msgbox NewMauville_LowerFloor1_Text_Grunt3PostBattle, MSGBOX_DEFAULT
	release
	end

NewMauville_LowerFloor1_Grunt4::
	trainerbattle_single TRAINER_GRUNT_NEW_MAUVILLE_4, NewMauville_LowerFloor1_Text_Grunt4Intro, NewMauville_LowerFloor1_Text_Grunt4Defeated
	msgbox NewMauville_LowerFloor1_Text_Grunt4PostBattle, MSGBOX_DEFAULT
	release
	end

NewMauville_LowerFloor1_Grunt5::
	trainerbattle_single TRAINER_GRUNT_NEW_MAUVILLE_5, NewMauville_LowerFloor1_Text_Grunt5Intro, NewMauville_LowerFloor1_Text_Grunt5Defeated
	msgbox NewMauville_LowerFloor1_Text_Grunt5PostBattle, MSGBOX_DEFAULT
	release
	end

NewMauville_LowerFloor1_Grunt6::
	trainerbattle_single TRAINER_GRUNT_NEW_MAUVILLE_6, NewMauville_LowerFloor1_Text_Grunt6Intro, NewMauville_LowerFloor1_Text_Grunt6Defeated
	msgbox NewMauville_LowerFloor1_Text_Grunt6PostBattle, MSGBOX_DEFAULT
	release
	end

NewMauville_LowerFloor1_Text_Grunt1Intro::
    .string "Hey watch out! You're\n"
    .string "stepping on the stuff I found!$"

NewMauville_LowerFloor1_Text_Grunt1Defeated::
    .string "All the stuff here is so shiny.$"

NewMauville_LowerFloor1_Text_Grunt1PostBattle::
    .string "What? I don't care that you\n"
    .string "won. I want to stay here.$"

NewMauville_LowerFloor1_Text_Grunt2Intro::
    .string "This mist is making me feel\n"
    .string "like my stomach is gonna EXPLODE.$"

NewMauville_LowerFloor1_Text_Grunt2Defeated::
    .string "I'm glad this box was here…$"

NewMauville_LowerFloor1_Text_Grunt2PostBattle::
    .string "…Eugh… Look kid, don't tell anyone else$"

NewMauville_LowerFloor1_Text_Grunt3Intro::
    .string "I saw that…$"

NewMauville_LowerFloor1_Text_Grunt3Defeated::
    .string "…$"

NewMauville_LowerFloor1_Text_Grunt3PostBattle::
    .string "Look, I don't care.$"

NewMauville_LowerFloor1_Text_Grunt4Intro::
    .string "BOO! HA HA HA!\p"
    .string "You sure weren't expecting me!\p"
    .string "What?\n"
    .string "You saw me through the window?$"

NewMauville_LowerFloor1_Text_Grunt4Defeated::
    .string "I didn't see the window…$"

NewMauville_LowerFloor1_Text_Grunt4PostBattle::
    .string "You don't believe me?\n"
    .string "These don't even fit here, why\l"
    .string "are there windows down here?$"

NewMauville_LowerFloor1_Text_Grunt5Intro::
    .string "I've been staring into this\n"
    .string "man's face for an hour now.$"

NewMauville_LowerFloor1_Text_Grunt5Defeated::
    .string "I wanna out. Now.$"

NewMauville_LowerFloor1_Text_Grunt5PostBattle::
    .string "Please don't go. Boss is not\n"
    .string "gonna take long and I want to\l"
    .string "have an excuse to not look at him.$"

NewMauville_LowerFloor1_Text_Grunt6Intro::
    .string "I've been staring into this\n"
    .string "woman's face for an hour now.$"

NewMauville_LowerFloor1_Text_Grunt6Defeated::
    .string "I feel like she hates me.$"

NewMauville_LowerFloor1_Text_Grunt6PostBattle::
    .string "Sigh…$"

NewMauville_LowerFloor1_Grunts1::
	goto_if_set FLAG_NEW_MAUVILLE_MAGMA, NewMauville_LowerFloor1_DoNothing
	goto_if_defeated TRAINER_GRUNTS_NEW_MAUVILLE_1, NewMauville_LowerFloor1_Grunts1_PostBattle
	lockall
	setvar VAR_TEMP_4, 1
	applymovement LOCALID_GRUNTS_1, GruntExclamation
	waitmovement 0
	specialvar VAR_RESULT, GetPlayerYLocation
	call_if_eq VAR_RESULT, 14, NewMauville_LowerFloor1_MoveGrunts
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	msgbox NewMauville_LowerFloor1_Text_Grunts1Intro, MSGBOX_DEFAULT
	closemessage
	trainerbattle_two_trainers TRAINER_GRUNTS_NEW_MAUVILLE_1, NewMauville_LowerFloor1_Text_Grunts1Defeated, TRAINER_GRUNTS_NEW_MAUVILLE_2, NewMauville_LowerFloor1_Text_Grunts2Defeated
	releaseall
	end

NewMauville_LowerFloor1_Grunts1_PostBattle::
	setvar VAR_TEMP_4, 1
	msgbox NewMauville_LowerFloor1_Text_Grunts1PostBattle, MSGBOX_DEFAULT
	releaseall
	end

NewMauville_LowerFloor1_Grunts2::
	goto_if_set FLAG_NEW_MAUVILLE_MAGMA, NewMauville_LowerFloor1_DoNothing
	goto_if_defeated TRAINER_GRUNTS_NEW_MAUVILLE_2, NewMauville_LowerFloor1_Grunts2_PostBattle
	lockall
	setvar VAR_TEMP_4, 1
	applymovement LOCALID_GRUNTS_2, GruntExclamation
	waitmovement 0
	specialvar VAR_RESULT, GetPlayerYLocation
	call_if_eq VAR_RESULT, 14, NewMauville_LowerFloor1_MoveGrunts
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	msgbox NewMauville_LowerFloor1_Text_Grunts2Intro, MSGBOX_DEFAULT
	closemessage
	trainerbattle_two_trainers TRAINER_GRUNTS_NEW_MAUVILLE_2, NewMauville_LowerFloor1_Text_Grunts2Defeated, TRAINER_GRUNTS_NEW_MAUVILLE_1, NewMauville_LowerFloor1_Text_Grunts1Defeated
NewMauville_LowerFloor1_DoNothing::
	releaseall
	end

NewMauville_LowerFloor1_Grunts2_PostBattle::
	setvar VAR_TEMP_4, 1
	msgbox NewMauville_LowerFloor1_Text_Grunts2PostBattle, MSGBOX_DEFAULT
	releaseall
	end

NewMauville_LowerFloor1_MoveGrunts::
    applymovement LOCALID_GRUNTS_1, MoveGruntDown
    applymovement LOCALID_GRUNTS_2, MoveGruntDown
    waitmovement 0
	delay 10
	return

GruntExclamation::
	emote_exclamation_mark
	delay_16
	delay_16
	delay_16
	delay_16
	step_end

MoveGruntDown::
    walk_down
    step_end

NewMauville_LowerFloor1_Text_Grunts1Intro:
    .string "I don't know how you got this\n"
    .string "far, kid, but this ends now.$"

NewMauville_LowerFloor1_Text_Grunts2Intro:
    .string "Trying to sneak around, eh?\n"
    .string "You're not gonna go much further.$"

NewMauville_LowerFloor1_Text_Grunts1Defeated:
    .string "How could you defeat us?$"

NewMauville_LowerFloor1_Text_Grunts2Defeated:
    .string "You're annoying.$"

NewMauville_LowerFloor1_Text_GruntsFewPokemon:
	.string "You don't even have enough\n"
	.string "POKéMON, brat!$"

NewMauville_LowerFloor1_Text_Grunts1PostBattle:
    .string "…You shouldn't be playing here, kid.$"

NewMauville_LowerFloor1_Text_Grunts2PostBattle:
    .string "Sneak around all you want, but\n"
    .string "eventually you'll get hurt.$"

NewMauville_LowerFloor1_ChillGrunt::
    locktarget
    faceplayer
    goto_if_eq VAR_TEMP_3, 1, Chills
    msgbox NewMauville_LowerFloor1_Text_ChillGrunt, MSGBOX_DEFAULT
    closemessage
    setvar VAR_TEMP_3, 1
    applymovement LOCALID_CHILL_GRUNT, Common_Movement_FaceDown
    delay 90
    faceplayer
Chills::
    msgbox NewMauville_LowerFloor1_Text_ChillGrunt2, MSGBOX_DEFAULT
    closemessage
    applymovement LOCALID_CHILL_GRUNT, Common_Movement_FaceDown
    waitmovement LOCALID_CHILL_GRUNT
    release
    end

NewMauville_LowerFloor1_Text_ChillGrunt:
    .string "Oh no, I don't wanna battle.\n"
    .string "I am a bit sick of this fog,\l"
    .string "honestly.\p"
    .string "But…$"

NewMauville_LowerFloor1_Text_ChillGrunt2:
    .string "Are these bones of POKéMON that\n"
    .string "did not get to survive it…?$"

NewMauville_LowerFloor1_Courtney::
	trainerbattle_single TRAINER_COURTNEY_NEW_MAUVILLE, NewMauville_LowerFloor1_Text_CourtneyIntro, NewMauville_LowerFloor1_Text_CourtneyDefeated, NewMauville_LowerFloor1_CourtneyPostBattle
	msgbox NewMauville_LowerFloor1_Text_CourtneyPostBattle2, MSGBOX_DEFAULT
    setvar VAR_TEMP_A, 1
	release
	end

NewMauville_LowerFloor1_CourtneyPostBattle::
    msgbox NewMauville_LowerFloor1_Text_CourtneyPostBattle, MSGBOX_DEFAULT
    release
	end

NewMauville_LowerFloor1_Text_CourtneyIntro:
    .string "…\p"
    .string "Why are you here?$"

NewMauville_LowerFloor1_Text_CourtneyDefeated:
    .string "…Powerful.$"

NewMauville_LowerFloor1_Text_CourtneyPostBattle:
    .string "Are you AQUA?\p"
    .string "… … … …\p"
    .string "No?\p"
    .string "Huh.\p"
    .string "…\p"
    .string "…\p"
    .string "Ignore us.$"

NewMauville_LowerFloor1_Text_CourtneyPostBattle2:
    .string "…\p"
    .string "Ignore us.$"
