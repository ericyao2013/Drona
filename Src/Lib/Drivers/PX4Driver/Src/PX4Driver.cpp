#include "PX4Driver.h"

PX4API::PX4API(int simulatorPort){

    this->px4com = new PX4Communicator(simulatorPort);
    this->systemId = 255;
    this->autopilotId = 1;
    this->companionId = 1;

    this->armed = false;
    this->autopilot = false;

}

bool PX4API::SendFakePosition()
{
    mavlink_att_pos_mocap_t mocap_position = {0};
    mocap_position.time_usec = 0;
    mocap_position.x = 1;
    mocap_position.y = 1;
    mocap_position.z = 1;
    mocap_position.q[0] = 1;

    mavlink_message_t msg;
    mavlink_msg_att_pos_mocap_encode(this->systemId + 1, this->autopilotId + 1, &msg, &mocap_position);

    this->px4com->WriteMessage(msg);

    LOG("PX4API::Mocap Position");
    return true;
}

bool PX4API::Arm(){

    if(this->armed){
        LOG("PX4API::Drone already armed");
        return false;
    }

    mavlink_command_long_t cmd = {0};
    cmd.confirmation = 1;
    cmd.target_system = this->companionId;
    cmd.target_component = this->autopilotId;

    cmd.command = MAV_CMD_COMPONENT_ARM_DISARM;
    cmd.param1 = 1;

    mavlink_message_t msg;
    mavlink_msg_command_long_encode(this->systemId, this->autopilotId, &msg, &cmd);

    this->px4com->WriteMessage(msg);
    this->armed = true;

    LOG("PX4API::Drone Armed");
    return true;

}


void PX4API::TakeoffGlobal(float alt){

    mavlink_command_long_t cmd = {0};
    cmd.confirmation = 1;
    cmd.target_system = this->companionId;
    cmd.target_component = this->autopilotId;

    cmd.command = MAV_CMD_NAV_TAKEOFF;
    cmd.param4 = NAN;
    cmd.param5 = NAN;
    cmd.param6 = NAN;
    cmd.param7 = alt;

    mavlink_message_t msg;
    mavlink_msg_command_long_encode(this->systemId, this->autopilotId, &msg, &cmd);

    this->px4com->WriteMessage(msg);

    // Print log
    char buff[100];
    sprintf(buff,"PX4API::Takeoff altitude %f", alt);
    LOG(buff);
}


bool PX4API::StartAutopilot(float x, float y, float z){

    if(this->autopilot){
        LOG("PX4API::StartAutopilot autopilot already on");
        return false;
    }

    this->SetTargetLocalPosition(x,y,z);
    this->px4com->WriteSetpoint();

    if( !this->ToggleOffBoard(true) ){
        return false;
    }

    this->autopilot = true;

    LOG("PX4API::StartAutopilot Autopilot on");
    this->px4com->StartAutoPilot();

    return true;
}

bool PX4API::StopAutopilot(){

    if(!this->autopilot){
        LOG("PX4API::StartAutopilot autopilot already off");
        return false;
    }

    this->px4com->StopAutoPilot();
    this->ToggleOffBoard(false);
    this->autopilot = false;

    LOG("PX4API::StopAutopilot Autopilot off");
    return true;
}


bool PX4API::ToggleOffBoard(bool on){

    mavlink_command_long_t cmd = {0};
    cmd.confirmation = 1;
    cmd.target_system = this->companionId;
    cmd.target_component = this->autopilotId;

    cmd.param1 = (float) on;
    cmd.command = MAV_CMD_NAV_GUIDED_ENABLE;

    mavlink_message_t msg;
    mavlink_msg_command_long_encode(this->systemId, this->autopilotId, &msg, &cmd);

    int len = this->px4com->WriteMessage(msg);

    if( len > 0 ){
        // Print log
        char buff[100];
        strcpy(buff,"PX4API::ToggleOffBoard Offboard control ");
        if(on){
            strcat(buff,"on");
        }else{
            strcat(buff,"off");
        }
        //LOG(buff);
        return true;
    }

    ERROR("PX4API::ToggleOffBoard Couldn't toggle offboard control");
    return false;
}

