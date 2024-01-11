#pragma once

#include "map.h"
class map;

class robot
{
	public:
		robot();
		robot(int score, int xCoord, int yCoord, bool sortDesc, bool firstThree, bool evenOdd);
		virtual ~robot();

		int getScore();
		void setScore(int score);
		int getXCoord();
		void setXCoord(int xCoord);
		int getYCoord();
		void setYCoord(int yCoord);

		void movement();
		void action(map* pMap);

	protected:
		int score;
		int xCoord;
		int yCoord;

		bool sortDesc;
		bool firstThree;
		bool evenOdd;
};
