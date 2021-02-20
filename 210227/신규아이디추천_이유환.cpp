#include <string>
#include <vector>

using namespace std;

string solution(string new_id) {

    if (new_id == "") new_id = "a";

    for (int i = 0; i < new_id.length(); i++) {
        if (65 <= new_id[i] && new_id[i] <= 90) {
            new_id[i] += 32;
        }

        if ((33 <= new_id[i] && new_id[i] <= 64) || (91 <= new_id[i] && new_id[i] <= 96) || (123 <= new_id[i] && new_id[i] <= 126)) {
            if (48 > new_id[i] || new_id[i] > 57) {
                if (new_id[i] != '-' && new_id[i] != '_' && new_id[i] != '.') {
                    new_id.erase(i, 1);
                    i--;
                }
            }
        }

        if (i > 0 && new_id[i] == '.' && new_id[i - 1] == '.') {
            new_id.erase(i - 1, 1);
            i--;
        }       
    }

    if (new_id.length() > 0 && new_id[0] == '.') new_id.erase(0, 1);
    else if (new_id.length() > 0 && new_id[new_id.length() - 1] == '.') new_id.erase(new_id.length() - 1, 1);

    if (new_id.length() > 15) new_id.erase(15, new_id.length() - 15);

    if (new_id.length() > 0 && new_id[0] == '.') new_id.erase(0, 1);
    else if (new_id.length() > 0 && new_id[new_id.length() - 1] == '.') new_id.erase(new_id.length() - 1, 1);

    if (new_id == "") new_id = "a";

    if (new_id.length() <= 2) {
        while (new_id.length() < 3) {
            new_id += new_id[new_id.length() - 1];
        }
    }

    return new_id;
}
