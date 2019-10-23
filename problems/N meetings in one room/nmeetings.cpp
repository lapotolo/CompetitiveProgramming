#include <iostream>
#include <vector>
#include <algorithm>

struct Meeting {
  int id, start, finish;
  bool operator < (const Meeting& meeting) const {return (finish < meeting.finish);}
};

void choose_meetings(std::vector<Meeting> & schedule){
  int last_selected_f_time = -1;
  sort(schedule.begin(), schedule.end()); // SORT BY FINISHING TIME
  for(auto meeting : schedule){
    if(meeting.start > last_selected_f_time){ // greedy choice
      last_selected_f_time = meeting.finish;
      std::cout << meeting.id << " ";
    }
  }
  std::cout << std::endl;
}

int main(){
  
  int test_cases, num_meetings, s_time, f_time;
  
  std::cin >> test_cases;
  
  while(test_cases > 0){
    std::cin >> num_meetings;
    std::vector<Meeting> schedule(num_meetings, Meeting({-1,-1}));
    for (int i = 0; i < num_meetings; ++i) {
      std::cin >> s_time;
      schedule[i].id = i+1; 
      schedule[i].start = s_time;
    }
    for (int i = 0; i < num_meetings; ++i) {
      std::cin >> f_time;
      schedule[i].finish = f_time;
    }
    choose_meetings(schedule);
    schedule.clear();
    test_cases--;
  }
  return 0;
}
