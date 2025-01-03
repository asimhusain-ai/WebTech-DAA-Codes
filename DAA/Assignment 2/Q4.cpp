#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Activity {
    int start, end;
};
bool compare(Activity a, Activity b) {
    return a.end < b.end;
}
void activitySelection(vector<Activity>& activities) {
    sort(activities.begin(), activities.end(), compare);
    int lastEndTime = 0;
    cout << "Selected activities: ";
    for (const auto& activity : activities) {
        if (activity.start >= lastEndTime) {
            cout << "(" << activity.start << ", " << activity.end << ") ";
            lastEndTime = activity.end;
        }
    }
    cout << endl;
}
int main() {
    vector<Activity> activities = {{1, 2}, {3, 4}, {0, 6}, {5, 7}, {8, 9}, {5, 9}};
    activitySelection(activities);
    return 0;
}