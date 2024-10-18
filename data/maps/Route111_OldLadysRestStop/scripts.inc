Route111_OldLadysRestStop_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route111_OldLadysRestStop_OnTransition
	.byte 0

Route111_OldLadysRestStop_OnTransition:
	setflag FLAG_LANDMARK_OLD_LADY_REST_SHOP
	end

Route111_OldLadysRestStop_EventScript_OldLady::
	locktarget
	faceplayer
	msgbox Route111_OldLadysRestStop_Text_RestUpHere, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route111_OldLadysRestStop_EventScript_Rest
	goto_if_eq VAR_RESULT, NO, Route111_OldLadysRestStop_EventScript_DeclineRest
	end

Route111_OldLadysRestStop_EventScript_Rest::
	msgbox Route111_OldLadysRestStop_Text_TakeYourTimeRestUp, MSGBOX_DEFAULT
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	msgbox Route111_OldLadysRestStop_Text_StillTiredTakeAnotherRest, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route111_OldLadysRestStop_EventScript_Rest
	goto_if_eq VAR_RESULT, NO, Route111_OldLadysRestStop_EventScript_DeclineRest
	end

Route111_OldLadysRestStop_EventScript_DeclineRest::
	msgbox Route111_OldLadysRestStop_Text_DontNeedToBeShy, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route111_OldLadysRestStop_EventScript_Rest
	goto_if_eq VAR_RESULT, NO, Route111_OldLadysRestStop_EventScript_SoBeIt
	release
	end

Route111_OldLadysRestStop_EventScript_DeclineRest2::
	msgbox Route111_OldLadysRestStop_Text_RematchUnavailable, MSGBOX_DEFAULT
	release
	end

Route111_OldLadysRestStop_EventScript_SoBeIt::
	goto_if_set FLAG_DAILY_OLD_LADY, Route111_OldLadysRestStop_EventScript_DeclineRest2
	cleartrainerflag TRAINER_OLD_LADY_1
	cleartrainerflag TRAINER_OLD_LADY_2
	msgbox Route111_OldLadysRestStop_Text_CanBattleMeNow, MSGBOX_DEFAULT
	trainerbattle_double TRAINER_OLD_LADY_1, Route111_OldLadysRestStop_Text_OldLady_Intro, Route111_OldLadysRestStop_Text_OhDearDear, Route111_OldLadysRestStop_Text_NotEnoughPokemon, Route111_OldLadysRestStop_EventScript_Battle2
	end

Route111_OldLadysRestStop_EventScript_Battle2::
	locktarget
	msgbox Route111_OldLadysRestStop_Text_OldLady_Defeated1, MSGBOX_DEFAULT
	trainerbattle_double TRAINER_OLD_LADY_2, Route111_OldLadysRestStop_Text_OldLady_NotDoneYet, Route111_OldLadysRestStop_Text_OhDearDear, Route111_OldLadysRestStop_Text_NotEnoughPokemon, AfterBattle
	end

AfterBattle::
	setflag FLAG_DAILY_OLD_LADY
	msgbox Route111_OldLadysRestStop_Text_OldLady_Defeated2, MSGBOX_DEFAULT
	msgbox Route111_OldLadysRestStop_Text_RestAfterDefeat, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route111_OldLadysRestStop_EventScript_Rest
	goto_if_eq VAR_RESULT, NO, Route111_OldLadysRestStop_EventScript_DeclineRest2
	release
	end

Route111_OldLadysRestStop_Text_RestUpHere:
	.string "Oh, dear, dear.\n"
	.string "Aren't your POKéMON exhausted?\p"
	.string "If you'd like, rest up here.\n"
	.string "That's a fine idea! You should do that.$"

Route111_OldLadysRestStop_Text_TakeYourTimeRestUp:
	.string "That's right.\n"
	.string "Take your time and rest up!$"

Route111_OldLadysRestStop_Text_StillTiredTakeAnotherRest:
	.string "Oh, dear, dear.\n"
	.string "Are your POKéMON still tired?\p"
	.string "You should take another rest here.\n"
	.string "That's a fine idea. You should do that.$"

Route111_OldLadysRestStop_Text_DontNeedToBeShy:
	.string "Is that so?\n"
	.string "You don't need to be shy about it.$"

Route111_OldLadysRestStop_Text_CanBattleMeNow:
	.string "Oh dear, dear...\n"
	.string "If your POKéMON are so rested…$"

Route111_OldLadysRestStop_Text_OldLady_Intro:
	.string "That means you can battle me now.$"

Route111_OldLadysRestStop_Text_OhDearDear:
	.string "Oh, dear, dear!$"

Route111_OldLadysRestStop_Text_OldLady_Defeated1:
	.string "Your POKéMON are so strong.\n"
	.string "But now they must be exhausted…$"

Route111_OldLadysRestStop_Text_OldLady_NotDoneYet:
	.string "For sure.$"

Route111_OldLadysRestStop_Text_OldLady_Defeated2:
	.string "I cannot believe you defeated\n"
	.string "me twice!\n"

Route111_OldLadysRestStop_Text_RestAfterDefeat:
	.string "If you'd like, you can rest again.\n"
	.string "Don't worry, I have to rest myself.$"

Route111_OldLadysRestStop_Text_RematchUnavailable:
	.string "I hope you come by to rematch me\n"
	.string "tomorrow!$"

Route111_OldLadysRestStop_Text_NotEnoughPokemon:
	.string "Nevermind, you only have one.$"
