class point
{
  int _x;
  int _y;
  int x_;
  int y_;
public:
  point(int x = 0, int y = 0);
  bool operator==(const point& other);
  bool operator!=(const point& other);
  bool operator<(const point& other);
};