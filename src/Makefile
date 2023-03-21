all: main.o cell.o field.o character.o player.o item.o itemFactory.o itemHealth.o itemHealthFactory.o itemEnergy.o itemEnergyFactory.o itemPoint.o itemPointFactory.o gameManager.o userInterface.o logFile.o logPlayer.o enemy.o policy.o policyChaser.o policyAmbusher.o policyJumper.o saveFile.o gameState.o memento.o caretaker.o exception.o exceptionFile.o exceptionLoad.o
	g++ main.o cell.o field.o character.o player.o item.o itemFactory.o itemHealth.o itemHealthFactory.o itemEnergy.o itemEnergyFactory.o itemPoint.o itemPointFactory.o gameManager.o userInterface.o logFile.o logPlayer.o enemy.o policy.o policyChaser.o policyAmbusher.o policyJumper.o saveFile.o gameState.o memento.o caretaker.o exception.o exceptionFile.o exceptionLoad.o -o oop_lab

main.o: Main/main.cpp
	g++ -c Main/main.cpp

cell.o: Cell/cell.cpp Cell/cell.h
	g++ -c Cell/cell.cpp

field.o: Field/field.cpp Field/field.h
	g++ -c Field/field.cpp

character.o: Characters/character.cpp Characters/character.h
	g++ -c Characters/character.cpp

player.o: Characters/player.cpp Characters/player.h
	g++ -c Characters/player.cpp

item.o: Items/item.cpp Items/item.h
	g++ -c Items/item.cpp

itemFactory.o: Items/itemFactory.cpp Items/itemFactory.h
	g++ -c Items/itemFactory.cpp

itemHealth.o: Items/ItemHealth/itemHealth.cpp Items/ItemHealth/itemHealth.h
	g++ -c Items/ItemHealth/itemHealth.cpp

itemHealthFactory.o: Items/ItemHealth/itemHealthFactory.cpp Items/ItemHealth/itemHealthFactory.h
	g++ -c Items/ItemHealth/itemHealthFactory.cpp

itemEnergy.o: Items/ItemEnergy/itemEnergy.cpp Items/ItemEnergy/itemEnergy.h
	g++ -c Items/ItemEnergy/itemEnergy.cpp

itemEnergyFactory.o: Items/ItemEnergy/itemEnergyFactory.cpp Items/ItemEnergy/itemEnergyFactory.h
	g++ -c Items/ItemEnergy/itemEnergyFactory.cpp

itemPoint.o: Items/ItemPoint/itemPoint.cpp Items/ItemPoint/itemPoint.h
	g++ -c Items/ItemPoint/itemPoint.cpp

itemPointFactory.o: Items/ItemPoint/itemPointFactory.cpp Items/ItemPoint/itemPointFactory.h
	g++ -c Items/ItemPoint/itemPointFactory.cpp

gameManager.o: GameManager/gameManager.cpp GameManager/gameManager.h
	g++ -c GameManager/gameManager.cpp

userInterface.o: UserInterface/userInterface.cpp UserInterface/userInterface.h
	g++ -c UserInterface/userInterface.cpp

logFile.o: Logs/logFile.cpp Logs/logFile.h
	g++ -c Logs/logFile.cpp

logPlayer.o: Logs/logPlayer.cpp Logs/logPlayer.h
	g++ -c Logs/logPlayer.cpp

enemy.o: Characters/enemy.cpp Characters/enemy.h
	g++ -c Characters/enemy.cpp

policy.o: Characters/Policies/policy.cpp Characters/Policies/policy.h
	g++ -c Characters/Policies/policy.cpp

policyChaser.o: Characters/Policies/policyChaser.cpp Characters/Policies/policyChaser.h
	g++ -c Characters/Policies/policyChaser.cpp

policyAmbusher.o: Characters/Policies/policyAmbusher.cpp Characters/Policies/policyAmbusher.h
	g++ -c Characters/Policies/policyAmbusher.cpp

policyJumper.o: Characters/Policies/policyJumper.cpp Characters/Policies/policyJumper.h
	g++ -c Characters/Policies/policyJumper.cpp

saveFile.o: GameSave/saveFile.cpp GameSave/saveFile.h
	g++ -c GameSave/saveFile.cpp

gameState.o: GameSave/gameState.cpp GameSave/gameState.h
	g++ -c GameSave/gameState.cpp

memento.o: GameSave/memento.cpp GameSave/memento.h
	g++ -c GameSave/memento.cpp

caretaker.o: GameSave/caretaker.cpp GameSave/caretaker.h
	g++ -c GameSave/caretaker.cpp

exception.o: GameSave/Exceptions/exception.cpp GameSave/Exceptions/exception.h
	g++ -c GameSave/Exceptions/exception.cpp

exceptionFile.o: GameSave/Exceptions/exceptionFile.cpp GameSave/Exceptions/exceptionFile.h
	g++ -c GameSave/Exceptions/exceptionFile.cpp

exceptionLoad.o: GameSave/Exceptions/exceptionLoad.cpp GameSave/Exceptions/exceptionLoad.h
	g++ -c GameSave/Exceptions/exceptionLoad.cpp

clean:
	@rm -rf *.o
	echo "\nClean complete"
