/*******************************************************************************
* @author  Joseph Kamel 
* @email   josephekamel@gmail.com
* @date    11/04/2018
* @version 1.0
*
* SCA (Secure Cooperative Autonomous systems)
* Copyright (c) 2013, 2018 Institut de Recherche Technologique SystemX
* All rights reserved.
*******************************************************************************/

#ifndef __VEINS_AppPrintable_H_
#define __VEINS_AppPrintable_H_

#include <stdio.h>
#include <stdlib.h>     /* atof */
#include <boost/algorithm/string.hpp>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

#include "../enumTypes/MbTypes.h"
#include "../enumTypes/MdChecksTypes.h"

using namespace std;
using namespace boost;

class AppPrintable {

private:
    char name[32];

    double flagsRangePlausibility_1 = 0;
    double flagsPositionPlausibility_1 = 0;
    double flagsSpeedPlausibility_1 = 0;
    double flagsPositionConsistancy_1 = 0;
    double flagsPositionSpeedConsistancy_1 = 0;
    double flagsSpeedConsistancy_1 = 0;
    double flagsBeaconFrequency_1 = 0;
    double flagsIntersection_1 = 0;
    double flagsSuddenAppearence_1 = 0;
    double flagsPositionHeadingConsistancy_1 = 0;

    double flagsRangePlausibility_2 = 0;
    double flagsPositionPlausibility_2 = 0;
    double flagsSpeedPlausibility_2 = 0;
    double flagsPositionConsistancy_2 = 0;
    double flagsPositionSpeedConsistancy_2 = 0;
    double flagsSpeedConsistancy_2 = 0;
    double flagsBeaconFrequency_2 = 0;
    double flagsIntersection_2 = 0;
    double flagsSuddenAppearence_2 = 0;
    double flagsPositionHeadingConsistancy_2 = 0;

    double cumulFlags_1 = 0;
    double cumulFlags_2 = 0;

    double allTests_1 = 0;
    double allTests_2 = 0;

public:
    AppPrintable();
    AppPrintable(const char *);

    void setName(const char *);

    void incAll(mbTypes::Mbs mbType);
    void incCumulFlags(mbTypes::Mbs mbType);
    void incFlags(mdChecksTypes::Checks check, mbTypes::Mbs mbType);
    void resetAll();
    void getPrintable(char* outStr, double density,double deltaT);

    void writeFile(std::string path, char* printStr, bool init);
};

#endif