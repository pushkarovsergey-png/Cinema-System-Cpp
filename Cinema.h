#include "NetUtils.h"
#include <string>
#include <map>
#include <mutex>
class Cinema{
    private:
    std::map<int, bool> seats;
    std::mutex cinemamtx;
    public:
    Cinema(){
        for (int i = 0; i < 10; i++){
            seats[i] = false;
        }
    }
    std::string getHallStatus(){
        std::lock_guard<std::mutex> lock(cinemamtx);
        std::string answer = "";
        for(int i = 0; i < 10; i++){
            if(seats[i] == false)
                answer += " [" + std::to_string(i) + "]";
            else{
                answer += " [X]";
            }
        }
        return answer;
    }
    bool bookSeat(int id){
        std::lock_guard<std::mutex> lock(cinemamtx);
        if(seats.count(id) > 0 && seats[id] == false){
            seats[id] = true;
            return true;
        }
        else{
            return false;
        }
    }
};