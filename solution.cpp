#include "solution.h"
#include "util.h"
#include <map>
#include <algorithm> //lower_bound
#include <string>
#include <queue>
#include <sstream>
#include <functional>
#include <math.h>

#include "Interval.h"
using namespace sol253;
using namespace std;

/*takeaways
  - you take a room when you see a strat time and release
    one an end time
  - record the max number of rooms taken during the process
*/

int Solution::minMeetingRooms(vector<vector<int>> &intervals)
{
  /* order by time in ascending order */
  auto m = map<int, int>();
  auto maxRooms = 0, roomsUsed = 0;
  for (auto i : intervals)
    /* take a room; release a room */
    m[i[0]]++, m[i[1]]--;

  for (auto &[_, count] : m)
    /* record max rooms needed  */
    roomsUsed += count, maxRooms = max(maxRooms, roomsUsed);

  return maxRooms;
}