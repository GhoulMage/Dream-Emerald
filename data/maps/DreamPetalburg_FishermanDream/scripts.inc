.set LOCALID_OWNER, 4
.set LOCALID_AQUAGRUNT, 6
.set LOCALID_EMPLOYEE1, 1
.set LOCALID_EMPLOYEE2, 2
.set LOCALID_EMPLOYEE3, 3
.set LOCALID_EMPLOYEE4, 5

DreamPetalburg_FishermanDream_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FishermanDream_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, FishermanDream_OnFrame
	.byte 0

FishermanDream_OnTransition::
	goto_if_set FLAG_FISHERMANS_DREAM_GRUNT_DEFEATED, FishermanDream_EventScript_CleanFishermanDream
	return

FishermanDream_OnFrame::
	map_script_2 VAR_TEMP_0, 0, FishermanDream_EventScript_AquaGruntYell
	map_script_2 VAR_FISHERMANS_DREAM_STATE, 4, FishermanDream_EventScript_WalkBack
	.2byte 0

FishermanDream_EventScript_CleanFishermanDream::
	setobjectxyperm LOCALID_OWNER, 14, 2
	setobjectmovementtype LOCALID_OWNER, MOVEMENT_TYPE_FACE_RIGHT
	
	setobjectxyperm LOCALID_EMPLOYEE1, 5, 4
	setobjectmovementtype LOCALID_EMPLOYEE1, MOVEMENT_TYPE_LOOK_AROUND
	
	setobjectxyperm LOCALID_EMPLOYEE2, 1, 5
	setobjectmovementtype LOCALID_EMPLOYEE2, MOVEMENT_TYPE_FACE_DOWN_AND_RIGHT
	
	setobjectxyperm LOCALID_EMPLOYEE3, 9, 2
	setobjectmovementtype LOCALID_EMPLOYEE3, MOVEMENT_TYPE_LOOK_AROUND

	setobjectxyperm LOCALID_EMPLOYEE4, 11, 9
	setobjectmovementtype LOCALID_EMPLOYEE4, MOVEMENT_TYPE_WANDER_LEFT_AND_RIGHT
	end

FishermanDream_EventScript_AquaGruntYell::
	setvar VAR_TEMP_0, 1
	goto_if_set FLAG_FISHERMANS_DREAM_GRUNT_DEFEATED, FishermanDream_EventScript_DoNothing
	lockall
	setvar VAR_RESULT, 6
	special SetRandomResult
	switch VAR_RESULT
	case 0, FishermanDream_EventScript_AquaGruntYell0
	case 1, FishermanDream_EventScript_AquaGruntYell1
	case 2, FishermanDream_EventScript_AquaGruntYell2
	case 3, FishermanDream_EventScript_AquaGruntYell3
	case 4, FishermanDream_EventScript_AquaGruntYell4
	case 5, FishermanDream_EventScript_AquaGruntYell5
	releaseall
FishermanDream_EventScript_DoNothing::
	end

FishermanDream_EventScript_AquaGruntYell0::
	lockall
	msgbox FishermanDream_Text_AquaGruntYell0, MSGBOX_DEFAULT
	waitmessage
	releaseall
	end

FishermanDream_EventScript_AquaGruntYell1::
	lockall
	msgbox FishermanDream_Text_AquaGruntYell1, MSGBOX_DEFAULT
	waitmessage
	releaseall
	end

FishermanDream_EventScript_AquaGruntYell2::
	lockall
	msgbox FishermanDream_Text_AquaGruntYell2, MSGBOX_DEFAULT
	waitmessage
	releaseall
	end

FishermanDream_EventScript_AquaGruntYell3::
	lockall
	msgbox FishermanDream_Text_AquaGruntYell3, MSGBOX_DEFAULT
	waitmessage
	releaseall
	end

FishermanDream_EventScript_AquaGruntYell4::
	lockall
	msgbox FishermanDream_Text_AquaGruntYell4, MSGBOX_DEFAULT
	waitmessage
	releaseall
	end

FishermanDream_EventScript_AquaGruntYell5::
	lockall
	msgbox FishermanDream_Text_AquaGruntYell5, MSGBOX_DEFAULT
	waitmessage
	releaseall
	end

