#ifndef QUATERNION
#define QUATERNION

#include <math.h>
#include <iostream>



using namespace std;

class quaternion {
    public:
        double R = 1;
        double i = 0;
        double j = 0;
        double k = 0;

        quaternion(float X, float Y, float Z);

        void addEuler(float X, float Y, float Z);
        void RewriteQuaternion(float X, float Y, float Z);
        float* GetEuler();
    private:

        float* euler2quaternion(float X, float Y, float Z);
        float vectorLength(float X, float Y, float Z);
};


#endif