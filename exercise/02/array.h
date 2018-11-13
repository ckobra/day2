// do not use standard container as member or base class
class array
{
	double* p;
	int n;
public:
  array();
  array(int size, double value);
  array(const array& other);
  array(array&& other);
  ~array();
  array& operator=(const array& other);
  int size() const;
  double at(int index) const;
};