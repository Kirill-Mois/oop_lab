#include "userInterface.h"

UserInterface::UserInterface()
{
	field = Field::GetInstance();
}

std::string UserInterface::ScanCommand() {
	std::cout << "Enter your command: ";
	std::string userCommand;
	std::getline(std::cin, userCommand);
	std::transform(userCommand.begin(), userCommand.end(), userCommand.begin(),
		[](unsigned char c) { return std::tolower(c); });
	return userCommand;
}

void UserInterface::PrintMenu()
{
	std::cout << "▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄\n";
	std::cout << "▌                                      ▐\n";
	std::cout << "▌       ╔═╗╔═╗╔═╗     ╔╗ ╔══╗╔╗        ▐\n";
	std::cout << "▌       ║║║║║║║║║     ║║ ║╔╗║║╚╗       ▐\n";
	std::cout << "▌       ║║║║║║║╔╝     ║╚╗║╠╣║║║║       ▐\n";
	std::cout << "▌       ╚═╝╚═╝╚╝      ╚═╝╚╝╚╝╚═╝       ▐\n";
	std::cout << "▌                                      ▐\n";
	std::cout << "▌  ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░  ▐\n";
	std::cout << "▌                                      ▐\n";
	std::cout << "▌             ╔═╦╗╔═╗╔╦═╦╗             ▐\n";
	std::cout << "▌             ║║║║║╦╝║║║║║             ▐\n";
	std::cout << "▌             ║║║║║╩╗║║║║║             ▐\n";
	std::cout << "▌             ╚╩═╝╚═╝╚═╩═╝             ▐\n";
	std::cout << "▌            ╔╗ ╔═╗╔══╗╔══╗            ▐\n";
	std::cout << "▌            ║║ ║║║║╔╗║╚╗╗║            ▐\n";
	std::cout << "▌            ║╚╗║║║║╠╣║╔╝╝║            ▐\n";
	std::cout << "▌            ╚═╝╚═╝╚╝╚╝╚══╝            ▐\n";
	std::cout << "▌            ╔╗╔╗╔═╗╔╗ ╔═╗             ▐\n";
	std::cout << "▌            ║╚╝║║╦╝║║ ║║║             ▐\n";
	std::cout << "▌            ║╔╗║║╩╗║╚╗║╔╝             ▐\n";
	std::cout << "▌            ╚╝╚╝╚═╝╚═╝╚╝              ▐\n";
	std::cout << "▌            ╔═╗╔╦╗╔══╗╔══╗            ▐\n";
	std::cout << "▌            ║║║║║║╚║║╝╚╗╔╝            ▐\n";
	std::cout << "▌            ╚╗║║║║╔║║╗ ║║             ▐\n";
	std::cout << "▌             ╚╝╚═╝╚══╝ ╚╝             ▐\n";
	std::cout << "▌                                      ▐\n";
	std::cout << "▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀\n";
}

void UserInterface::PrintGame(Player* player, int pointsToWin) {
	std::cout << "▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄\n";
	std::cout << "▌                                      ▐\n";
	std::cout << "▌ Health<3 " << player->GetHealth();
	if (player->GetHealth() < 10)
		std::cout << "  Points{+ " << player->GetPoints() << '/' << pointsToWin;
	else
		std::cout << " Points{+ " << player->GetPoints() << '/' << pointsToWin;
	if(player->GetEnergy() < 10)
		std::cout << "  Energy~@ " << player->GetEnergy() << " ▐\n";
	else
		std::cout << " Energy~@ " << player->GetEnergy() << " ▐\n";
	std::cout << "▌                                      ▐\n";
	for (int i = 0; i < field->GetHeight(); i++)
	{
		std::cout << "▌";
		for (int j = 0; j < field->GetWidth(); j++)
		{
			if (field->IsPlayerSet(j, i))
				std::cout << "(=";
			else if (field->IsEnemySet(j, i))
			{
				switch (field->GetField()[i][j].GetEnemyIndex())
				{
				case 0:
					std::cout << "]:";
					break;
				case 1:
					std::cout << "S:";
					break;
				case 2:
					std::cout << "D:";
					break;
				default:
					break;
				}
			}
			else if (field->IsItemSet(j, i))
			{
				switch (field->GetItem(j, i)->GetIndex())
				{
				case 0:
					std::cout << "<3";
					break;
				case 1:
					std::cout << "~@";
					break;
				case 2:
					std::cout << "{+";
					break;
				default:
					break;
				}
			}
			else {
				switch (field->GetField()[i][j].GetCellType())
				{
				case CellType::PATH:
					std::cout << "  ";
					break;
				case CellType::WALL:
					std::cout << "░░";
					break;
				case CellType::START:
					std::cout << "->";
					break;
				case CellType::END:
					std::cout << ">>";
					break;
				default:
					break;
				}
			}
		}
		std::cout << "▐\n";
	}
	std::cout << "▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀\n";
}

