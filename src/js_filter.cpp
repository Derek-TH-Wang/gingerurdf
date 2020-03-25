#include <ros/ros.h>
#include "sensor_msgs/JointState.h"
#include "gingerurdf/joint_state.h"
#include <gingerurdf/SetZero.h>

sensor_msgs::JointState js_;
//sensor_msgs::JointState js2_;
ros::Publisher  pub_;
ros::Publisher  pub2_;
ros::Subscriber sub_;
ros::ServiceServer ser_;
ros::Timer  timer_;

bool setZero(gingerurdf::SetZero::Request &req,gingerurdf::SetZero::Response &res){
                        //sensor_msgs::JointState js;
                        for(int i = 0 ; i < 49;i++){
                           // js.name.push_back(actor[i]);
                            js_.position[i] = 0.0;
                        }
                        js_.header.stamp = ros::Time::now();
                        pub2_.publish(js_);
                        res.ret = 1;
                        return true;
                    }
void jspub(const ros::TimerEvent& event){
        //ROS_INFO("timer");
        sensor_msgs::JointState js;
        js = js_;
        // std::cout << "test js_.name size " << js.name.size() << "test js_.name size " << js.position.size() <<  std::endl;
        js.header.stamp = ros::Time::now();
        pub2_.publish(js);
        js.name.clear();
        js.position.clear();
        js.velocity.clear();
        js.effort.clear();
    }
void jsCallback(const sensor_msgs::JointState &msg){
        ROS_INFO("cb");

        for(int i = 0; i < msg.name.size();i++){
            ROS_INFO("%d,  %f  %s",i, msg.position[i], msg.name[i].c_str());

        if(!strcmp("Knee_X",msg.name[i].c_str())){
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


int main(int argc, char** argv){
    ros::init(argc, argv, "js_filter");
    ros::NodeHandle nh_;
    sub_ = nh_.subscribe("/joint_states",1,jsCallback);
    pub_ = nh_.advertise<sensor_msgs::JointState>("/joint_state_in",10);
    pub2_ = nh_.advertise<sensor_msgs::JointState>("/ginger/joint_states",1);
    ser_ = nh_.advertiseService("/setZeroPostion",setZero);

        js_.name.resize(49);
        js_.position.resize(49);

        for(int i = 0; i < 49; i++){
            // std::cout << actor[i]  << std::endl;
            // js_.name.push_back(actor[i]);
            // js_.position.push_back(0);

            js_.name[i] = actor[i];
            js_.position[i] = 0;

            // std::cout << "___  " << js_.name[i] << std::endl;
            // std::cout << "___  " << js_.position[i] << std::endl;
        }
        //js_.header.stamp = ros::Time::now();

        //pub_.publish(js_);

        ROS_INFO("go out cycle");
        timer_ = nh_.createTimer(ros::Duration(0.03),jspub);

        ros::spin();
        return  0;

}

