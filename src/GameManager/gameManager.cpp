#include "gameManager.h"

GameManager::GameManager()
{
	field = nullptr;
	player = nullptr;
	userInterface = new UserInterface;
	chaser = nullptr;
	ambusher = nullptr;
	jumper = nullptr;
}

std::pair<int, int> GameManager::randomCell()
{
	int x = rand() % field->GetWidth();
	int y = rand() % field->GetHeight();

	while (field->GetField()[y][x].GetCellType() != CellType::PATH || field->IsItemSet(x, y) || field->IsEnemySet(x, y))
	{
		x = rand() % field->GetWidth();
		y = rand() % field->GetHeight();
	}
	return std::make_pair(x, y);
}

void GameManager::setGameObjects()
{
	ItemFactory* itemFactory;
	std::pair<int, int> randPos = randomCell();
	itemFactory = new ItemPointFactory;
	for (int i = 0; i < numOfItemPoint; i++)
	{
		randPos = randomCell();
		field->GetField()[randPos.second][randPos.first].SetItem(itemFactory->CreateItem());
	}
	delete itemFactory;
	itemFactory = new ItemHealthFactory;
	for (int i = 0; i < numOfItemHealth; i++)
	{
		randPos = randomCell();
		field->GetField()[randPos.second][randPos.first].SetItem(itemFactory->CreateItem());
	}
	delete itemFactory;
	itemFactory = new ItemEnergyFactory;
	for (int i = 0; i < numOfItemEnergy; i++)
	{
		randPos = randomCell();
		field->GetField()[randPos.second][randPos.first].SetItem(itemFactory->CreateItem());
	}
	delete itemFactory;
	randPos = randomCell();
	chaser = new Enemy<PolicyChaser>(randPos.first, randPos.second);
	field->GetField()[randPos.second][randPos.first].PlaceChaser(chaser);
	randPos = randomCell();
	ambusher = new Enemy<PolicyAmbusher>(randPos.first, randPos.second);
	field->GetField()[randPos.second][randPos.first].PlaceAmbusher(ambusher);
	randPos = randomCell();
	jumper = new Enemy<PolicyJumper>(randPos.first, randPos.second);
	field->GetField()[randPos.second][randPos.first].PlaceJumper(jumper);
}

void GameManager::OpenMenu()
{
	userInterface->PrintMenu();
	std::string userCommand = userInterface->ScanCommand();
	if (userCommand == "n" || userCommand == "new")
		openNew();
	else if (userCommand == "l" || userCommand == "load")
		openLoad();
	else if (userCommand == "h" || userCommand == "help")
		openHelp(0);
	else if (userCommand != "q" && userCommand != "quit")
	{
		std::cout << "Invalid command!\n";
		OpenMenu();
	}
}

void GameManager::openNew()
{
	if (player)
		delete player;
	if (field)
		field->DeleteField();
	if (chaser)
		delete chaser;
	if (ambusher)
		delete ambusher;
	if (jumper)
		delete jumper;
	field = Field::GetInstance();
	player = new Player(field->GetStart().first, field->GetStart().second);
	player->SetLogPlayer(new LogPlayer(player));
	srand(time(0));
	numOfItemPoint = rand() % 4 + 4;
	pointsToWin = numOfItemPoint;
	numOfItemHealth = rand() % 7 + 6;
	numOfItemEnergy = rand() % 6 + 10;
	field->SetPlayer(player);
	field->GetField()[field->GetStart().second][field->GetStart().first].PlacePlayer(player);
	setGameObjects();
	player->GetLogPlayer()->GameStarts(pointsToWin);
	parseMove();
}

