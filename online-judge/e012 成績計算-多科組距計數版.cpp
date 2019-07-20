#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> group(vector<int> scores) {
  // 90-100, 80-90, 70-80 ...
  vector<int> groups;

  vector<int>::iterator score = scores.begin();
  for (int base=90; base>=0; base-=10) {
    int count = 0;
    while (*score >= base and score != scores.end()) {
      count++;
      score++;
    }
    groups.push_back(count);
  }

  return groups;
}

int main() {
  int student_count, subject_count;
  vector< vector<int> > grades;

  cin >> student_count >> subject_count;
  grades.resize(subject_count, vector<int>(student_count));
  for (int i=0; i<student_count; i++) {
    for (int j=0; j<subject_count; j++) {
      cin >> grades[j][i];
    }
  }

  for (vector< vector<int> >::iterator subject = grades.begin();
       subject != grades.end();
       subject++) {
    sort(subject->begin(), subject->end(), greater<int>()); // descending
    vector<int> groups = group(subject);
    for (vector<int>::iterator _group = groups.begin();
         _group != groups.end();
         _group++) {
      cout << *_group << ' ';
    }
    cout << endl;
  }

  return 0;
}

/* testing data:
38 10

95 26 8 41 65 76 90 31 81 99
81 1 60 50 33 63 94 16 31 40
49 60 95 24 91 34 3 46 40 84
6 24 50 77 77 86 5 88 41 85
51 55 44 37 17 45 27 63 41 10
18 16 62 4 95 72 28 58 14 28
62 15 8 22 13 43 44 86 99 22
73 52 48 97 92 51 30 48 94 25
87 38 64 37 100 36 28 86 47 93
49 54 47 33 6 51 58 30 85 37
40 44 90 92 99 89 23 93 89 62
72 96 86 65 33 45 67 38 57 97
30 63 16 89 98 55 91 38 55 12
54 35 0 55 92 96 20 27 16 68
38 1 30 42 6 62 38 15 85 63
37 16 77 52 75 22 62 49 3 5
50 55 36 60 48 70 78 6 69 85
54 42 41 50 46 37 20 47 97 18
87 85 37 3 42 49 32 64 45 39
16 21 30 70 67 48 72 25 88 45
24 19 10 93 2 41 82 77 26 82
60 0 54 63 97 10 41 43 85 62
25 30 56 22 60 72 71 49 100 100
60 80 58 40 16 25 46 64 42 63
58 91 40 17 80 91 23 10 35 71
32 64 24 21 88 4 29 48 91 72
93 92 72 16 9 68 30 45 65 90
39 76 71 41 71 84 63 20 51 40
68 73 55 47 23 11 45 1 18 6
19 50 41 16 57 51 69 17 67 29
27 24 75 30 74 64 1 99 59 95
70 1 3 46 93 73 62 91 65 68
5 27 97 64 66 35 75 4 48 60
89 68 43 89 86 4 85 77 19 48
93 28 7 57 60 81 76 18 96 78
75 8 17 38 9 88 29 25 9 13
40 57 95 64 55 85 24 85 12 58
55 0 82 1 50 37 64 69 38 13
*/