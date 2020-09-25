#ifndef QNODE_H
#define QNODE_H

#ifndef Q_MOC_RUN
#include <ros/ros.h>
#include <std_msgs/String.h>
#endif
#include <string>
#include <QThread>
#include <QStringListModel>

class QNode : public QThread {
    Q_OBJECT

public:
    QNode(int argc, char** argv);
    virtual ~QNode();
    bool init();
    void run();
    ros::Publisher pub;

    // callback
    void topicCallback(const std_msgs::String::ConstPtr& msg);

    // Variables:
    std::string sub_message = "";
    std::string pub_message = "";

    // Signals
Q_SIGNALS:
    void msgSubscribed();


private:
    int init_argc;
    char** init_argv;
    ros::Subscriber subs;



};

#endif // QNODE_H