void GameManager::parseMove()
{
	if (field->IsItemSet(chaser->GetX(), chaser->GetY())) {
		std::cout << "Enemy Chaser(]:) is contesting item ";
		switch (field->GetItem(chaser->GetX(), chaser->GetY())->GetIndex()) {
		case 0:
			std::cout << "Health(<3)\n";
			break;
		case 1:
			std::cout << "Energy(~@)\n";
			break;
		case 2:
			std::cout << "Point({+)\n";
			break;
		default:
			break;
		}
	}
	if (field->IsItemSet(ambusher->GetX(), ambusher->GetY())) {
		std::cout << "Enemy Ambusher(S:) is contesting item ";
		switch (field->GetItem(ambusher->GetX(), ambusher->GetY())->GetIndex()) {
		case 0:
			std::cout << "Health(<3)\n";
			break;
		case 1:
			std::cout << "Energy(~@)\n";
			break;
		case 2:
			std::cout << "Point({+)\n";
			break;
		default:
			break;
		}
	}
	if (field->IsItemSet(jumper->GetX(), jumper->GetY())) {
		std::cout << "Enemy Jumper(D:) is contesting item ";
		switch (field->GetItem(jumper->GetX(), jumper->GetY())->GetIndex()) {
		case 0:
			std::cout << "Health(<3)\n";
			break;
		case 1:
			std::cout << "Energy(~@)\n";
			break;
		case 2:
			std::cout << "Point({+)\n";
			break;
		default:
			break;
		}
	}
	if (field->IsStartOrEnd(chaser->GetX(), chaser->GetY()))
		std::cout << "Enemy Chaser(]:) is contesting spawn(->) or exit(>>)\n";
	if (field->IsStartOrEnd(ambusher->GetX(), ambusher->GetY()))
		std::cout << "Enemy Ambusher(S:) is contesting spawn(->) or exit(>>)\n";
	if (field->IsStartOrEnd(jumper->GetX(), jumper->GetY()))
		std::cout << "Enemy Jumper(D:) is contesting spawn(->) or exit(>>)\n";
	userInterface->PrintGame(player, pointsToWin);
	std::string userCommand = userInterface->ScanCommand();
	if (userCommand == "p" || userCommand == "pause")
		openPause();
	else if (userCommand == "a" || userCommand == "left")
		nextMove(-1, 0);
	else if (userCommand == "d" || userCommand == "right")
		nextMove(1, 0);
	else if (userCommand == "w" || userCommand == "up")
		nextMove(0, -1);
	else if (userCommand == "s" || userCommand == "down")
		nextMove(0, 1);
	else if (userCommand == "a2" || userCommand == "left2" || userCommand == "2a" || userCommand == "2left")
		nextMove(-2, 0);
	else if (userCommand == "d2" || userCommand == "right2" || userCommand == "2d" || userCommand == "2right")
		nextMove(2, 0);
	else if (userCommand == "w2" || userCommand == "up2" || userCommand == "2w" || userCommand == "2up")
		nextMove(0, -2);
	else if (userCommand == "s2" || userCommand == "down2" || userCommand == "2s" || userCommand == "2down")
		nextMove(0, 2);
	else if (userCommand != "q" && userCommand != "quit")
	{
		std::cout << "Invalid command!\n";
		parseMove();
	}
}

void GameManager::openLoad()
{
	std::cout << "LOAD: Enter the file name or go BACK\n";
	std::string userCommand = userInterface->ScanCommand();
	if (userCommand == "b" || userCommand == "back")
		OpenMenu();
	else if (userCommand != "q" && userCommand != "quit")
	{
		userCommand = "./" + userCommand;
		Caretaker* caretaker = new Caretaker(this, userCommand, 0);
		if (!caretaker->Load())
		{
			if (caretaker)
				delete caretaker;
			std::cout << "Game was loaded from file " << userCommand << "\n";
			player->GetLogPlayer()->GameStarts(pointsToWin);
			parseMove();
		}
		else
		{
			if (caretaker)
				delete caretaker;
			std::cout << "An error occured. Load was cancelled\n";
			OpenMenu();
		}
	}
}

void GameManager::openSave()
{
	std::cout << "SAVE: Enter the file name or go BACK\n";
	std::string userCommand = userInterface->ScanCommand();
	if (userCommand == "b" || userCommand == "back")
		openPause();
	else if (userCommand != "q" && userCommand != "quit")
	{
		userCommand = "./" + userCommand;
		Caretaker* caretaker = new Caretaker(this, userCommand, 1);
		if (!caretaker->Save())
		{
			if (caretaker)
				delete caretaker;
			std::cout << "Game was saved in file " << userCommand << "\n";
			openPause();
		}
		else
		{
			if (caretaker)
				delete caretaker;
			std::cout << "An error occured. Save was cancelled\n";
			openPause();
		}
	}
}

void GameManager::openHelp(int back)
{
	userInterface->PrintHelp();
	std::string userCommand = userInterface->ScanCommand();
	if (userCommand == "r" || userCommand == "rules")
		openRules(back);
	else if (userCommand == "c" || userCommand == "controls")
		openControls(back);
	else if (userCommand == "b" || userCommand == "back") {
		if (back == 0)
			OpenMenu();
		else
			openPause();
	}
	else if (userCommand != "q" && userCommand != "quit")
	{
		std::cout << "Invalid command!\n";
		openHelp(back);
	}
}