FishermanDream_EventScript_Owner_Rattled::
	locktarget
	switch VAR_TEMP_0
	case 2, FishermanDream_EventScript_OwnerWaiting
	case 3, FishermanDream_EVentScript_OwnerAfterBattle
	faceplayer
	goto_if_set FLAG_FISHERMANS_DREAM_GRUNT_DEFEATED, FishermanDream_EventScript_Owner
	msgbox FishermanDream_Text_Owner_Rattled, MSGBOX_DEFAULT
	goto_if_set FLAG_BADGE05_GET, FishermanDream_EventScript_Owner_Help
	msgbox FishermanDream_Text_Owner_Rude, MSGBOX_DEFAULT
	release
	end

FishermanDream_EVentScript_OwnerAfterBattle::
	msgbox FishermanDream_Text_Owner_Busy, MSGBOX_DEFAULT
	closemessage
	end

FishermanDream_EventScript_OwnerWaiting::
	lockall
	faceplayer
	msgbox FishermanDream_Text_Owner_Ready, MSGBOX_YESNO
	closemessage
	switch VAR_RESULT
	case YES, FishermanDream_EventScript_BattleStart
	msgbox FishermanDream_Text_Owner_BeQuick, MSGBOX_DEFAULT
	releaseall
	release
	end

FishermanDream_EventScript_BattleStart::
	lockall
	applymovement LOCALID_OWNER, FishermanDream_Movement_LookRight
	applymovement OBJ_EVENT_ID_PLAYER, FishermanDream_Movement_LookRight
	waitmovement LOCALID_OWNER
	delay 30
	applymovement LOCALID_EMPLOYEE2, FishermanDream_Movement_LookLeft
	applymovement LOCALID_AQUAGRUNT, Common_Movement_QuestionMark
	waitmovement LOCALID_EMPLOYEE2
	delay 60
	applymovement LOCALID_AQUAGRUNT, FishermanDream_Movement_GoUpThenLookDown
	applymovement LOCALID_EMPLOYEE2, FishermanDream_Movement_GoRightThenDownOnceAndLookUp
	waitmovement LOCALID_EMPLOYEE2
	applymovement LOCALID_AQUAGRUNT, FishermanDream_Movement_AquaGruntMovesToFight
	applymovement LOCALID_EMPLOYEE1, FishermanDream_Movement_LookDown
	applymovement LOCALID_EMPLOYEE3, FishermanDream_Movement_LookUp
	waitmovement LOCALID_AQUAGRUNT
	playbgm MUS_ENCOUNTER_AQUA, TRUE
	trainerbattle_single TRAINER_FISHERMAN_DREAM_AQUA_GRUNT, FishermanDream_Text_AquaGruntIntro, FishermanDream_Text_AquaGruntDefeated, FishermanDream_EventScript_BattleEnd
	end

FishermanDream_EventScript_BattleEnd::
	lockall
	applymovement LOCALID_OWNER, FishermanDream_Movement_LookDown
	applymovement LOCALID_AQUAGRUNT, FishermanDream_Movement_AquaGruntIrritated
	waitmovement LOCALID_AQUAGRUNT
	msgbox FishermanDream_Text_AquaGrunt_Irritated, MSGBOX_DEFAULT
	applymovement OBJ_EVENT_ID_PLAYER, FishermanDream_Movement_LeaveSpaceForAquaGrunt
	applymovement LOCALID_AQUAGRUNT, FishermanDream_Movement_AquaGruntLeaves
	applymovement LOCALID_EMPLOYEE1, FishermanDream_Movement_LookLeft
	applymovement LOCALID_EMPLOYEE2, FishermanDream_Movement_WalkUpLeft
	applymovement LOCALID_EMPLOYEE3, FishermanDream_Movement_LookLeft
	waitmovement LOCALID_AQUAGRUNT
	playse SE_EXIT
	removeobject LOCALID_AQUAGRUNT
	delay 20
	fadedefaultbgm
	applymovement LOCALID_OWNER, FishermanDream_Movement_GoDown
	waitmovement LOCALID_OWNER
	msgbox FishermanDream_Text_Owner_ThankYou, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_ITEM
	message FishermanDream_Text_ReceivedFreeTickets
	waitfanfare
	closemessage
	applymovement LOCALID_OWNER, FishermanDream_Movement_Owner_AfterBattle
	waitmovement LOCALID_OWNER
	setvar VAR_TEMP_0, 3
	setvar VAR_FISHERMANS_DREAM_TICKETS, 5
	release
	releaseall
	end

