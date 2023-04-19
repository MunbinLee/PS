#include <iostream>
#include <random>

using namespace std;

struct Cube {
  string name;
  int price;
  int prop;
  int pity;

  Cube(string name, int price, int prop, int pity) : name(std::move(name)), price(price), prop(prop), pity(pity) {}
};

random_device rd;
mt19937 gen(rd());
uniform_int_distribution<int> uid(1, 1000000);
const int trial = 1000000; // 시행 횟수
const int cost = 1250000; // 감정 비용

double getExp(int prob, int pity) {
  double sumCube = 0;
  for (int i = 0; i < trial; i++) {
    int cube = 1; // 큐브 돌린 횟수
    for (; cube < pity; cube++) {
      if (uid(gen) <= prob) break;
    }
    sumCube += cube;
  }
  return sumCube / trial;
}

int main() {
  Cube *cubes[3];
  cubes[0] = new Cube("장인의 큐브", 4704000 + cost, 11858, INT32_MAX);
  cubes[1] = new Cube("레드 큐브", 12500000 + cost, 18000, 84);
  cubes[2] = new Cube("블랙 큐브", 22600000 + cost, 35000, 43);

  for (Cube *cube: cubes) {
    double exp = getExp(cube->prop, cube->pity);
    printf("%s 기댓값 : %.2f개, %.3f억 메소\n", cube->name.c_str(), exp, exp * cube->price / 100000000);
  }
  return 0;
}