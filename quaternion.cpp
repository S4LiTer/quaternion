#include "quaternion.h"


quaternion::quaternion(float X, float Y, float Z) {
    
    addEuler(X, Y, Z);
}

void quaternion::RewriteQuaternion(float X, float Y, float Z) {
    R = 1;
    i = 0;
    j = 0;
    k = 0;

    addEuler(X, Y, Z);
}

void quaternion::addEuler(float X, float Y, float Z) {
    float *q = euler2quaternion(X, Y, Z);

    
    float new_R = q[0]*R - q[1]*i - q[2]*j - q[3]*k;
    float new_i = q[1]*R + q[0]*i + q[3]*j - q[2]*k;
    float new_j = q[2]*R - q[3]*i + q[0]*j + q[1]*k;
    float new_k = q[3]*R + q[2]*i - q[1]*j + q[0]*k;
    

    R = new_R;
    i = new_i;
    j = new_j;
    k = new_k;

    delete[] q;
}


float* quaternion::euler2quaternion(float X, float Y, float Z) {
    float len = vectorLength(X, Y, Z);

    float *_q = new float[4]{1, 0, 0, 0};

    if(len == 0) 
        return _q;

    _q[0] = cos(len * 0.5f);
    _q[1] = (X/len) * sin(len * 0.5);
    _q[2] = (Y/len) * sin(len * 0.5);
    _q[3] = (Z/len) * sin(len * 0.5);

    return _q;
}

float quaternion::vectorLength(float X, float Y, float Z) {
    float len = pow(X, 2) + pow(Y, 2) + pow(Z, 2);
    len = sqrt(len);

    return len;
}

float* quaternion::GetEuler() {
    float *angles = new float[3];

    angles[0] = atan2f( 2*(R*i+j*k), 1 - 2*( pow(i, 2) + pow(j, 2) ));
    angles[1] = (-M_PI/2) + 2 * atan2f( sqrt(1+2*(R*j-i*k)) , sqrt(1-2*(R*j - i*k)));
    angles[2] = atan2f( 2*(R*k+i*j), 1 - 2*( pow(j, 2) + pow(k, 2) ));

    return angles;
}

