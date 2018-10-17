#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

struct Meeting {
    int id;
    int start;
    int finish;

    bool operator < (const Meeting& meeting) const {return (finish < meeting.finish);}
    bool operator > (const Meeting& meeting) const {return (finish > meeting.finish);}
};

void choose_meetings(vector<Meeting> & schedule){
    int last_selected_f_time = -1;
    sort(schedule.begin(), schedule.end());
    for(auto meeting : schedule){
        if(meeting.start > last_selected_f_time){ // greedy choice
            last_selected_f_time = meeting.finish;
            cout << meeting.id << " ";
        }
    }
    cout << endl;

}

int main(){

    int test_cases, num_meetings, s_time, f_time;

    cin >> test_cases;

    while(test_cases > 0){
        cin >> num_meetings;
        vector<Meeting> schedule(num_meetings, Meeting({-1,-1}));
        for (int i = 0; i < num_meetings; ++i) {
            cin >> s_time;
            schedule[i].id = i+1; 
            schedule[i].start = s_time;

        }
        for (int i = 0; i < num_meetings; ++i) {
            cin >> f_time;
            schedule[i].finish = f_time;
        }
        choose_meetings(schedule);
        schedule.clear();
        test_cases--;
    }
    return 0;
}