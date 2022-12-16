DreamPetalburg_House1_MapScripts::
	.byte 0

DreamOldale_EventScript_Kirlia::
	locktarget
	faceplayer
	waitse
	playmoncry SPECIES_KIRLIA, CRY_MODE_NORMAL
	msgbox DreamPetalburg_TextKirlia, MSGBOX_DEFAULT
	waitmoncry
	release
	end

DreamOldale_EventScript_Man1::
	locktarget
	msgbox DreamPetalburg_Text_Man1, MSGBOX_NPC
	release
	end

DreamOldale_EventScript_Man2::
	locktarget
	msgbox DreamPetalburg_Text_Man2, MSGBOX_NPC
	release
	end

DreamPetalburg_Text_Man1:
	.string "Kiki often helps me clean\n"
	.string "with its psychic powers.$"

DreamPetalburg_Text_Man2:
	.string "We decided to live here\n"
	.string "not long ago.\p"
	.string "Coming from Petalburg is always\n"
	.string "troublesome with all that tall grass!$"

DreamPetalburg_TextKirlia:
	.string "Kirlia: Kikiraaa!!$"
