#include<bits/stdc++.h>
using namespace std;

class Subscriber{
    public : string subscriberId;
    public : Subscriber(string id){
        subscriberId = id;
    }
    public : void receiveNotification(string videoName, string channelName){
        printf("Hi %s a new video has been uploaded on %s's channel titled '%s'\n", 
        subscriberId.c_str(), channelName.c_str(), videoName.c_str());
    }
};

class publisher{
    public : string channelName;
    public : unordered_set<Subscriber*> subscribers;
    //can not use unoredered_set<Subscriber> because there is no hash automatically available
    //for a class in C++, same is true for unordered_map.
    public : publisher(string channelName){
        this->channelName = channelName;
    }
    public : void subscribe(Subscriber* subscriber){
        subscribers.insert(subscriber);
    }
    public : void unSubscribe(Subscriber* subscriber){
        subscribers.erase(subscriber);
    }
    public : void notifyUpdate(string videoName){
        for(Subscriber* subscriber : subscribers){
            subscriber->receiveNotification(videoName, this->channelName);
        }
        printf("Horray! Notifications sent to all subscribers\n");
    }
};

int main()
{
    publisher channel = publisher("Mr.Beast");
    Subscriber* sub1 = new Subscriber("1");
    Subscriber* sub2 = new Subscriber("2");
    Subscriber* sub3 = new Subscriber("3");
    channel.subscribe(sub1);
    channel.subscribe(sub2);
    channel.notifyUpdate("How I spent $1,000,000 on a boat");
    channel.subscribe(sub3);
    channel.notifyUpdate("I spent a night in worlds most expensive restaurant");
}