void GameManager::openRules(int back)
{
	userInterface->PrintRules();
	std::string userCommand = userInterface->ScanCommand();
	if (userCommand == "b" || userCommand == "back")
		openHelp(back);
	else if (userCommand == "i" || userCommand == "items")
		openItems(back);
	else if (userCommand == "e" || userCommand == "enemies")
		openEnemies(back);
	else if (userCommand != "q" && userCommand != "quit")
	{
		std::cout << "Invalid command!\n";
		openRules(back);
	}
}

void GameManager::openItems(int back)
{
	userInterface->PrintItems();
	std::string userCommand = userInterface->ScanCommand();
	if (userCommand == "b" || userCommand == "back")
		openRules(back);
	else if (userCommand != "q" && userCommand != "quit")
	{
		std::cout << "Invalid command!\n";
		openItems(back);
	}
}

void GameManager::openEnemies(int back)
{
	userInterface->PrintEnemies();
	std::string userCommand = userInterface->ScanCommand();
	if (userCommand == "b" || userCommand == "back")
		openRules(back);
	else if (userCommand != "q" && userCommand != "quit")
	{
		std::cout << "Invalid command!\n";
		openEnemies(back);
	}
}

void GameManager::openControls(int back)
{
	userInterface->PrintControls();
	std::string userCommand = userInterface->ScanCommand();
	if (userCommand == "b" || userCommand == "back")
		openHelp(back);
	else if (userCommand != "q" && userCommand != "quit")
	{
		std::cout << "Invalid command!\n";
		openControls(back);
	}
}

void GameManager::openWin()
{
	userInterface->PrintWin();
	std::string userCommand = userInterface->ScanCommand();
	if (userCommand == "m" || userCommand == "menu" || userCommand == "<<")
		OpenMenu();
	else if (userCommand == "n" || userCommand == "new" || userCommand == ">>")
		openNew();
	else if (userCommand != "q" && userCommand != "quit")
	{
		std::cout << "Invalid command!\n";
		openWin();
	}
}

void GameManager::openLose(int count)
{
	userInterface->PrintLose();
	std::string userCommand = userInterface->ScanCommand();
	if (userCommand == "m" || userCommand == "menu" || userCommand == "<<")
		OpenMenu();
	else if (userCommand == "n" || userCommand == "new" || userCommand == ">>")
		openNew();
	else if (userCommand != "q" && userCommand != "quit")
	{
		std::cout << "Invalid command!\n";
		count++;
		if (count == 50)
		{
			openWin();
			return;
		}
		openLose(count);
	}
}

void GameManager::openPause()
{
	userInterface->PrintPause();
	std::string userCommand = userInterface->ScanCommand();
	if (userCommand == "b" || userCommand == "back")
		parseMove();
	else if (userCommand == "s" || userCommand == "save")
		openSave();
	else if (userCommand == "h" || userCommand == "help")
		openHelp(1);
	else if (userCommand == "m" || userCommand == "menu")
		OpenMenu();
	else if (userCommand != "q" && userCommand != "quit")
	{
		std::cout << "Invalid command!\n";
		openPause();
	}
}