FishermanDream_EventScript_Owner::
	locktarget
	faceplayer
	msgbox FishermanDream_Text_Owner, MSGBOX_DEFAULT
	release
	end

FishermanDream_EventScript_Owner_Help::
	msgbox FishermanDream_Text_Owner_Help, MSGBOX_YESNO
	switch VAR_RESULT
	case YES, FishermanDream_EventScript_Owner_Help_YES
	case NO, FishermanDream_EventScript_Owner_Help_NO
	release
	end

FishermanDream_EventScript_Owner_Help_YES::
	msgbox FishermanDream_Text_Owner_Grateful, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_0, 2
	switch VAR_FACING
	case DIR_WEST, FishermanDream_EventScript_LetOwnerPassAndMove
	applymovement OBJ_EVENT_ID_PLAYER, FishermanDream_Movement_LookAtOwner
	applymovement LOCALID_OWNER, FishermanDream_Movement_OwnerHelp
	waitmovement 4
	release
	end

FishermanDream_EventScript_Owner_Help_NO::
	msgbox FishermanDream_Text_Owner_Pleading, MSGBOX_DEFAULT
	release
	end

FishermanDream_EventScript_LetOwnerPassAndMove::
	applymovement OBJ_EVENT_ID_PLAYER, FishermanDream_Movement_LetOwnerPass
	applymovement LOCALID_OWNER, FishermanDream_Movement_OwnerHelp
	waitmovement 4
	releaseall
	end

FishermanDream_EventScript_Employee1_Rattled::
	switch VAR_TEMP_0
	case 3, FishermanDream_EventScript_Employee1_AfterBattle
	goto_if_set FLAG_FISHERMANS_DREAM_GRUNT_DEFEATED, FishermanDream_EventScript_Employee1
	msgbox FishermanDream_Text_Employee1_Rattled, MSGBOX_SIGN
	end

FishermanDream_EventScript_Employee2_Rattled::
	switch VAR_TEMP_0
	case 3, FishermanDream_EventScript_Employee2_AfterBattle
	goto_if_set FLAG_FISHERMANS_DREAM_GRUNT_DEFEATED, FishermanDream_EventScript_Employee2
	msgbox FishermanDream_Text_Employee2_Rattled, MSGBOX_SIGN
	end

FishermanDream_EventScript_Employee3_Rattled::
	switch VAR_TEMP_0
	case 3, FishermanDream_EventScript_Employee3_AfterBattle
	goto_if_set FLAG_FISHERMANS_DREAM_GRUNT_DEFEATED, FishermanDream_EventScript_Employee3
	msgbox FishermanDream_Text_Employee3_Rattled, MSGBOX_SIGN
	end

FishermanDream_EventScript_Employee1::
	locktarget
	faceplayer
	msgbox FishermanDream_Text_Employee1, MSGBOX_DEFAULT
	releaseall
	end

FishermanDream_EventScript_Employee2::
	locktarget
	faceplayer
	msgbox FishermanDream_Text_Employee2, MSGBOX_DEFAULT
	releaseall
	end

FishermanDream_EventScript_Employee3::
	setvar VAR_LAST_TALKED, LOCALID_EMPLOYEE3
	locktarget
	applymovement LOCALID_EMPLOYEE3, FishermanDream_Movement_LookDown
	applymovement OBJ_EVENT_ID_PLAYER, FishermanDream_Movement_LookUp
	switch VAR_FISHERMANS_DREAM_TICKETS
	case 0, FishermanDream_EventScript_Employee3_NoTickets
	msgbox FishermanDream_Text_Employee3_BuyTickets, MSGBOX_YESNO
	switch VAR_RESULT
	case YES, FishermanDream_EventScript_StartFishing
	case NO, FishermanDream_EventScript_Employee3_Goodbye