void UserInterface::PrintHelp()
{
	std::cout << "▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄\n";
	std::cout << "▌                                      ▐\n";
	std::cout << "▌       ╔═╗╔═╗╔═╗     ╔╗ ╔══╗╔╗        ▐\n";
	std::cout << "▌       ║║║║║║║║║     ║║ ║╔╗║║╚╗       ▐\n";
	std::cout << "▌       ║║║║║║║╔╝     ║╚╗║╠╣║║║║       ▐\n";
	std::cout << "▌       ╚═╝╚═╝╚╝      ╚═╝╚╝╚╝╚═╝       ▐\n";
	std::cout << "▌                                      ▐\n";
	std::cout << "▌  ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░  ▐\n";
	std::cout << "▌                                      ▐\n";
	std::cout << "▌                                      ▐\n";
	std::cout << "▌           ╔═╗╔╦╗╔╗ ╔═╗╔══╗           ▐\n";
	std::cout << "▌           ║║║║║║║║ ║╦╝║══╣           ▐\n";
	std::cout << "▌           ║╗╣║║║║╚╗║╩╗╠══║           ▐\n";
	std::cout << "▌           ╚╩╝╚═╝╚═╝╚═╝╚══╝           ▐\n";
	std::cout << "▌                                      ▐\n";
	std::cout << "▌     ╔═╗╔═╗╔═╦╗╔══╗╔═╗╔═╗╔╗ ╔══╗      ▐\n";
	std::cout << "▌     ║╔╝║║║║║║║╚╗╔╝║║║║║║║║ ║══╣      ▐\n";
	std::cout << "▌     ║╚╗║║║║║║║ ║║ ║╗╣║║║║╚╗╠══║      ▐\n";
	std::cout << "▌     ╚═╝╚═╝╚╩═╝ ╚╝ ╚╩╝╚═╝╚═╝╚══╝      ▐\n";
	std::cout << "▌                                      ▐\n";
	std::cout << "▌                                      ▐\n";
	std::cout << "▌            ╔╗ ╔══╗╔═╗╔╦╗             ▐\n";
	std::cout << "▌            ║╚╗║╔╗║║╔╝║╔╝             ▐\n";
	std::cout << "▌            ║║║║╠╣║║╚╗║╚╗             ▐\n";
	std::cout << "▌            ╚═╝╚╝╚╝╚═╝╚╩╝             ▐\n";
	std::cout << "▌                                      ▐\n";
	std::cout << "▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀\n";
}

void UserInterface::PrintRules()
{
	std::cout << "▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄\n";
	std::cout << "▌                                      ▐\n";
	std::cout << "▌       ╔═╗╔═╗╔═╗     ╔╗ ╔══╗╔╗        ▐\n";
	std::cout << "▌       ║║║║║║║║║     ║║ ║╔╗║║╚╗       ▐\n";
	std::cout << "▌       ║║║║║║║╔╝     ║╚╗║╠╣║║║║       ▐\n";
	std::cout << "▌       ╚═╝╚═╝╚╝      ╚═╝╚╝╚╝╚═╝       ▐\n";
	std::cout << "▌                                      ▐\n";
	std::cout << "▌  ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░  ▐\n";
	std::cout << "▌                                      ▐\n";
	std::cout << "▌        Сollect all the points        ▐\n";
	std::cout << "▌         and reach the exit!          ▐\n";
	std::cout << "▌  -> - spawn  (= - player  >> - exit  ▐\n";
	std::cout << "▌  If your health reaches 0 you lose!  ▐\n";
	std::cout << "▌         ╔══╗╔══╗╔═╗╔═╦═╗╔══╗         ▐\n";
	std::cout << "▌         ╚║║╝╚╗╔╝║╦╝║║║║║║══╣         ▐\n";
	std::cout << "▌         ╔║║╗ ║║ ║╩╗║║║║║╠══║         ▐\n";
	std::cout << "▌         ╚══╝ ╚╝ ╚═╝╚╩═╩╝╚══╝         ▐\n";
	std::cout << "▌      ╔═╗╔═╦╗╔═╗╔═╦═╗╔══╗╔═╗╔══╗      ▐\n";
	std::cout << "▌      ║╦╝║║║║║╦╝║║║║║╚║║╝║╦╝║══╣      ▐\n";
	std::cout << "▌      ║╩╗║║║║║╩╗║║║║║╔║║╗║╩╗╠══║      ▐\n";
	std::cout << "▌      ╚═╝╚╩═╝╚═╝╚╩═╩╝╚══╝╚═╝╚══╝      ▐\n";
	std::cout << "▌            ╔╗ ╔══╗╔═╗╔╦╗             ▐\n";
	std::cout << "▌            ║╚╗║╔╗║║╔╝║╔╝             ▐\n";
	std::cout << "▌            ║║║║╠╣║║╚╗║╚╗             ▐\n";
	std::cout << "▌            ╚═╝╚╝╚╝╚═╝╚╩╝             ▐\n";
	std::cout << "▌                                      ▐\n";
	std::cout << "▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀\n";
}