void GameManager::nextMove(int dx, int dy)
{
	if (field->IsWall(player->GetX() + dx, player->GetY() + dy)) {
		std::cout << "That's not a valid move!\n";
		parseMove();
		return;
	}
	if (abs(dx + dy) == 2)
	{
		if (player->GetEnergy() > 0)
		{
			player->UseJump();
			player->GetLogPlayer()->PlayerJumps();
		}
		else
		{
			std::cout << "You have no energy!\n";
			parseMove();
			return;
		}
	}
	field->GetField()[player->GetY()][player->GetX()].RemovePlayer();
	player->Move(dx, dy);
	field->GetField()[player->GetY()][player->GetX()].PlacePlayer(player);
	player->GetLogPlayer()->PlayerMoves();
	if (field->IsItemSet(player->GetX(), player->GetY()))
	{
		*(field->GetItem(player->GetX(), player->GetY())) + player;
		player->GetLogPlayer()->PlayerCollects(field->GetItem(player->GetX(), player->GetY()), pointsToWin);
		switch (field->GetItem(player->GetX(), player->GetY())->GetIndex())
		{
		case 0:
			numOfItemHealth--;
			break;
		case 1:
			numOfItemEnergy--;
			break;
		case 2:
			numOfItemPoint--;
			break;
		default:
			break;
		}
		field->GetField()[player->GetY()][player->GetX()].DeleteItem();
	}
	bool chaserMove = true;
	bool ambusherMove = true;
	bool jumperMove = true;
	if (player->GetX() == chaser->GetX() && player->GetY() == chaser->GetY())
	{
		chaserMove = false;
		*(chaser->GetPolicy()) + player;
		player->GetLogPlayer()->PlayerTakesDamage();
		std::pair<int, int> randPos = randomCell();
		int newX = randPos.first;
		int newY = randPos.second;
		field->GetField()[chaser->GetY()][chaser->GetX()].RemoveChaser();
		chaser->Move(newX - chaser->GetX(), newY - chaser->GetY());
		field->GetField()[chaser->GetY()][chaser->GetX()].PlaceChaser(chaser);
	}
	if (player->GetX() == ambusher->GetX() && player->GetY() == ambusher->GetY())
	{
		ambusherMove = false;
		*(ambusher->GetPolicy()) + player;
		player->GetLogPlayer()->PlayerTakesDamage();
		std::pair<int, int> randPos = randomCell();
		int newX = randPos.first;
		int newY = randPos.second;
		field->GetField()[ambusher->GetY()][ambusher->GetX()].RemoveAmbusher();
		ambusher->Move(newX - ambusher->GetX(), newY - ambusher->GetY());
		field->GetField()[ambusher->GetY()][ambusher->GetX()].PlaceAmbusher(ambusher);
	}
	if (player->GetX() == jumper->GetX() && player->GetY() == jumper->GetY())
	{
		jumperMove = false;
		*(jumper->GetPolicy()) + player;
		player->GetLogPlayer()->PlayerTakesDamage();
		std::pair<int, int> randPos = randomCell();
		int newX = randPos.first;
		int newY = randPos.second;
		field->GetField()[jumper->GetY()][jumper->GetX()].RemoveJumper();
		jumper->Move(newX - jumper->GetX(), newY - jumper->GetY());
		field->GetField()[jumper->GetY()][jumper->GetX()].PlaceJumper(jumper);
	}
	int startX = field->GetStart().first;
	int startY = field->GetStart().second;
	if (ambusherMove)
	{
		field->GetField()[ambusher->GetY()][ambusher->GetX()].RemoveAmbusher();
		ambusher->MakeMove();
		field->GetField()[ambusher->GetY()][ambusher->GetX()].PlaceAmbusher(ambusher);
	}
	if (player->GetX() == ambusher->GetX() && player->GetY() == ambusher->GetY())
	{
		*(ambusher->GetPolicy()) + player;
		player->GetLogPlayer()->PlayerTakesDamage();
		field->GetField()[player->GetY()][player->GetX()].RemovePlayer();
		player->Move(startX - player->GetX(), startY - player->GetY());
		field->GetField()[player->GetY()][player->GetX()].PlacePlayer(player);
		player->GetLogPlayer()->PlayerMoves();
	}
	if (chaserMove)
	{
		field->GetField()[chaser->GetY()][chaser->GetX()].RemoveChaser();
		chaser->MakeMove();
		field->GetField()[chaser->GetY()][chaser->GetX()].PlaceChaser(chaser);
	}
	if (player->GetX() == chaser->GetX() && player->GetY() == chaser->GetY())
	{
		*(chaser->GetPolicy()) + player;
		player->GetLogPlayer()->PlayerTakesDamage();
		field->GetField()[player->GetY()][player->GetX()].RemovePlayer();
		player->Move(startX - player->GetX(), startY - player->GetY());
		field->GetField()[player->GetY()][player->GetX()].PlacePlayer(player);
		player->GetLogPlayer()->PlayerMoves();

	}
	if (jumperMove)
	{
		field->GetField()[jumper->GetY()][jumper->GetX()].RemoveJumper();
		jumper->MakeMove();
		field->GetField()[jumper->GetY()][jumper->GetX()].PlaceJumper(jumper);
	}
	if (player->GetX() == jumper->GetX() && player->GetY() == jumper->GetY())
	{
		*(jumper->GetPolicy()) + player;
		player->GetLogPlayer()->PlayerTakesDamage();
		field->GetField()[player->GetY()][player->GetX()].RemovePlayer();
		player->Move(startX - player->GetX(), startY - player->GetY());
		field->GetField()[player->GetY()][player->GetX()].PlacePlayer(player);
		player->GetLogPlayer()->PlayerMoves();
	}
	if (player->GetHealth() <= 0)
	{
		player->GetLogPlayer()->GameEnds();
		openLose(0);
		return;
	}
	if (field->GetField()[player->GetY()][player->GetX()].GetCellType() == CellType::END)
	{
		if (player->GetPoints() == pointsToWin)
		{
			player->GetLogPlayer()->GameEnds();
			openWin();
			return;
		}
		else
		{
			std::cout << "You haven't collected all the points!\n";
			parseMove();
			return;
		}
	}
	parseMove();
}