FishermanDream_EventScript_StartFishing::
	msgbox FishermanDream_Text_Employee3_StartFishing, MSGBOX_DEFAULT
	closemessage
	specialvar VAR_RESULT, GetPlayerYLocation
	switch VAR_RESULT
	case 4, FishermanDream_EventScript_GoFishUpper
	case 5, FishermanDream_EventScript_GoFishHalf
	case 6, FishermanDream_EventScript_GoFishLower
	releaseall
	end

FishermanDream_EventScript_WalkBack::
	setvar VAR_LAST_TALKED, LOCALID_EMPLOYEE3
	locktarget
	applymovement LOCALID_EMPLOYEE3, FishermanDream_Movement_LookDown
	applymovement OBJ_EVENT_ID_PLAYER, FishermanDream_Movement_WalkBack
	waitmovement 0
	setvar VAR_FISHERMANS_DREAM_STATE, 0
	releaseall
	end

FishermanDream_EventScript_GoFishUpper::
	applymovement OBJ_EVENT_ID_PLAYER, FishermanDream_Movement_GoFishUpper
	waitmovement 0
	setvar VAR_FISHERMANS_DREAM_STATE, 1
	warp MAP_DREAM_PETALBURG, 4
	releaseall
	end

FishermanDream_EventScript_GoFishHalf::
	applymovement OBJ_EVENT_ID_PLAYER, FishermanDream_Movement_GoFishHalf
	waitmovement 0
	setvar VAR_FISHERMANS_DREAM_STATE, 1
	warp MAP_DREAM_PETALBURG, 4
	releaseall
	end

FishermanDream_EventScript_GoFishLower::
	applymovement OBJ_EVENT_ID_PLAYER, FishermanDream_Movement_GoFishLower
	waitmovement 0
	setvar VAR_FISHERMANS_DREAM_STATE, 1
	warp MAP_DREAM_PETALBURG, 4
	releaseall
	end

FishermanDream_EventScript_Employee3_NoTickets::
	showmoneybox 0, 0
	msgbox FishermanDream_Text_Employee3_NoTickets, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, FishermanDream_EventScript_Employee3_Goodbye
	checkmoney 2500
	goto_if_eq VAR_RESULT, 0, FishermanDream_EventScript_Employee3_NotEnoughMoney
	playse SE_SHOP
	updatemoneybox
	msgbox FishermanDream_Text_Employee3_ThankYou, MSGBOX_DEFAULT
	setvar VAR_FISHERMANS_DREAM_TICKETS, 4
	removemoney 2500
	hidemoneybox
	msgbox FishermanDream_Text_Employee3_UseTicket, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, FishermanDream_EventScript_Employee3_Goodbye
	goto FishermanDream_EventScript_StartFishing
	releaseall
	end

FishermanDream_EventScript_Employee3_NotEnoughMoney::
	msgbox FishermanDream_Text_Employee3_NotEnoughMoney, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, FishermanDream_Movement_WalkLeft
	waitmovement OBJ_EVENT_ID_PLAYER
	releaseall
	end

FishermanDream_EventScript_Employee3_Goodbye::
	msgbox FishermanDream_Text_Employee3_Goodbye, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, FishermanDream_Movement_WalkLeft
	waitmovement OBJ_EVENT_ID_PLAYER
	releaseall
	end

FishermanDream_EventScript_Employee1_AfterBattle::
	locktarget
	faceplayer
	msgbox FishermanDream_Text_Employee1_AfterBattle, MSGBOX_DEFAULT
	releaseall
	end

FishermanDream_EventScript_Employee2_AfterBattle::
	locktarget
	faceplayer
	msgbox FishermanDream_Text_Employee2_AfterBattle, MSGBOX_DEFAULT
	releaseall
	end

FishermanDream_EventScript_Employee3_AfterBattle::
	locktarget
	faceplayer
	msgbox FishermanDream_Text_Employee3_AfterBattle, MSGBOX_DEFAULT
	releaseall
	end

FishermanDream_EventScript_Sign1::
	goto_if_set FLAG_FISHERMANS_DREAM_GRUNT_DEFEATED, FishermanDream_EventScript_Sign2
	msgbox FishermanDream_Text_Sign1, MSGBOX_SIGN
	end

