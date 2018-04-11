#ifndef __VEINS_MDModuleV2_H_
#define __VEINS_MDModuleV2_H_

#include <omnetpp.h>
#include <veins/modules/application/misbehaviorDetection/baseClasses/NodeMDMHistory.h>

#include "baseClasses/NodeTable.h"
#include "baseClasses/InterTest.h"
#include "baseClasses/BsmCheck.h"
#include "baseClasses/InterTest.h"
#include "supportClasses/MDMLib.h"
#include "JosephVeinsApp.h"
#include "veins/modules/obstacle/ObstacleControl.h"
#include "veins/modules/obstacle/Obstacle.h"
#include "veins/modules/application/ieee80211p/BaseWaveApplLayer.h"


#include "mdAuthority/MBReport.h"
#include "mdAuthority/MDAuthority.h"
using namespace Veins;
using namespace omnetpp;

class MDModuleV2 {
private:

    int myId;
    Coord myPosition;
    Coord myPositionConfidence;

    MDMLib mdmLib;

    double RangePlausibilityCheck(Coord, Coord, Coord, Coord);
    double PositionPlausibilityCheck(Coord, Coord, double, double);
    double SpeedPlausibilityCheck(double, double);
    double PositionConsistancyCheck(Coord curPosition, Coord curPositionConfidence,
            Coord oldPosition, Coord oldPositionConfidence, double time);
    double SpeedConsistancyCheck(double, double, double, double, double);
    double IntersectionCheck(Coord, Coord,Coord,Coord);
    InterTest MultipleIntersectionCheck(NodeTable detectedNodes, BasicSafetyMessage bsm);

    double PositionSpeedConsistancyCheck(Coord curPosition,
            Coord curPositionConfidence, Coord oldPosition,
            Coord oldPositionConfidence, double curSpeed, double curSpeedConfidence,
            double oldspeed, double oldSpeedConfidence, double time);



    double BeaconFrequencyCheck(double, double);
    double SuddenAppearenceCheck(Coord, Coord, Coord, Coord);

    void PrintBsmCheck(int senderId, BsmCheck bsmCheck);

    bool AggregateFactors(double curFactor, double factor0, double factor1);
    BsmCheck CheckNodeForReport(BasicSafetyMessage bsm, BsmCheck bsmCheck,
            NodeTable detectedNodes, double mbType);



    void SendReport(MBReport mbReport);


public:
    MDModuleV2(int myId, Coord myPosition, Coord myPositionConfidence);
    BsmCheck CheckBSM(BasicSafetyMessage bsm, NodeTable detectedNodes);
    void CheckNodesHistoryForReport(NodeTable*);

    void saveLine(std::string path, std::string serial, double density, double deltaT);
};

#endif