Memento* GameManager::SaveGame() {
	GameState state;
	state.numOfItemPoint = numOfItemPoint;
	state.numOfItemHealth = numOfItemHealth;
	state.numOfItemEnergy = numOfItemEnergy;
	state.pointsToWin = pointsToWin;
	state.playerPoints = player->GetPoints();
	state.playerHealth = player->GetHealth();
	state.playerEnergy = player->GetEnergy();
	state.playerPos = std::make_pair(player->GetX(), player->GetY());
	state.chaserPos = std::make_pair(chaser->GetX(), chaser->GetY());
	state.ambusherPos = std::make_pair(ambusher->GetX(), ambusher->GetY());
	state.jumperPos = std::make_pair(jumper->GetX(), jumper->GetY());
	state.itemPointPos = new std::pair<int, int>[numOfItemPoint];
	state.itemHealthPos = new std::pair<int, int>[numOfItemHealth];
	state.itemEnergyPos = new std::pair<int, int>[numOfItemEnergy];
	int pointCount = 0;
	int healthCount = 0;
	int energyCount = 0;
	for(int i = 0; i < field->GetHeight(); i++)
		for (int j = 0; j < field->GetWidth(); j++)
			if (field->IsItemSet(j, i))
				switch (field->GetItem(j, i)->GetIndex())
				{
				case 0:
					state.itemHealthPos[healthCount] = std::make_pair(j, i);
					healthCount++;
					break;
				case 1:
					state.itemEnergyPos[energyCount] = std::make_pair(j, i);
					energyCount++;
					break;
				case 2:
					state.itemPointPos[pointCount] = std::make_pair(j, i);
					pointCount++;
					break;
				default:
					break;
				}
	return new Memento(state);
}