FishermanDream_EventScript_Sign2::
	msgbox FishermanDream_Text_Sign2, MSGBOX_SIGN
	releaseall
	end

FishermanDream_Text_AquaGrunt_Irritated:
	.string "Agh, whatever okay?\p"
	.string "You can all have these\n"
	.string "stupid POKéMON!\p"
	.string "I guess after so long\n"
	.string "boss is not gonna care...$"

FishermanDream_Text_AquaGruntIntro:
	.string "What is this? Are you gonna\n"
	.string "let me pass or not?\p"
	.string "Who are you?\p"
	.string "What? You will battle me\n"
	.string "for these POKéMON?\l"
	.string "Do you not know who I am?$"

FishermanDream_Text_AquaGruntDefeated:
	.string "WHO ARE YOU!?$"

FishermanDream_Text_AquaGruntYell0:
	.string "You cannot do this to me,\n"
	.string "LET ME OUT!!$"

FishermanDream_Text_AquaGruntYell1:
	.string "Once my boss notices I'm away,\n"
	.string "YOU'LL BE DONE FOR!!$"

FishermanDream_Text_AquaGruntYell2:
	.string "Can I go, pretty please?$"

FishermanDream_Text_AquaGruntYell3:
	.string "You all... worse than\n"
	.string "A MAGIKARP!!$"

FishermanDream_Text_AquaGruntYell4:
	.string "Look, I can give you one Milotic\n"
	.string "at most, leave me alone.$"

FishermanDream_Text_AquaGruntYell5:
	.string "“Ocean man, take me\n"
	.string "by the hand to the land,\l"
	.string "...that you understand...”$"

FishermanDream_Text_Sign2:
	.string "Some text is scratched...\p"
	.string "“Catch all the fish you want,\n"
	.string "until the time runs out!”\p"
	.string "There's some new text below.\p"
	.string "“Grab tickets! For each ticket,\n"
	.string "you could catch a rare fish POKéMON!”$"

FishermanDream_Text_Sign1:
	.string "“Catch all the fish you want,\n"
	.string "until the time runs out!”$"

FishermanDream_Text_Owner_Rattled:
	.string "This has never happened...\p"
	.string "This usual client was catching\n"
	.string "the likes of hundreds of POKéMON\l"
	.string "every time she came...\p"
	.string "So I finally changed the rules,\n"
	.string "and warned her about it.\p"
	.string "But she caught 250 POKéMON and\n"
	.string "wants to leave! As if!$"

FishermanDream_Text_Owner_Rude:
	.string "Would you help us..?\p"
	.string "Nevermind, you don't seem strong...\n"
	.string "I wish someone came to help...$"

FishermanDream_Text_Owner_Help:
	.string "Would you help us..?$"

FishermanDream_Text_Owner_Pleading:
	.string "Please... it's been two weeks...$"

FishermanDream_Text_Owner_Grateful:
	.string "Oh, thank you!\n"
	.string "I think you will need to\l"
	.string "battle her though...$"

FishermanDream_Text_Owner_ThankYou:
	.string "Thank you so much for helping!\n"
	.string "We've been stuck like this for\l"
	.string "a long time...\p"
	.string "As a reward, you can come here\n"
	.string "and fish for free!\p"
	.string "...the first eight times.$"

FishermanDream_Text_ReceivedFreeTickets:
	.string "{PLAYER} received 8 tickets!$"

FishermanDream_Text_Owner_Ready:
	.string "Here goes nothing...\n"
	.string "Are you ready?$"

FishermanDream_Text_Owner_BeQuick:
	.string "Please, help us quickly.\n"
	.string "We can't take much more...$"

FishermanDream_Text_Owner_Busy:
	.string "He looks tired and busy...\n"
	.string "Let's leave him alone.$"

FishermanDream_Text_Owner:
	.string "What did you say? The prices are\n"
	.string "too high?\p"
	.string "Well I do have to make a business\n"
	.string "here, you know!$"

FishermanDream_Text_Employee1_Rattled:
	.string "We won't let you pass until\n"
	.string "you leave those 200 POKéMON.$"

