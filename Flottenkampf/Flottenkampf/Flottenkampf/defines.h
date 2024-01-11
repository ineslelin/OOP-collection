#pragma once

// #define DEBUG

#define CHOOSE_FLEET			"\nChoose the size of the fleet (1-9)!\n"

#define SHIP_TYPES				"\nChoose the type of ship you want: "

#define BOX_1					"+--------------------------------+--------------------------------+--------------------------------+\n"
#define BOX_2					"|                                |                                |                                |\n"
#define SHIP_CHOICE_1			"| (1) HUNTER                     | (2) DESTROYER                  | (3) CRUISER                    |\n"
#define SHIP_CHOICE_2			"|      Shell:  75                |      Shell: 150                |      Shell: 250                |\n"
#define SHIP_CHOICE_3			"|       Size:   4                |       Size:   6                |       Size:   8                |\n"
#define SHIP_CHOICE_4			"|     Damage:  30                |     Damage:  60                |     Damage:  50                |\n"
							   /*|                                |                                |                                |*/
#define SHIP_CHOICE_5			"|     CRITICAL HITS              |     TARGET-SEEKING             |     BOMBARDEMENT               |\n"
#define SHIP_CHOICE_6			"|     If the result of the       |     Each dice roll has +2      |     For every successful       |\n"
#define SHIP_CHOICE_7			"|     dice roll is >= 9, the     |     added to it.               |     attack, it receives an     |\n"
#define SHIP_CHOICE_8			"|     attack causes double       |                                |     additional turn.           |\n"
#define SHIP_CHOICE_9			"|     damage.                    |                                |                                |\n"
							   /*|                                |                                |                                |
							     +--------------------------------+--------------------------------+--------------------------------+*/

#define ERR_MSG					"Wrong input, try again!\n"

#define HUNTER_SHELL			75
#define HUNTER_SIZE				4
#define HUNTER_DAMAGE			30

#define DESTROYER_SHELL			150
#define DESTROYER_SIZE			6
#define DESTROYER_DAMAGE		60

#define CRUISER_SHELL			250
#define CRUISER_SIZE			8
#define CRUISER_DAMAGE			50