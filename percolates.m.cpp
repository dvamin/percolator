#include <iostream>
using namespace std;

class UnionFind {
  int *arr;
  int *size;
  size_t sz;

  int root(int index)
  {
    while(arr[index] != index) {
      index = arr[index];
    }
    return index;
  }

  void dump()
  {
    cout << "Arr: ";
    for (size_t i = 0; i < sz; ++i) {
      cout << " " << arr[i];
    }
    cout << endl;
    cout << "Size: ";
    for (size_t i = 0; i < sz; ++i) {
      cout << " " << size[i];
    }
    cout << endl;
  }

 public:
  UnionFind(size_t x) : sz(x)
  {
    arr = (int *)malloc(sizeof(int)*sz);
    size = (int *)malloc(sizeof(int)*sz);
    for (size_t i = 0; i < sz; ++i) {
      arr[i] = i;
      size[i] = 1;
    }
  }

  ~UnionFind()
  {
    delete arr;
    delete size;
  }

  void Union(int i, int j)
  {
    if (Find(i,j)) {
      return;
    }
    i = root(i); j = root(j);
    if (size[i] > size[j]) {
      arr[j] = i;
    }
    else if (size[j] > size[i]) {
      arr[i] = j;
    }
    else {
      arr[i] = j;
      size[j]++;
    }
  }

  bool Find(int i, int j)
  {
    return root(i) == root(j);
  }
};

static bool percolates(bool *grid, size_t size) {
  size_t total = size*size + 2;
  UnionFind uf(total);
  size_t i = 0, counter = 1;
  for (i = 0; i < size; ++i) {
    for (size_t j = 0; j < size; ++j) {
      if (grid[i*size+j]) {
        if (i == 0) {
          uf.Union(0, counter);
        }
        if (i == size-1) {
          uf.Union(total - 1, counter);
        }
        if (i != 0 && grid[(i-1)*size+j]) {
          uf.Union(counter, counter - size);
        }
        if (i != size-1 && grid[(i+1)*size+j]) {
          uf.Union(counter, counter + size);
        }
        if (j != 0 && grid[i*size+j-1]) {
          uf.Union(counter, counter - 1);
        }
        if (j != size-1 && grid[i*size+j+1]) {
          uf.Union(counter, counter + 1);
        }
      }
      counter++;
    }
  }
  return uf.Find(0, total-1);
}

int main(int argc, const char *argv[])
{
  if (argc < 2) {
    return -1;
  }
  
  size_t size = (size_t)atoi(argv[1]);
  bool *grid = (bool *)malloc(size*size*sizeof(bool));
  for (size_t i = 0; i < size*size; ++i) {
    grid[i] = true;
  }

  for (size_t index = 2; index < (size_t)argc; ++index) {
    int id = atoi(argv[index]);
    if (id < 0 || id >= (int)(size*size)) {
        return -2;
    }
    grid[id] = false;
  }

  if (percolates(grid, size)) {
    cout << "Percolates" << endl;
  }
  else {
    cout << "Does not percolate" << endl;
  }

  delete grid;
  return 0;
}
