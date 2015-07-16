#!/bin/bash

# three scripts to always execute the most updated SquadPlanner executables 
qmake resources/squadplanner.pro
make
./squadplanner
