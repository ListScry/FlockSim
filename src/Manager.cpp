#include "Manager.h"

#include <stdio.h>
#include <chrono>
#include <thread>
#include <iostream>
#include <fstream>
#include <sstream>
#include <time.h> 

#define NUM_NODES 50
#define DATA_FILE "node_data.json"
typedef std::chrono::milliseconds milliseconds;

// Static initialization
double Manager::CurrentAlignment = 0.0;
double Manager::CurrentSeparation = 0.0;
double Manager::CurrentCohesion = 0.0;
Graph Manager::g = Graph(NUM_NODES, CurrentSeparation, CurrentCohesion, CurrentAlignment, time(NULL));

// Game loop Params
const int FPS = 30.0;
int tick = 0;
void Manager::gameLoop(){
	while(true){
		// Sleep this thread depending on desired FPS.
		// NOTE: 	Sleeping thread here may prove VERY inefficient.
		//			If performance issues happen, break into 2 threads
		//			or don't use threads at all.
		int time_to_sleep = 1000.0 / FPS;
		tick ++;
	   	std::this_thread::sleep_for(milliseconds(time_to_sleep));
		std::cout << "-------" << std::endl << "Tick:" << tick << std::endl;
		
		g.writeNodes(DATA_FILE);
		
		// Update all Managers once per tick
		Manager::update();
	}
}

void Manager::update(){
	printf( "Updating Manager...\n" );
	g.update(1000.0/FPS);

	//move node randomly
	//g.updateRandomMove(time(NULL));
}

void Manager::init(){
	printf( "Manager init...\n" );
	Manager::gameLoop();
}