void UserInterface::PrintItems()
{
	std::cout << "▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄\n";
	std::cout << "▌                                      ▐\n";
	std::cout << "▌       ╔═╗╔═╗╔═╗     ╔╗ ╔══╗╔╗        ▐\n";
	std::cout << "▌       ║║║║║║║║║     ║║ ║╔╗║║╚╗       ▐\n";
	std::cout << "▌       ║║║║║║║╔╝     ║╚╗║╠╣║║║║       ▐\n";
	std::cout << "▌       ╚═╝╚═╝╚╝      ╚═╝╚╝╚╝╚═╝       ▐\n";
	std::cout << "▌                                      ▐\n";
	std::cout << "▌  ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░  ▐\n";
	std::cout << "▌                                      ▐\n";
	std::cout << "▌   {+ - main point, collect all       ▐\n";
	std::cout << "▌        of them to win the game       ▐\n";
	std::cout << "▌   <3 - collect to add 1 health       ▐\n";
	std::cout << "▌        to your character             ▐\n";
	std::cout << "▌   ~@ - collect to add 1 energy       ▐\n";
	std::cout << "▌        to your character             ▐\n";
	std::cout << "▌                                      ▐\n";
	std::cout << "▌    Energy allows you to jump         ▐\n";
	std::cout << "▌    over 1 cell in one move;          ▐\n";
	std::cout << "▌    you can use it to skip walls,     ▐\n";
	std::cout << "▌    evade or attack enemies, etc.     ▐\n";
	std::cout << "▌                                      ▐\n";
	std::cout << "▌            ╔╗ ╔══╗╔═╗╔╦╗             ▐\n";
	std::cout << "▌            ║╚╗║╔╗║║╔╝║╔╝             ▐\n";
	std::cout << "▌            ║║║║╠╣║║╚╗║╚╗             ▐\n";
	std::cout << "▌            ╚═╝╚╝╚╝╚═╝╚╩╝             ▐\n";
	std::cout << "▌                                      ▐\n";
	std::cout << "▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀\n";
}

void UserInterface::PrintEnemies()
{
	std::cout << "▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄\n";
	std::cout << "▌                                      ▐\n";
	std::cout << "▌       ╔═╗╔═╗╔═╗     ╔╗ ╔══╗╔╗        ▐\n";
	std::cout << "▌       ║║║║║║║║║     ║║ ║╔╗║║╚╗       ▐\n";
	std::cout << "▌       ║║║║║║║╔╝     ║╚╗║╠╣║║║║       ▐\n";
	std::cout << "▌       ╚═╝╚═╝╚╝      ╚═╝╚╝╚╝╚═╝       ▐\n";
	std::cout << "▌                                      ▐\n";
	std::cout << "▌  ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░  ▐\n";
	std::cout << "▌                                      ▐\n";
	std::cout << "▌  S: - Ambusher, moves to a random    ▐\n";
	std::cout << "▌       cell around the player,        ▐\n";
	std::cout << "▌       if player is in range of one   ▐\n";
	std::cout << "▌       cell, moves directly to him;   ▐\n";
	std::cout << "▌       deals 3 damage                 ▐\n";
	std::cout << "▌  ]: - Chaser, moves 1 cell           ▐\n";
	std::cout << "▌       left, right, up or down;       ▐\n";
	std::cout << "▌       deals 2 damage                 ▐\n";
	std::cout << "▌  D: - Jumper, moves like a knight    ▐\n";
	std::cout << "▌       from chess; deals 1 damage     ▐\n";
	std::cout << "▌If you attack an enemy you take damage▐\n";
	std::cout << "▌Characters respawn if they're attacked▐\n";
	std::cout << "▌            ╔╗ ╔══╗╔═╗╔╦╗             ▐\n";
	std::cout << "▌            ║╚╗║╔╗║║╔╝║╔╝             ▐\n";
	std::cout << "▌            ║║║║╠╣║║╚╗║╚╗             ▐\n";
	std::cout << "▌            ╚═╝╚╝╚╝╚═╝╚╩╝             ▐\n";
	std::cout << "▌                                      ▐\n";
	std::cout << "▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀\n";
}

