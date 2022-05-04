#include <vector>

using namespace std;

template <class T>
class QuickFind {
    public:
        QuickFind(vector <T> & V);
        ~QuickFind();
        int _Operate();
    private:
        vector <T> TrackRoot;
};

