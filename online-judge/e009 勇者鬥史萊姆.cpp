#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;


class Slime {
public:
  // health points, defence points, attack points
  int hp, dp, ap;

  Slime(string type) {
    if (type == "Little_Slime") {
      hp = 100;
      dp = 10;
      ap = 10;
    } else if (type == "Big_Slime") {
      hp = 500;
      dp = 100;
      ap = 100;
    } else if (type == "Slime_King") {
      hp = 1000;
      dp = 300;
      ap = 300;
    }
  }
};

class Warrior {
public:
  // level, experience points, health points,
  // full health points, defence points, attack points
  int lv, xp, hp, fhp, dp, dp_gained, ap, ap_gained;

  Warrior() {
    lv = 1;
    xp = 0;
    hp = 80;
    dp = 9;
    ap = 11;    
  }

  void gain_xp(int xp) {
    while (xp >= next_level_xp()) {
      hp += lv * 10;
      fhp += lv * 10;

      gain_dp(lv * 5);
      gain_ap(lv * 5);

      lv++;
    }
  }

  void gain_hp(int value) {
    hp += value;
    if (hp > fhp)
      hp = fhp;
  }

  void gain_dp(int value) {
    dp += value;
    dp_gained = value;
  }

  void gain_ap(int value) {
    ap += value;
    ap_gained = value;
  }

  int next_level_xp() {
    // 1^3 + 2^3 + ... + lv^3
    return pow(lv * (lv+1) / 2, 2);
  }
};

int main() {
  Warrior bwoyau;
  string thing("");
  bool succeed = false;

  while (cin >> thing) {
    cin.ignore(1, '#');

    if (thing == "Princess") {
      succeed = true;
      break;
    } else if (thing.find("Slime") != string::npos) {
      // if there is a Slime
      Slime blue(thing);

      // bwoyau attack
      blue.hp -= bwoyau.ap - blue.dp;
      bwoyau.gain_xp((bwoyau.ap - blue.dp) / 10);
      printf("Lv:%d(%d/%d) HP:%d/%d DP:%d(+%d) AP:%d(+%d)\n",
        bwoyau.lv,
        bwoyau.xp, bwoyau.next_level_xp(),
        bwoyau.hp, bwoyau.fhp,
        bwoyau.dp, bwoyau.dp_gained,
        bwoyau.ap, bwoyau.ap_gained);

      // blue attack
      bwoyau.hp -= blue.ap - bwoyau.dp;
      if (bwoyau.hp <= 0) {
        succeed = false;
        break;
      }
    } else if (thing == "bread") {
      bwoyau.gain_hp(5);
    } else if (thing == "beef") {
      bwoyau.gain_hp(50);
    } else if (thing == "meal") {
      bwoyau.gain_hp(100);
    } else if (thing == "drug") {
      bwoyau.gain_hp(300);
    } else if (thing == "shoes") {
      bwoyau.gain_dp(5);
    } else if (thing == "hat") {
      bwoyau.gain_dp(50);
    } else if (thing == "clothes") {
      bwoyau.gain_dp(100);
    } else if (thing == "armor") {
      bwoyau.gain_dp(300);
    } else if (thing == "knife") {
      bwoyau.gain_ap(5);
    } else if (thing == "sword") {
      bwoyau.gain_ap(50);
    } else if (thing == "hammer") {
      bwoyau.gain_ap(100);
    } else if (thing == "gun") {
      bwoyau.gain_ap(300);
    }
    cout << "@@@\n";
  }

  if (succeed)
    cout << "You Win!\n";
  else
    cout << "You Lose!\n";

  return 0;
}