void UserInterface::PrintControls()
{
	std::cout << "▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄\n";
	std::cout << "▌                                      ▐\n";
	std::cout << "▌       ╔═╗╔═╗╔═╗     ╔╗ ╔══╗╔╗        ▐\n";
	std::cout << "▌       ║║║║║║║║║     ║║ ║╔╗║║╚╗       ▐\n";
	std::cout << "▌       ║║║║║║║╔╝     ║╚╗║╠╣║║║║       ▐\n";
	std::cout << "▌       ╚═╝╚═╝╚╝      ╚═╝╚╝╚╝╚═╝       ▐\n";
	std::cout << "▌                                      ▐\n";
	std::cout << "▌  ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░  ▐\n";
	std::cout << "▌                                      ▐\n";
	std::cout << "▌    p/pause - pause the game          ▐\n";
	std::cout << "▌    q/quit - quit the game            ▐\n";
	std::cout << "▌    w/up - move up                    ▐\n";
	std::cout << "▌    a/left - move left                ▐\n";
	std::cout << "▌    s/down - move down                ▐\n";
	std::cout << "▌    d/right - move right              ▐\n";
	std::cout << "▌    2 with the direction - use jump   ▐\n";
	std::cout << "▌                                      ▐\n";
	std::cout << "▌                                      ▐\n";
	std::cout << "▌    All the interface commands also   ▐\n";
	std::cout << "▌   have an abbreviated and full form  ▐\n";
	std::cout << "▌                                      ▐\n";
	std::cout << "▌            ╔╗ ╔══╗╔═╗╔╦╗             ▐\n";
	std::cout << "▌            ║╚╗║╔╗║║╔╝║╔╝             ▐\n";
	std::cout << "▌            ║║║║╠╣║║╚╗║╚╗             ▐\n";
	std::cout << "▌            ╚═╝╚╝╚╝╚═╝╚╩╝             ▐\n";
	std::cout << "▌                                      ▐\n";
	std::cout << "▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀\n";
}

void UserInterface::PrintPause()
{
	std::cout << "▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄\n";
	std::cout << "▌                                      ▐\n";
	std::cout << "▌       ╔═╗╔═╗╔═╗     ╔╗ ╔══╗╔╗        ▐\n";
	std::cout << "▌       ║║║║║║║║║     ║║ ║╔╗║║╚╗       ▐\n";
	std::cout << "▌       ║║║║║║║╔╝     ║╚╗║╠╣║║║║       ▐\n";
	std::cout << "▌       ╚═╝╚═╝╚╝      ╚═╝╚╝╚╝╚═╝       ▐\n";
	std::cout << "▌                                      ▐\n";
	std::cout << "▌  ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░  ▐\n";
	std::cout << "▌                                      ▐\n";
	std::cout << "▌            ╔╗ ╔══╗╔═╗╔╦╗             ▐\n";
	std::cout << "▌            ║╚╗║╔╗║║╔╝║╔╝             ▐\n";
	std::cout << "▌            ║║║║╠╣║║╚╗║╚╗             ▐\n";
	std::cout << "▌            ╚═╝╚╝╚╝╚═╝╚╩╝             ▐\n";
	std::cout << "▌           ╔══╗╔══╗╔╗ ╔╗╔═╗           ▐\n";
	std::cout << "▌           ║══╣║╔╗║║╚╦╝║║╦╝           ▐\n";
	std::cout << "▌           ╠══║║╠╣║╚╗║╔╝║╩╗           ▐\n";
	std::cout << "▌           ╚══╝╚╝╚╝ ╚═╝ ╚═╝           ▐\n";
	std::cout << "▌            ╔╗╔╗╔═╗╔╗ ╔═╗             ▐\n";
	std::cout << "▌            ║╚╝║║╦╝║║ ║║║             ▐\n";
	std::cout << "▌            ║╔╗║║╩╗║╚╗║╔╝             ▐\n";
	std::cout << "▌            ╚╝╚╝╚═╝╚═╝╚╝              ▐\n";
	std::cout << "▌           ╔═╦═╗╔═╗╔═╦╗╔╦╗            ▐\n";
	std::cout << "▌           ║║║║║║╦╝║║║║║║║            ▐\n";
	std::cout << "▌           ║║║║║║╩╗║║║║║║║            ▐\n";
	std::cout << "▌           ╚╩═╩╝╚═╝╚╩═╝╚═╝            ▐\n";
	std::cout << "▌                                      ▐\n";
	std::cout << "▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀\n";
}

