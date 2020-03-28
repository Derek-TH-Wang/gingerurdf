#include <ros/ros.h>
#include "sensor_msgs/JointState.h"
#include "gingerurdf/ArmMsgs.h"
#include "gingerurdf/BodyMsgs.h"
#include "gingerurdf/HandMsgs.h"
#include "gingerurdf/HeadMsgs.h"
#include "gingerurdf/joint_state.h"
#include <gingerurdf/SetZero.h>

sensor_msgs::JointState js_;
ros::Publisher  pub_;
ros::Publisher  pub2_;
ros::Subscriber sub_;
ros::ServiceServer ser_;
ros::Timer  timer_;

ros::Publisher mainbodyAnglePub;
ros::Publisher rightArmAnglePub;
ros::Publisher leftArmAnglePub;
ros::Subscriber rightArmPosSub;
ros::Subscriber leftArmPosSub;
ros::Subscriber trunkPosSub;

bool setZero(gingerurdf::SetZero::Request &req,gingerurdf::SetZero::Response &res){
    for(int i = 0 ; i < 49;i++){
        js_.position[i] = 0.0;
    }
    js_.header.stamp = ros::Time::now();
    pub2_.publish(js_);
    res.ret = 1;
    return true;
}

void Timer(const ros::TimerEvent& event){
    // ROS_DEBUG("GO INTO Timer");
    sensor_msgs::JointState js;
    gingerurdf::ArmMsgs lArmAngle, rArmAngle;
    gingerurdf::BodyMsgs bodyAngle;
    gingerurdf::HeadMsgs headAngle;

    bodyAngle.Knee = js_.position[0];
    bodyAngle.Back_Z = js_.position[1];
    bodyAngle.Back_X = js_.position[2];
    bodyAngle.Back_Y = js_.position[3];
    lArmAngle.Shoulder_X = js_.position[7];
    lArmAngle.Shoulder_Y = js_.position[8];
    lArmAngle.Elbow_Z = js_.position[9];
    lArmAngle.Elbow_X = js_.position[10];
    lArmAngle.Wrist_Z = js_.position[11];
    lArmAngle.Wrist_X = js_.position[12];
    lArmAngle.Wrist_Y = js_.position[13];
    rArmAngle.Shoulder_X = js_.position[14];
    rArmAngle.Shoulder_Y = js_.position[15];
    rArmAngle.Elbow_Z = js_.position[16];
    rArmAngle.Elbow_X = js_.position[17];
    rArmAngle.Wrist_Z = js_.position[18];
    rArmAngle.Wrist_X = js_.position[19];
    rArmAngle.Wrist_Y = js_.position[20];

    mainbodyAnglePub.publish(bodyAngle);
    rightArmAnglePub.publish(rArmAngle);
    leftArmAnglePub.publish(lArmAngle);

    js = js_;
    js.header.stamp = ros::Time::now();
    pub2_.publish(js);
    js.name.clear();
    js.position.clear();
    js.velocity.clear();
    js.effort.clear();
}

