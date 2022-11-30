UndergroundTunnels_DreamOldale_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, UndergroundTunnels_OnTransition
	.byte 0

UndergroundTunnels_DreamOldale_EventScript_LeaveCave::
	locktarget
	goto_if_eq FLAG_DREAM_OLDALE_DEBRIS, 0, UndergroundTunnels_Text_DebrisOnTheWayCannotAdvance
	msgbox UndergroundTunnels_Text_DebrisOnTheWayClearIt, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, UndergroundTunnels_DreamOldale_Leave
	goto UndergroundTunnels_StepBack
	end

UndergroundTunnels_DreamOldale_Leave::
	warp MAP_DREAM_OLDALE, 31, 19
    release
	end

UndergroundTunnels_OnTransition:
	@setflag FLAG_LANDMARK_UNDERGROUND_TUNNELS
	setvar VAR_ASK_TO_LEAVE, 0
	end

UndergroundTunnels_StepBack::
	specialvar VAR_RESULT, GetPlayerFacingDirection
    applymovement OBJ_EVENT_ID_PLAYER, UndergroundTunnels_StepBackMovement
	waitmovement 0
    release
	end

UndergroundTunnels_StepBackMovement::
	goto_if_eq VAR_RESULT, DIR_SOUTH, Common_Movement_WalkUp
	goto_if_eq VAR_RESULT, DIR_NORTH, Common_Movement_WalkDown
	goto_if_eq VAR_RESULT, DIR_EAST, Common_Movement_WalkLeft
	goto_if_eq VAR_RESULT, DIR_WEST, Common_Movement_WalkRight
