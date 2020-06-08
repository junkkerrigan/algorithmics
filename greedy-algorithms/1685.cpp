#include <iostream>
#include <list>

int main()
{
  struct Coord
  {
    int32_t X, Y;
  };
  std::list<std::list<Coord>> ll;
  short n;
  Coord buff;

  std::cin >> n;
  for (int i(0); i < n; ++i)
  {
    std::cin >> buff.X >> buff.Y;
    std::list<Coord> l;
    l.push_back(buff);

    for (auto it1(ll.begin()); it1 != ll.end();)
    {
      bool b(false);
      for (auto it2(it1->begin()); it2 != it1->end(); ++it2)
      {
        if ((buff.X - it2->X) * (buff.X - it2->X) + (buff.Y - it2->Y) * (buff.Y - it2->Y) < 4)
        {
          l.splice(l.end(), *it1);
          it1 = ll.erase(it1);
          b = true;
          break;
        }
      }
      if (!b)
        ++it1;
    }
    ll.push_back(std::move(l));
  }

  std::cout << ll.size();

  return 0;
}