void jsCallback(const sensor_msgs::JointState &msg){
    ROS_DEBUG("cb");

    for(int i = 0; i < msg.name.size();i++){
        ROS_DEBUG("%d,  %f  %s",i, msg.position[i], msg.name[i].c_str());

        if(!strcmp("Knee",msg.name[i].c_str())){
            js_.position[0] = msg.position[i];
        }
        if(!strcmp("Back_Z",msg.name[i].c_str())){
            js_.position[1] = msg.position[i];
        }
        if(!strcmp("Back_X",msg.name[i].c_str())){
            js_.position[2] = msg.position[i];
        }
        if(!strcmp("Back_Y",msg.name[i].c_str())){
            js_.position[3] = msg.position[i];
        }
        if(!strcmp("Neck_Z",msg.name[i].c_str())){
            js_.position[4] = msg.position[i];
        }
        if(!strcmp("Neck_X",msg.name[i].c_str())){
            js_.position[5] = msg.position[i];
        }
        if(!strcmp("Head_Y",msg.name[i].c_str())){
            js_.position[6] = msg.position[i];
        }

        if(!strcmp("Left_Shoulder_X",msg.name[i].c_str())){
            js_.position[7] = msg.position[i];
        }
        if(!strcmp("Left_Shoulder_Y",msg.name[i].c_str())){
            js_.position[8] = msg.position[i];
        }
        if(!strcmp("Left_Elbow_Z",msg.name[i].c_str())){
            js_.position[9] = msg.position[i];
        }
        if(!strcmp("Left_Elbow_X",msg.name[i].c_str())){
            js_.position[10] = msg.position[i];
        }
        if(!strcmp("Left_Wrist_Z",msg.name[i].c_str())){
            js_.position[11] = msg.position[i];
        }
        if(!strcmp("Left_Wrist_Y",msg.name[i].c_str())){
            js_.position[12] = msg.position[i];
        }
        if(!strcmp("Left_Wrist_X",msg.name[i].c_str())){
            js_.position[13] = msg.position[i];
        }

        if(!strcmp("Right_Shoulder_X",msg.name[i].c_str())){
            js_.position[14] = msg.position[i];
        }
        if(!strcmp("Right_Shoulder_Y",msg.name[i].c_str())){
            js_.position[15] = msg.position[i];
        }
        if(!strcmp("Right_Elbow_Z",msg.name[i].c_str())){
            js_.position[16] = msg.position[i];
        }
        if(!strcmp("Right_Elbow_X",msg.name[i].c_str())){
            js_.position[17] = msg.position[i];
        }
        if(!strcmp("Right_Wrist_Z",msg.name[i].c_str())){
            js_.position[18] = msg.position[i];
        }
        if(!strcmp("Right_Wrist_Y",msg.name[i].c_str())){
            js_.position[19] = msg.position[i];
        }
        if(!strcmp("Right_Wrist_X",msg.name[i].c_str())){
            js_.position[20] = msg.position[i];
        }

        if(!strcmp("Left_1_1",msg.name[i].c_str())){
            js_.position[21] = msg.position[i];
        }
        if(!strcmp("Left_1_2",msg.name[i].c_str())){
            js_.position[22] = msg.position[i];
        }
        if(!strcmp("Left_2_1",msg.name[i].c_str())){
            js_.position[23] = msg.position[i];
        }
        if(!strcmp("Left_2_2",msg.name[i].c_str())){
            js_.position[24] = msg.position[i];
        }
        if(!strcmp("Left_2_3",msg.name[i].c_str())){
            js_.position[25] = msg.position[i];
        }
        if(!strcmp("Left_3_1",msg.name[i].c_str())){
            js_.position[26] = msg.position[i];
        }
        if(!strcmp("Left_3_2",msg.name[i].c_str())){
            js_.position[27] = msg.position[i];
        }
        if(!strcmp("Left_3_3",msg.name[i].c_str())){
            js_.position[28] = msg.position[i];
        }
        if(!strcmp("Left_4_1",msg.name[i].c_str())){
            js_.position[29] = msg.position[i];
        }
        if(!strcmp("Left_4_2",msg.name[i].c_str())){
            js_.position[30] = msg.position[i];
        }
        if(!strcmp("Left_4_3",msg.name[i].c_str())){
            js_.position[31] = msg.position[i];
        }
        if(!strcmp("Left_5_1",msg.name[i].c_str())){
            js_.position[32] = msg.position[i];
        }
        if(!strcmp("Left_5_2",msg.name[i].c_str())){
            js_.position[33] = msg.position[i];
        }
        if(!strcmp("Left_5_3",msg.name[i].c_str())){
            js_.position[34] = msg.position[i];
        }

        //right hand
        if(!strcmp("Right_1_1",msg.name[i].c_str())){
            js_.position[35] = msg.position[i];
        }
        if(!strcmp("Right_1_2",msg.name[i].c_str())){
            js_.position[36] = msg.position[i];
        }
        if(!strcmp("Right_2_1",msg.name[i].c_str())){
            js_.position[37] = msg.position[i];
        }
        if(!strcmp("Right_2_2",msg.name[i].c_str())){
            js_.position[38] = msg.position[i];
        }
        if(!strcmp("Right_2_3",msg.name[i].c_str())){
            js_.position[39] = msg.position[i];
        }
        if(!strcmp("Right_3_1",msg.name[i].c_str())){
            js_.position[40] = msg.position[i];
        }
        if(!strcmp("Right_3_2",msg.name[i].c_str())){
            js_.position[41] = msg.position[i];
        }
        if(!strcmp("Right_3_3",msg.name[i].c_str())){
            js_.position[42] = msg.position[i];
        }
        if(!strcmp("Right_4_1",msg.name[i].c_str())){
            js_.position[43] = msg.position[i];
        }
        if(!strcmp("Right_4_2",msg.name[i].c_str())){
            js_.position[44] = msg.position[i];
        }
        if(!strcmp("Right_4_3",msg.name[i].c_str())){
            js_.position[45] = msg.position[i];
        }
        if(!strcmp("Right_5_1",msg.name[i].c_str())){
            js_.position[46] = msg.position[i];
        }
        if(!strcmp("Right_5_2",msg.name[i].c_str())){
            js_.position[47] = msg.position[i];
        }
        if(!strcmp("Right_5_3",msg.name[i].c_str())){
            js_.position[48] = msg.position[i];
        }
    }
    js_.header.stamp = ros::Time::now();
    pub_.publish(js_);
}