FishermanDream_Text_Employee2_Rattled:
	.string "Oh man...$"

FishermanDream_Text_Employee3_Rattled:
	.string "Ma'am please, calm down...$"

FishermanDream_Text_Employee1_AfterBattle:
	.string "I was ready to battle but boss\n"
	.string "has a strict rule against employees\l"
	.string "participating in battles at work.$"

FishermanDream_Text_Employee2_AfterBattle:
	.string "Maybe if this work wasn't so\n"
	.string "shady it wouldn't attract these\l"
	.string "kinds of individuals...$"

FishermanDream_Text_Employee3_AfterBattle:
	.string "Thank you kid.$"

FishermanDream_Text_Employee1:
	.string "Thanks to the wonders of technology\n"
	.string "we can gather thousands of rare\l"
	.string "POKéMON in this little pond!$."

FishermanDream_Text_Employee2:
	.string "I don't know how ethical is to\n"
	.string "have so many POKéMON waiting to be\l"
	.string "fished for business...$"

FishermanDream_Text_Employee3_NoTickets:
	.string "Welcome back to Fisherman's Dream!\n"
	.string "Do you wish to buy tickets?$"

FishermanDream_Text_Employee3_BuyTickets:
	.string "Welcome back to Fisherman's Dream!\n"
	.string "Do you want to use one ticket?$"

FishermanDream_Text_Employee3_UseTicket:
	.string "Do you want to use one ticket?$"

FishermanDream_Text_Employee3_StartFishing:
	.string "Please proceed to the red door.$"

FishermanDream_Text_Employee3_Goodbye:
	.string "Have a good day, kid.$"

FishermanDream_Text_Employee3_NotEnoughMoney:
	.string "Sorry kid, you need ¥2500\n"
	.string "to buy four tickets.$"

FishermanDream_Text_Employee3_ThankYou:
	.string "Here are four tickets.\n"
	.string "Thank you for the purchase.$"

FishermanDream_Movement_LetOwnerPass:
	walk_down
	walk_in_place_faster_right
	step_end

FishermanDream_Movement_LookAtOwner:
	walk_in_place_faster_right
	step_end

FishermanDream_Movement_OwnerHelp:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_in_place_faster_down
	step_end

FishermanDream_Movement_GoUpThenLookDown:
	walk_up
	walk_in_place_faster_down
	step_end

FishermanDream_Movement_GoRightThenDownOnceAndLookUp:
	delay_2
	walk_right
	walk_down
	walk_in_place_faster_up
	step_end

FishermanDream_Movement_LookDown:
	walk_in_place_faster_down
	step_end

FishermanDream_Movement_LookUp:
	walk_in_place_faster_up
	step_end

FishermanDream_Movement_LookLeft:
	walk_in_place_faster_left
	step_end

FishermanDream_Movement_LookRight:
	walk_in_place_faster_right
	step_end

FishermanDream_Movement_WalkLeft:
	walk_left
	step_end

FishermanDream_Movement_WalkUpLeft:
	walk_up
	walk_left
	step_end

FishermanDream_Movement_AquaGruntMovesToFight:
	walk_down
	walk_left
	delay_16
	delay_16
	walk_in_place_faster_up
	delay_16
	delay_16
	walk_in_place_faster_down
	delay_16
	delay_16
	walk_in_place_fast_left
	delay_16
	step_end

FishermanDream_Movement_AquaGruntIrritated:
	walk_in_place_faster_up
	delay_16
	delay_16
	walk_in_place_faster_down
	delay_16
	delay_16
	walk_in_place_fast_left
	delay_16
	step_end

FishermanDream_Movement_LeaveSpaceForAquaGrunt:
	walk_faster_down
	walk_in_place_fast_up
	step_end

FishermanDream_Movement_GoDown:
	walk_down
	step_end

FishermanDream_Movement_AquaGruntLeaves:
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end

FishermanDream_Movement_Owner_AfterBattle:
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	step_end

FishermanDream_Movement_GoFishUpper:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

FishermanDream_Movement_GoFishHalf:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

FishermanDream_Movement_GoFishLower:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

FishermanDream_Movement_WalkBack:
	delay_8
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end