void PX4API::MotionPrimitive(char motion, int steps){

//    char buff[100];
//    strcpy(buff,"PX4API::MotionPrimitive received");

//    // Retrieve current coords
//    mavlink_local_position_ned_t act_pos = ROBOTSTATE->GetLocalPosition();

//    // Get grid index
//    coord c = {act_pos.x,act_pos.y,-act_pos.z};
//    int cur_idx = this->map->Coord2Idx(c);

//    // Get neighbor grid coordinates
//    c = this->map->CentroidNeigh(cur_idx,motion,steps);

    int a, b, c;

    this->SetTargetLocalPosition(a,b,c);

    while(!(this->CloseTo(a,b,c,0.5))){}

}


// GoTo a workspace coordinate with precitions eps
void PX4API::GoTo(WS_Coord goal, double eps){
    this->SetTargetLocalPosition(goal.x,goal.y,goal.z);
    while(!(this->CloseTo(goal.x,goal.y,goal.z,eps))){}
}


void PX4API::GoTo(float x, float y, float z, double eps){
    this->SetTargetLocalPosition(x,y,z);
    std::time_t start = std::time(NULL);


    while(!(this->CloseTo(x,y,z,eps))){ if(std::difftime(std::time(NULL), start)> 7) break; }
}


// Follow trajectory
void PX4API::FollowTrajectory(vector< WS_Coord > traj, float eps){

    if( traj.size() <= 0 ){
        ERROR("FollowTrajectory: provide at least one way point");
    }

    for (auto wp = traj.begin(); wp != traj.end();  ++wp ){
        this->GoTo(*wp,eps);
    }
}



/*

void PX4API::Loiter(vector< float > center, float radius, int rounds, float eps, float loitStep){

    if( center.size() != 3 ){
        ERROR("Loiter: center must be 3d array");
    }

    char buf[100];
    sprintf(buf, "Loiter: center %f,%f,%f, radius %f", center[0],center[1],center[2],radius);
    LOG(buf);

    vector< vector<float> > waypoints;

    for(double angle=0; angle <= 2*M_PI; angle += loitStep){

        vector<float> waypoint;
        waypoint.push_back(center[0] + radius*cos(angle));
        waypoint.push_back(center[1] + radius*sin(angle));
        waypoint.push_back(center[2]);

        waypoints.push_back(waypoint);
    }

    this->FollowTrajectory(waypoints, rounds, eps);
}

void PX4API::Square(vector< float > corner, float edge, int rounds, float eps){

    if( corner.size() != 3 ){
        ERROR("Square: corner must be 3d array");
    }

    char buf[100];
    sprintf(buf, "Square: start %f,%f,%f, edge %f", corner[0],corner[1],corner[2],edge);
    LOG(buf);

    vector<float> loRight = corner;
    loRight[0] = corner[0] + edge;
    vector<float> upRight = loRight;
    upRight[1] = loRight[1] + edge;
    vector<float> upLeft = corner;
    upLeft[1] = corner[1] + edge;

    vector< vector<float> > waypoints;
    waypoints.push_back(corner);
    waypoints.push_back(loRight);
    waypoints.push_back(upRight);
    waypoints.push_back(upLeft);
    waypoints.push_back(corner);

    this->FollowTrajectory(waypoints,rounds,eps);

}

*/

// Check if drone is eps-close to (x,y,x)
bool PX4API::CloseTo(float x, float y, float z, float eps){

    mavlink_local_position_ned_t act_pos = ROBOTSTATE->GetLocalPosition();

    float dx = x - act_pos.x;
    float dy = y - act_pos.y;
    float dz = z - act_pos.z;
    float dist = sqrt( pow(dx,2) + pow(dy,2) + pow(dz,2) );

    return (dist < eps);
}