void SubRightArmPos(const gingerurdf::ArmMsgs &msg) {
    js_.position[14] = msg.Shoulder_X;
    js_.position[15] = msg.Shoulder_Y;
    js_.position[16] = msg.Elbow_Z;
    js_.position[17] = msg.Elbow_X;
    js_.position[18] = msg.Wrist_Z;
    js_.position[19] = msg.Wrist_X;
    js_.position[20] = msg.Wrist_Y;
}

void SubLeftArmPos(const gingerurdf::ArmMsgs &msg) {
    ROS_DEBUG("sub left arm target position");
    js_.position[7] = msg.Shoulder_X;
    js_.position[8] = msg.Shoulder_Y;
    js_.position[9] = msg.Elbow_Z;
    js_.position[10] = msg.Elbow_X;
    js_.position[11] = msg.Wrist_Z;
    js_.position[12] = msg.Wrist_X;
    js_.position[13] = msg.Wrist_Y;
}

void SubTrunkPos(const gingerurdf::BodyMsgs &msg) {
    js_.position[0] = msg.Knee;
    js_.position[1] = msg.Back_Z;
    js_.position[2] = msg.Back_X;
    js_.position[3] = msg.Back_Y;
}

// void SubHeadPos(const gingerurdf::HeadMsgs &msg) {
//     js_.position[4] = msg.Neck_Z;
//     js_.position[5] = msg.Neck_X;
//     js_.position[6] = msg.Head;
// }

int main(int argc, char** argv){
    ros::init(argc, argv, "ginger_control");
    ros::console::set_logger_level(ROSCONSOLE_DEFAULT_NAME, ros::console::levels::Info);
    ros::NodeHandle nh_;
    sub_ = nh_.subscribe("/joint_states", 1, jsCallback);
    pub_ = nh_.advertise<sensor_msgs::JointState>("/joint_state_in", 10);
    pub2_ = nh_.advertise<sensor_msgs::JointState>("/ginger/joint_states", 1);
    ser_ = nh_.advertiseService("/setZeroPostion",setZero);

    mainbodyAnglePub =
      nh_.advertise<gingerurdf::BodyMsgs>("/MainBody/Position", 1);
    rightArmAnglePub =
      nh_.advertise<gingerurdf::ArmMsgs>("/RightArm/Position", 1);
    leftArmAnglePub =
      nh_.advertise<gingerurdf::ArmMsgs>("/LeftArm/Position", 1);

    rightArmPosSub =
      nh_.subscribe("/RightArm/TargetPosition", 1, SubRightArmPos);
    leftArmPosSub =
      nh_.subscribe("/LeftArm/TargetPosition", 1, SubLeftArmPos);
    trunkPosSub =
      nh_.subscribe("/MainBody/TargetPosition", 1, SubTrunkPos);
    // headPosSub =
    //   nh_.subscribe("/HeadBody/TargetPosition", 1, SubHeadPos);

    js_.name.resize(49);
    js_.position.resize(49);

    for(int i = 0; i < 49; i++){

        js_.name[i] = actor[i];
        js_.position[i] = 0;
    }

    ROS_DEBUG("go out cycle");
    timer_ = nh_.createTimer(ros::Duration(0.002), Timer);

    ros::spin();
    return  0;

}