void GameManager::LoadGame(Memento* snapShot) {
	GameState state = snapShot->GetState();
	if (field)
		field->DeleteField();
	field = Field::GetInstance();

	if (field->IsWall(state.playerPos.first, state.playerPos.second))
		throw ExceptionLoad("Load file is corrupted.\n");
	if (player)
		delete player;
	player = new Player(state.playerPos.first, state.playerPos.second);
	field->SetPlayer(player);
	field->GetField()[state.playerPos.second][state.playerPos.first].PlacePlayer(player);

	if(state.playerPoints < 0 || state.playerPoints > 7)
		throw ExceptionLoad("Load file is corrupted.\n");
	player->SetPoints(state.playerPoints);

	if (state.playerHealth < 0 || state.playerHealth > 18)
		throw ExceptionLoad("Load file is corrupted.\n");
	player->SetHealth(state.playerHealth);

	if (state.playerEnergy < 0 || state.playerEnergy > 18)
		throw ExceptionLoad("Load file is corrupted.\n");
	player->SetEnergy(state.playerEnergy);

	if(state.numOfItemPoint < 0 || state.numOfItemPoint > 7)
		throw ExceptionLoad("Load file is corrupted.\n");
	numOfItemPoint = state.numOfItemPoint;

	if(state.numOfItemPoint + state.playerPoints != state.pointsToWin || state.pointsToWin > 7)
		throw ExceptionLoad("Load file is corrupted.\n");
	pointsToWin = state.pointsToWin;

	if(state.numOfItemHealth > 12 || state.numOfItemHealth + state.playerHealth > 18)
		throw ExceptionLoad("Load file is corrupted.\n");
	numOfItemHealth = state.numOfItemHealth;

	if (state.numOfItemEnergy > 15 || state.numOfItemEnergy + state.playerEnergy > 18)
		throw ExceptionLoad("Load file is corrupted.\n");
	numOfItemEnergy = state.numOfItemEnergy;

	player->SetLogPlayer(new LogPlayer(player));

	ItemFactory* itemFactory;
	itemFactory = new ItemPointFactory;
	for (int i = 0; i < numOfItemPoint; i++)
	{
		if (field->IsWall(state.itemPointPos[i].first, state.itemPointPos[i].second) ||
			field->IsItemSet(state.itemPointPos[i].first, state.itemPointPos[i].second) ||
			field->IsPlayerSet(state.itemPointPos[i].first, state.itemPointPos[i].second))
		{
			delete itemFactory;
			throw ExceptionLoad("Load file is corrupted.\n");
		}
		field->GetField()[state.itemPointPos[i].second][state.itemPointPos[i].first].SetItem(itemFactory->CreateItem());
	}
	delete itemFactory;

	itemFactory = new ItemHealthFactory;
	for (int i = 0; i < numOfItemHealth; i++)
	{
		if (field->IsWall(state.itemHealthPos[i].first, state.itemHealthPos[i].second) ||
			field->IsItemSet(state.itemHealthPos[i].first, state.itemHealthPos[i].second) ||
			field->IsPlayerSet(state.itemHealthPos[i].first, state.itemHealthPos[i].second))
		{
			delete itemFactory;
			throw ExceptionLoad("Load file is corrupted.\n");
		}
		field->GetField()[state.itemHealthPos[i].second][state.itemHealthPos[i].first].SetItem(itemFactory->CreateItem());
	}
	delete itemFactory;

	itemFactory = new ItemEnergyFactory;
	for (int i = 0; i < numOfItemEnergy; i++)
	{
		if (field->IsWall(state.itemEnergyPos[i].first, state.itemEnergyPos[i].second) ||
			field->IsItemSet(state.itemEnergyPos[i].first, state.itemEnergyPos[i].second) ||
			field->IsPlayerSet(state.itemEnergyPos[i].first, state.itemEnergyPos[i].second))
		{
			delete itemFactory;
			throw ExceptionLoad("Load file is corrupted.\n");
		}
		field->GetField()[state.itemEnergyPos[i].second][state.itemEnergyPos[i].first].SetItem(itemFactory->CreateItem());
	}
	delete itemFactory;

	if (field->IsWall(state.chaserPos.first, state.chaserPos.second) ||
		field->IsEnemySet(state.chaserPos.first, state.chaserPos.second) ||
		field->IsPlayerSet(state.chaserPos.first, state.chaserPos.second))
		throw ExceptionLoad("Load file is corrupted.\n");
	if (chaser)
		delete chaser;
	chaser = new Enemy<PolicyChaser>(state.chaserPos.first, state.chaserPos.second);
	field->GetField()[state.chaserPos.second][state.chaserPos.first].PlaceChaser(chaser);

	if (field->IsWall(state.ambusherPos.first, state.ambusherPos.second) ||
		field->IsEnemySet(state.ambusherPos.first, state.ambusherPos.second) ||
		field->IsPlayerSet(state.ambusherPos.first, state.ambusherPos.second))
		throw ExceptionLoad("Load file is corrupted.\n");
	if (ambusher)
		delete ambusher;
	ambusher = new Enemy<PolicyAmbusher>(state.ambusherPos.first, state.ambusherPos.second);
	field->GetField()[state.ambusherPos.second][state.ambusherPos.first].PlaceAmbusher(ambusher);

	if (field->IsWall(state.jumperPos.first, state.jumperPos.second) ||
		field->IsEnemySet(state.jumperPos.first, state.jumperPos.second) ||
		field->IsPlayerSet(state.jumperPos.first, state.jumperPos.second))
		throw ExceptionLoad("Load file is corrupted.\n");
	if (jumper)
		delete jumper;
	jumper = new Enemy<PolicyJumper>(state.jumperPos.first, state.jumperPos.second);
	field->GetField()[state.jumperPos.second][state.jumperPos.first].PlaceJumper(jumper);
}

GameManager::~GameManager()
{
	if (player)
		delete player;
	if (field)
		field->DeleteField();
	if (userInterface)
		delete userInterface;
	if (chaser)
		delete chaser;
	if (ambusher)
		delete ambusher;
	if (jumper)
		delete jumper;
}