void UserInterface::PrintWin()
{
	std::cout << "▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄\n";
	std::cout << "▌                                      ▐\n";
	std::cout << "▌       ╔═╗╔═╗╔═╗     ╔╗ ╔══╗╔╗        ▐\n";
	std::cout << "▌       ║║║║║║║║║     ║║ ║╔╗║║╚╗       ▐\n";
	std::cout << "▌       ║║║║║║║╔╝     ║╚╗║╠╣║║║║       ▐\n";
	std::cout << "▌       ╚═╝╚═╝╚╝      ╚═╝╚╝╚╝╚═╝       ▐\n";
	std::cout << "▌                                      ▐\n";
	std::cout << "▌  ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░  ▐\n";
	std::cout << "▌                                      ▐\n";
	std::cout << "▌                                      ▐\n";
	std::cout << "▌                        ╬             ▐\n";
	std::cout << "▌            ╬     C=                  ▐\n";
	std::cout << "▌       ╬                              ▐\n";
	std::cout << "▌  ╔╗ ╔╗                   ╬      ╔╗   ▐\n";
	std::cout << "▌  ║║ ║║                          ║║   ▐\n";
	std::cout << "▌  ║╚═╝║╔══╗╔╗╔╗     ╔╗╔╗╔╗╔╗╔═╗  ║║   ▐\n";
	std::cout << "▌  ╚═╗╔╝║╔╗║║║║║     ║╚╝╚╝║╠╣║╔╗╗ ╚╝   ▐\n";
	std::cout << "▌    ║║ ║╚╝║║╚╝║     ╚╗╔╗╔╝║║║║║║ ╔╗   ▐\n";
	std::cout << "▌    ╚╝ ╚══╝╚══╝      ╚╝╚╝ ╚╝╚╝╚╝ ╚╝   ▐\n";
	std::cout << "▌                             ╬        ▐\n";
	std::cout << "▌        ╬                             ▐\n";
	std::cout << "▌                      ╬               ▐\n";
	std::cout << "▌                                      ▐\n";
	std::cout << "▌               ╬                      ▐\n";
	std::cout << "▌                                      ▐\n";
	std::cout << "▌<< Menu                         New >>▐\n";
	std::cout << "▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀\n";
}

void UserInterface::PrintLose()
{
	std::cout << "▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄\n";
	std::cout << "▌                                      ▐\n";
	std::cout << "▌       ╔═╗╔═╗╔═╗     ╔╗ ╔══╗╔╗        ▐\n";
	std::cout << "▌       ║║║║║║║║║     ║║ ║╔╗║║╚╗       ▐\n";
	std::cout << "▌       ║║║║║║║╔╝     ║╚╗║╠╣║║║║       ▐\n";
	std::cout << "▌       ╚═╝╚═╝╚╝      ╚═╝╚╝╚╝╚═╝       ▐\n";
	std::cout << "▌                                      ▐\n";
	std::cout << "▌  ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░  ▐\n";
	std::cout << "▌                                      ▐\n";
	std::cout << "▌                                      ▐\n";
	std::cout << "▌                                      ▐\n";
	std::cout << "▌                  )X                  ▐\n";
	std::cout << "▌                                      ▐\n";
	std::cout << "▌  ╔╗ ╔╗                           ╔╗  ▐\n";
	std::cout << "▌  ║║ ║║             ╔╗            ║║  ▐\n";
	std::cout << "▌  ║╚═╝║╔══╗╔╗╔╗     ║║╔══╗╔══╗╔═╗ ║║  ▐\n";
	std::cout << "▌  ╚═╗╔╝║╔╗║║║║║     ║║║╔╗║║══╣║╦╝ ╚╝  ▐\n";
	std::cout << "▌    ║║ ║╚╝║║╚╝║     ║║║╚╝║╠══║║╩╗ ╔╗  ▐\n";
	std::cout << "▌    ╚╝ ╚══╝╚══╝     ╚╝╚══╝╚══╝╚═╝ ╚╝  ▐\n";
	std::cout << "▌                                      ▐\n";
	std::cout << "▌                                      ▐\n";
	std::cout << "▌                                      ▐\n";
	std::cout << "▌                                      ▐\n";
	std::cout << "▌                                      ▐\n";
	std::cout << "▌                                      ▐\n";
	std::cout << "▌<< Menu                         New >>▐\n";
	std::cout << "▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀\n";
}
