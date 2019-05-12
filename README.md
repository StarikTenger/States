# States
This is a cellular automaton that simulates war between some states.
Each cell includes following parameters:
* The identifier of the empire the cell belongs to (0 if there is no owner, such cells are called "black")
* The amount of soldiers in a cell
* Age 

Each turn is divided into 5 parts:
1) Each cell increases it's age by if it's age is less than agelimit constant. In black cells it becomes 0
2) On every cell that belongs to state amount of soldiers increases by a constant
3) Every black cell is captured by a state if there is a neighbor cell with such a state value (in conflict situations priority is random)
4) All soldiers from each cell move to random neighbor cell. The movement is't happened if tharget cell is black or enemy or it's older then the original cell
5) Each non-black cell kills as much soldiers in each neighboring enemy cell as the number of soldiers in itself. The cell becomes black if all soldiers are dead

Picture below shows age map: the lighter the cell, the larger it's age
![](https://cdn.discordapp.com/attachments/444936496135536672/576828502284828682/unknown.png)

To compile project you need to link SDL-2.0.8
To run compilled programm open war/state.exe. The map is toroidal, to move camera use WASD keys, to change display mode use space key



